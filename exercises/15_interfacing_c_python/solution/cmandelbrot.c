#include "cmandelbrot.h"

/*  Compute the number of Mandelbrot iterations */
void compute_mandelbrot_iterations(
    int * niter, int nx, int ny, double xmin, double xmax, double ymin,
    double ymax, int maxiter, double threshold)
{
    double deltax = (xmax - xmin) / (nx - 1);
    double deltay = (ymax - ymin) / (ny - 1);
    double threshold2 = threshold * threshold;

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            double cr = xmin + i * deltax;
            double ci = ymin + j * deltay;
            double zr = 0.0, zi = 0.0;

            // Apply z <- z^2 + c until it diverges or reaches maxiter
            int k;
            for (k = 0; k < maxiter; k++) {
                double zr_new = zr * zr - zi * zi + cr;
                zi = 2.0 * zr * zi + ci;
                zr = zr_new;
                if (zr * zr + zi * zi > threshold2) {
                    break;
                }
            }
            if (k == maxiter) {
                k = maxiter - 1;
            }

            // niter is a C-contiguous (nx, ny) array: element [i, j] is at i * ny + j
            niter[i * ny + j] = k;
        }
    }
}
