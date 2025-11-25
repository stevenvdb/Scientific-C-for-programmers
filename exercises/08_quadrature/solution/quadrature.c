#include <stdio.h>
#include <math.h>

double trapezoidRule (double (*f)(double), double a, double b) {
    return (b-a)*(f(a) + f(b))/2;
}

double quadrature (double (*f)(double), double x0, double xN, long int N) {
    // Set up an equidistant grid
    double x[N];
    for (long int i=0; i < N; i++) {
        x[i] = x0 + (xN - x0) * i / (N - 1);
    }
    // Numerically integrate by applying trapezoid rule to each segment
    double integral = 0;
    for (long int i=0; i < N-1; i++) {
        integral += trapezoidRule(f, x[i], x[i+1]);
    }
    return integral;
}

double cos_square(double x) {
    return cos(x) * cos(x);
}

int main(void) {
    // Number of grid points
    long int N = 100;
    double x0, xN, integral;
    // Integration interval
    x0 = 0.0;
    xN = M_PI / 2;

    integral = quadrature(sin, x0, xN, N);
    printf("The integral of sin between %.6f and %.6f is %.6f\n", x0, xN, integral);
    integral = quadrature(cos_square, x0, xN, N);
    printf("The integral of cos^2 between %.6f and %.6f is %.6f\n", x0, xN, integral);

    return 0;
}
