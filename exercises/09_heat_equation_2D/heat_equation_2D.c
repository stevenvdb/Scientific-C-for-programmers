#include <stdio.h>
#include <stdlib.h>

// Allocate a 2D array
double **allocate_grid(int Nx, int Ny) {
    double **grid = malloc(Nx * sizeof(double *));
    if (grid == NULL) {
        printf("Failed to allocate memory!\n");
        exit(1);
    }
    for (int i=0; i<Nx; i++) {
        grid[i] = malloc(Ny * sizeof(double));
        if (grid[i] == NULL) {
            printf("Failed to allocate memory!\n");
            exit(1);
        }
    }
    return grid;
}



// Compute the right-hand side of the heat equation (excluding the kappa prefactor)
void compute_update(double **u, double **delta_u, int Nx, int Ny) {
    for (int i=0; i<Nx; i++) {
        for (int j=0; j<Ny; j++) {
            delta_u[i][j] = (u[i+1][j] - 2.0 * u[i][j] + u[i-1][j] ) * (Nx * Nx);
            delta_u[i][j] += (u[i][j+1] - 2.0 * u[i][j] + u[i][j-1]) * (Ny * Ny);
        }
    }
}


// Initialize u to be 1 in the first quadrant (excluding the domain boundaries) and
// zero everywhere else.
void initialize_u(double **u, int Nx, int Ny) {
    for (int i=0; i<Nx; i++) {
        for (int j=0; j<Ny; j++) {
            u[i][j] = 0.0;
        }
    }
    for (int i=1; i<Nx/2; i++) {
        for (int j=1; j<Ny/2; j++) {
            u[i][j] = 1.0;
        }
    }
}


// Write u to a binary file as a succession of doubles
void write_to_file(char *fn, double **u, int Nx, int Ny) {
    FILE *f = fopen(fn, "wb");
    
    for (int i = 0; i < Nx; i++) {
        fwrite(u[i], sizeof(double), Ny, f);
    }
    fclose(f);
}


int main() {
    int Nx = 64;
    int Ny = 64;
    double kappa = 2.0;

    double tmax = 600.0 / (kappa * Nx * Ny);
    double timestep = 1.0 / (4 * kappa * Nx * Ny);
    double tcurrent = 0.0;
    int timesteps = 0;
    char fn[32];

    double **u = allocate_grid(Nx, Ny);
    initialize_u(u, Nx, Ny);
    sprintf(fn, "u_%08d.bin", timesteps);
    printf("i = %d t = %.6f %s\n", timesteps, tcurrent, fn);
    write_to_file(fn, u, Nx, Ny);

    while (tcurrent < tmax) {
        double **delta_u = allocate_grid(Nx, Ny);        
        compute_update(u, delta_u, Nx, Ny);
        for (int i=1; i<Nx-1; i++) {
            for (int j=1; j<Ny-1; j++) {
                u[i][j] += kappa * timestep * delta_u[i][j];
            }
        }
        timesteps++;
        tcurrent += timestep;
        if (timesteps % 20 == 0) {
            sprintf(fn, "u_%08d.bin", timesteps);
            printf("i = %08d t = %.6f %s\n", timesteps, tcurrent, fn);
            write_to_file(fn, u, Nx, Ny);
        }
    }

    return 0;
}
