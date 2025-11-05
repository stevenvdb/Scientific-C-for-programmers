#include <stdio.h>
#include <gsl/gsl_linalg.h>

int main() {
    /*
    This programs finds the coefficients for the equation
    a C_3H_8 + b O_2 -> c CO_2 + d H2O
    This is an underdetermined system, since multiplying all coefficients
    that are a solution, gives another solution. We therefore fix a = 1
    and get the following equations:
      C:   0 * b - 1 * c + 0 * d = -3 
      H:   0 * b + 0 * c - 2 * d = -8
      O:   2 * b - 2 * c - 1 * d = 0
    */

    // Reduce system to solve for b, c, d
    double A_reduced_data[] = {
        0, -1, 0,
        0, 0, -2,
        2, -2, -1
    };

    gsl_matrix_view A_reduced = gsl_matrix_view_array(A_reduced_data, 3, 3);
    gsl_vector *rhs = gsl_vector_alloc(3);
    gsl_vector_set(rhs, 0, -3);
    gsl_vector_set(rhs, 1, -8);
    gsl_vector_set(rhs, 2, 0);

    int signum;
    gsl_permutation *p = gsl_permutation_alloc(3);
    gsl_linalg_LU_decomp(&A_reduced.matrix, p, &signum);
    gsl_vector *x = gsl_vector_alloc(3);
    gsl_linalg_LU_solve(&A_reduced.matrix, p, rhs, x);

    printf("a = 1, b = %.2f, c = %.2f, d = %.2f\n",
           gsl_vector_get(x, 0), gsl_vector_get(x, 1), gsl_vector_get(x, 2));

    gsl_vector_free(x);
    gsl_vector_free(rhs);
    gsl_permutation_free(p);

    return 0;
}
