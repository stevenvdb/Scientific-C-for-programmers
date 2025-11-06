# Heat equation

## Goal

- Write a program that integrates the 2D heat equation over time

## Learning outcome

- Learn to work with multi-dimensional arrays

## Instructions

- The homogeneous heat equation $\frac{\partial u}{\partial t} = \kappa \Delta u$ describes
  the time- and space dependence of the temperature, with $\kappa$ the diffusivity
  constant. In a computer program, space and time are discretized and the update
  formula looks as follows:

  $$u_{i,j}(n+1) \leftarrow \kappa \delta t \left(\frac{u_{i+1,j}(n) - 2 * u_{i,j}(n) + u_{i-1,j}(n)}{\delta x ^2} + \frac{u_{i,j-1}(n) - 2 * u_{i,j}(n) + u_{i,j-1}(n)}{\delta y ^2}\right)$$

- Write a program that applies this formula iteratively, starting from $u_{i,j}(0)$
  that is zero, except in the first quadrant where it is 1. The boundary conditions
  are such that $u$ is zero at the edges of the domain (Dirichlet boundary conditions).
- You can start from the provided `heat_equation_2D.c` skeleton, but be aware
  that it contains some (nasty) bugs!
- Run the program in order to generate binary files containing the field at
  selected timesteps. You can generate a movie using the supplied `make_movie.py`
  python script. Does the visualization match your physical intuition?
- [Bonus] The time integration currently uses the so-called forward Euler
  method. Look up a different method with some benefits and implement it as
  well.
- [Bonus] The fields at different timesteps are dumped to separate files.
  Change this so that only a single file is generated and information about
  the grid size and time is included. Adapt the `make_movie.py` script accordingly.
