import numpy as np
import matplotlib.pyplot as plt
import cmandelbrot

if __name__ == '__main__':
    # Parameters
    xmin = -2.0  # Lowest real value
    xmax = 1.0   # Highest real value
    nx = 501     # Number of grid points along real axis
    ymin = -1.0  # Lowest imaginary value
    ymax = 1.0   # Highest imaginary value
    ny = 501     # Number of grid points along imaginary axis
    maxiter = 256    # Limit on the number of iterations
    threshold = 2.0  # Iterations are considered diverged if norm(z) exceeds this

    niter = np.zeros((nx, ny), dtype=np.intc)
    cmandelbrot.compute_niter(niter, xmin, xmax, ymin, ymax, maxiter, threshold)

    # Plot the number of iterations
    plt.imshow(niter.T, extent=[xmin, xmax, ymin, ymax], cmap='hot')
    plt.title('Mandelbrot set')
    plt.xlabel('Re(c)')
    plt.ylabel('Im(c)')
    plt.savefig('mandelbrot.png')
