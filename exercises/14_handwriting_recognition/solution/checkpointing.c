#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

#include "hdf5.h"
#include "include/neural_network.h"

void write_to_hdf5(neural_network_t *network, int step) {
    
    // Create or open HDF5 file
    char *fn = "parameters.h5";
    hid_t file_id;
    if (access(fn, F_OK) != 0) {
        // File does not exist, create it
        file_id = H5Fcreate(fn, H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);
    }
    else {
        file_id = H5Fopen(fn, H5F_ACC_RDWR, H5P_DEFAULT);
        if (file_id < 0) {
            // File does not exist, create it
            printf("Error opening file %s\n", fn);
        }
    }

    // Create/open group
    char groupname[16];
    sprintf(groupname, "step_%06d", step);
    hid_t group_id;
    if (H5Lexists(file_id, groupname, H5P_DEFAULT)) {
        group_id = H5Gopen(file_id, groupname, H5P_DEFAULT);
    } else {
        group_id = H5Gcreate(file_id, groupname, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
    }

    // Weights:
    // Define dataspace for 2D array
    hsize_t dims[2] = {MNIST_LABELS, MNIST_IMAGE_SIZE};
    hid_t dataspace_id = H5Screate_simple(2, dims, NULL);

    // If dataset exists, delete it
    if (H5Lexists(group_id, "W", H5P_DEFAULT)) {
        H5Ldelete(group_id, "W", H5P_DEFAULT);
    }
    // Create dataset
    hid_t dataset_id = H5Dcreate(group_id, "W", H5T_NATIVE_FLOAT,
                                 dataspace_id, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);

    // Write data to dataset
    H5Dwrite(dataset_id, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT, network->W);
    H5Dclose(dataset_id);
    H5Sclose(dataspace_id);

    // biases:
    // Define dataspace for 1D array
    hsize_t bdims[1] = {MNIST_LABELS};
    dataspace_id = H5Screate_simple(1, bdims, NULL);

    // If dataset exists, delete it
    if (H5Lexists(group_id, "b", H5P_DEFAULT)) {
        H5Ldelete(group_id, "b", H5P_DEFAULT);
    }
    // Create dataset
    dataset_id = H5Dcreate(group_id, "b", H5T_NATIVE_FLOAT,
                           dataspace_id, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);

    // Write data to dataset
    H5Dwrite(dataset_id, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL, H5P_DEFAULT, network->b);

    // Close resources
    H5Dclose(dataset_id);
    H5Sclose(dataspace_id);
    H5Gclose(group_id);
    H5Fclose(file_id);

    printf("Data written to %s\n", fn);
}


herr_t list_groups(hid_t loc_id, const char *name, const H5L_info_t *info, void *op_data) {
    if (info->type == H5L_TYPE_HARD) {
        char **names = (char **)op_data;
        names[*((int *)names[0])] = strdup(name);
        (*((int *)names[0]))++;
    }
    return 0;
}

typedef struct {
    int count;
    char **names;
} iter_data;

// Callback for counting
herr_t count_links(hid_t loc_id, const char *name, const H5L_info_t *info, void *op_data) {
    int *count = (int *)op_data;
    (*count)++;
    return 0;
}

// Callback for collecting names
herr_t collect_names(hid_t loc_id, const char *name, const H5L_info_t *info, void *op_data) {
    iter_data *data = (iter_data *)op_data;
    data->names[data->count] = strdup(name);
    data->count++;
    return 0;
}

// Extract numeric suffix from "step_XXXXX"
int extract_number(const char *name) {
    const char *underscore = strrchr(name, '_');
    return underscore ? atoi(underscore + 1) : -1;
}

// Compare function for qsort (numeric)
int compare_names(const void *a, const void *b) {
    const char *nameA = *(const char **)a;
    const char *nameB = *(const char **)b;
    return extract_number(nameA) - extract_number(nameB);
}

int read_latest_parameters(neural_network_t *network) {
    char *fn = "parameters.h5";

    if (access(fn, F_OK) != 0) { return -1;}
    
    hid_t file_id = H5Fopen(fn, H5F_ACC_RDONLY, H5P_DEFAULT);
    if (file_id < 0) {
        printf("Failed to open file\n");
        return -1;
    }

    // First pass: count groups
    int count = 0;
    hsize_t idx = 0;
    H5Literate(file_id, H5_INDEX_NAME, H5_ITER_INC, &idx, count_links, &count);

    if (count == 0) {
        fprintf(stderr, "No groups found.\n");
        H5Fclose(file_id);
        return 1;
    }
 
    // Allocate memory for names
    char **names = malloc(count * sizeof(char *));
    iter_data data = {0, names};

    // Second pass: collect names
    idx = 0;
    H5Literate(file_id, H5_INDEX_NAME, H5_ITER_INC, &idx, collect_names, &data);

    // Sort names numerically
    qsort(names, count, sizeof(char *), compare_names);

    // Last group name
    char *last_group = names[count - 1];
    int step = extract_number(last_group);
    printf("Last group: %s (step %d)\n", last_group, step);

    // Open last group
    hid_t group_id = H5Gopen(file_id, last_group, H5P_DEFAULT);
    printf("Opened group: %s\n", last_group);

    hid_t dataset_id = H5Dopen(group_id, "W", H5P_DEFAULT);
    herr_t status = H5Dread(dataset_id, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL,
                            H5P_DEFAULT, network->W);
    H5Dclose(dataset_id);
    dataset_id = H5Dopen(group_id, "b", H5P_DEFAULT);
    status = H5Dread(dataset_id, H5T_NATIVE_FLOAT, H5S_ALL, H5S_ALL,
                            H5P_DEFAULT, network->b);
    H5Dclose(dataset_id);

    // Cleanup
    for (int i = 0; i < count; i++) free(names[i]);
    free(names);
    H5Gclose(group_id);
    H5Fclose(file_id);

    return step;
}
