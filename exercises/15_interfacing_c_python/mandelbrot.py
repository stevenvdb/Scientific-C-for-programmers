import numpy as np
import cmath
import matplotlib.pyplot as plt


if __name__ == '__main__':
    # Parameters
    xmin = -2.0  # Lowest real value
    xmax = 1.0   # Highest real value
    nx = 201     # Number of grid points along real axis
    ymin = -1.0  # Lowest imaginary value
    ymax = 1.0   # Highest imaginary value
    ny = 201     # Number of grid points along imaginary axis
    maxiter = 256    # Limit on the number of iterations
    threshold = 2.0  # Iterations are considered diverged if norm(z) exceeds this

    # Derived parameters
    deltax = (xmax - xmin) / (nx - 1)
    deltay = (ymax - ymin) / (ny - 1)
    niter = np.zeros((nx, ny))

    # Loop over the grid
    for i in range(nx):
        for j in range(ny):
            c = complex(xmin + i * deltax, ymin + j * deltay)
            z = 0.0
            # Apply z_{n+1} <- z_n^2 + c until it diverges or
            # reaches the maximal number of iterations
            for k in range(maxiter):
                z = z * z + c
                norm, _ = cmath.polar(z)
                if norm > threshold:
                    break
            niter[i,j] = k

    # Plot the number of iterations
    plt.imshow(niter.T, extent=[xmin, xmax, ymin, ymax], cmap='hot')
    plt.title('Mandelbrot set')
    plt.xlabel('Re(c)')
    plt.ylabel('Im(c)')
    plt.savefig('mandelbrot.png')
