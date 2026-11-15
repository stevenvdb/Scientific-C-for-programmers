#include <math.h>
#include <stdlib.h>

double get_random_double() {
    // Get a random double in [0, 1]
    int x = rand();
    return (double) x / RAND_MAX;
}

double estimate_pi(unsigned long N) {
    double x, y;
    unsigned long hits = 0;

    // This can be used to seed the random number generator
    srand(0);

    for (unsigned long i = 0; i < N; i++) {
        x = get_random_double();
        y = get_random_double();
        if ( x*x + y*y < 1 ) {
            hits++;
        }
    }
    return 4.0 * hits / N;
}
