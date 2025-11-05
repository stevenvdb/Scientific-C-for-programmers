#include <stdio.h>
#include <math.h>

int main(void) {
    int N, max_iter = 10000, iter;
    double T0, TL, tol = 1e-6;

    printf("Enter number of points: ");
    scanf("%d", &N);
    printf("Enter left boundary temperature T0: ");
    scanf("%lf", &T0);
    printf("Enter right boundary temperature TL: ");
    scanf("%lf", &TL);

    double T[N], T_old[N];

    // Initialize temperatures
    for (int i = 0; i < N; i++) {
        T[i] = 0.0;
    }
    T[0] = T0;
    T[N-1] = TL;

    // Iterative relaxation
    // FIXME: Write a loop over iter from 0 up to max_iter
        double max_diff = 0.0;
        //FIXME: Copy the values of T into T_old

        for (int i = 1; i < N-1; i++) {
            //FIXME: Update temperature at point i
            double diff = fabs(T[i] - T_old[i]);
            if (diff > max_diff)
                max_diff = diff;
        }

        if (max_diff < tol)
            break;
    }

    printf("\nSteady-state temperature distribution after %d iterations:\n", iter);
    for (int i = 0; i < N; i++) {
        printf("x = %5.2f, T = %8.4f\n", (double)i / (N-1), T[i]);
    }

    return 0;
}
