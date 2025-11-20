#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double get_random_double() {
    // Get a random double in [0, 1]
    int x = rand();
    return (double) x / RAND_MAX;
}

int main() {
    unsigned long N = 100000000;
    double x, y;
    unsigned long hits = 0;

    // This can be used to seed the random number generator
    srand(0);

    // FIXME Write the Monte Carlo loop

    // FIXME Estimate pi based on the Monte Carlo result

    double error = pi - M_PI;
    printf("Nsamples = %lu Estimated pi = %12.8f Error = %12.4e\n", N, pi, error);

    return 0;
}
