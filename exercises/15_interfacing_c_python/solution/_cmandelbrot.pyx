""" Example of wrapping a C function that fills a 2D array of integers,
    using the NumPy declarations from Cython """

# cimport the Cython declarations for NumPy
cimport numpy as np

# if you want to use the NumPy-C-API from Cython
# (not strictly necessary for this example, but good practice)
np.import_array()

# cdefine the signature of our c function
cdef extern from "cmandelbrot.h":
    void compute_mandelbrot_iterations(
        int * niter, int nx, int ny, double xmin, double xmax, double ymin,
        double ymax, int maxiter, double threshold)

# create the wrapper code, with NumPy type annotations
def compute_niter(np.ndarray[int, ndim=2, mode="c"] niter not None, double xmin,
                  double xmax, double ymin, double ymax, int maxiter, double threshold):
    compute_mandelbrot_iterations(<int*> np.PyArray_DATA(niter),
                niter.shape[0], niter.shape[1], xmin, xmax, ymin, ymax, maxiter, threshold)
