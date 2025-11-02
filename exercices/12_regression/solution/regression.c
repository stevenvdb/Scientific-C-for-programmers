#include <stdio.h>

int main() {
    char fn[] = "land_global_temperature_anomaly-1880-2016.csv";
    FILE *fp;
    fp = fopen(fn, "r");
    if (fp == NULL) {
        printf("Failed to open %s\n", fn);
        return 1;
    }
    
    // Assumes no line is longer than 256 characters
    char line[256];
    int year;
    double temp, mean_temp;
    int Nmeasurements = 0;
    double xsum = 0.0;
    double ysum = 0.0;
    double xxsum = 0.0;
    double xysum = 0.0;

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%d,%lf\n", &year, &temp) == 2) {
            printf("In year %d the temperature anomaly was %f\n", year, temp);
            mean_temp += temp;
            Nmeasurements++;
            xsum += year;
            ysum += temp;
            xxsum += year * year;
            xysum += year * temp;
        } else {
            printf("Skipping line %s\n", line);
        }
    }
    fclose(fp);

    mean_temp /= Nmeasurements;
    printf("The average temperature anomaly was %f\n", mean_temp);

    double beta = (xysum - xsum * ysum / Nmeasurements) / (xxsum - xsum * xsum / Nmeasurements);
    double alpha = (ysum - beta * xsum) / Nmeasurements;
    printf("alpha = %f beta = %f\n", alpha, beta);
    for (int year = 2017; year < 2030; year++) {
        temp = alpha + beta * year;
        printf("year = %d temp = %f\n", year, temp);
    }


    return 0;
}
