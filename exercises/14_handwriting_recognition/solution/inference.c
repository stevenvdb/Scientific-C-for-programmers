#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>


#define STB_IMAGE_IMPLEMENTATION
#include "include/stb_image.h"
#include "hdf5.h"
#include "include/mnist_file.h"
#include "include/neural_network.h"
#include "include/checkpointing.h"


int main(int argc, char *argv[])
{
    if (argc != 2 ) {
        printf("Expected exactly 1 argument: a .png file!\n");
        exit(1);
    }
    char *image_fn = argv[1];
    
    int width, height, channels;
    unsigned char *img = stbi_load(image_fn, &width, &height, &channels, 1); // force grayscale

    
    if (!img) {
        fprintf(stderr, "Failed to load image\n");
        return 1;
    }

    mnist_image_t mnist_img;

    // Resize using nearest-neighbor
    for (int i = 0; i < MNIST_IMAGE_WIDTH; i++) {
        for (int j = 0; j < MNIST_IMAGE_HEIGHT; j++) {
            int src_x = j * width / MNIST_IMAGE_WIDTH;
            int src_y = i * height / MNIST_IMAGE_HEIGHT;
            unsigned char val = img[src_y * width + src_x];
            mnist_img.pixels[i * MNIST_IMAGE_HEIGHT + j] = val; // keep 0–255
        }
    }

    stbi_image_free(img);

    // Initialise weights and biases with random values
    neural_network_t network;
    int initial_step = read_latest_parameters(&network);
    if (initial_step < 0) {
        neural_network_random_weights(&network);
        initial_step = 0;
    }

    // Calculate the activations for each image using the neural network
    float activations[MNIST_LABELS];
    neural_network_hypothesis(&mnist_img, &network, activations);
    float max_activation = 0.0;
    int prediction = -1;
    for (int i=0; i < MNIST_LABELS; i++) {
        printf("P(%d) = %6.2f%%\n", i, activations[i] * 100.0);
        if (activations[i] > max_activation) {
            max_activation = activations[i];
            prediction = i;
        }
    }
    printf("Digit prediction: %d\n", prediction);
    return 0;
}
