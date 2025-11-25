#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>

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

    struct timeval tstart, tend, walltime;
    gettimeofday(&tstart, NULL);
    for (unsigned long i = 0; i < N; i++) {
        x = get_random_double();
        y = get_random_double();
        if ( x*x + y*y < 1 ) {
            hits++;
        }
#ifdef PRINT_PROGRESS
        if (i % 1000000 == 0) printf("Estimated after %lu: pi = %12.8f\n", i, 4.0 * hits / ( i + 1));
#endif
    }
    gettimeofday(&tend, NULL);
    timersub(&tend, &tstart, &walltime);
    double walltime_s = walltime.tv_sec + 1e-6 * walltime.tv_usec;
    printf("Walltime = %8.3fs, %12.1e iterations/s\n", walltime_s, N / walltime_s);

    double pi = 4.0 * hits / N;
    double error = pi - M_PI;
    printf("Nsamples = %lu Estimated pi = %12.8f Error = %12.4e\n", N, pi, error);

    return 0;
}
