#include <stdio.h>

double update_population(double current_population, double growth_rate) {
    return growth_rate * current_population * (1.0 - current_population);
}


int main() {
    const int Nsteps = 100;

    double growth_rate;
    double current_population;

    printf("Please enter the growth rate: ");
    int nread = scanf("%lf", &growth_rate);
    // Check input was read correctly
    if (nread != 1) {
        printf("Failed to read input!\n");
        return 1;
    }
    // Check input value makes sense
    if (growth_rate < 0.0 || growth_rate >= 4.0) {
        printf("The growth rate has to be in the interval [0, 4[\n");
        return 1;
    }

    printf("Please enter the initial population: ");
    nread = scanf("%lf", &current_population);
    // Check input was read correctly
    if (nread != 1) {
        printf("Failed to read input!\n");
        return 1;
    }
    // Check input value makes sense
    if (current_population < 0.0 || current_population > 1.0) {
        printf("The initial population has to be in the interval [0, 1]\n");
        return 1;
    }

    FILE *outputfile = fopen("population.txt", "w");

    for (int i=0; i < Nsteps; i++){
        current_population = update_population(current_population, growth_rate);
        fprintf(outputfile, "%d %12.6f\n", i, current_population);
    }

    fclose(outputfile);
    return 0;
}
