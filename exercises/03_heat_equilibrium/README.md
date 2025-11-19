# Heat Distribution Along a Metal Rod

## Goal

This program computes the **steady-state temperature distribution** along a
one-dimensional metal rod with fixed boundary temperatures. The system
evolves according to the heat equation
($\frac{\partial T(x,t)}{\partial t} = \frac{\partial^2 T(x,t)}{\partial x^2}$)
until it reaches equilibrium. The program searches for equilibrium by updating
each interior point’s temperature as the average of its neighbors:
$T^{i} \leftarrow \frac{1}{2}\left( T^{i-1} + T^{i+1} \right)$.

## Learning Outcomes

- Learn how to use **arrays** in C to store and update a physical field.
- Understand **iterative numerical methods** for solving steady-state problems.
- Practice **loops**, **floating-point arithmetic**, and **convergence testing**.
- Connect basic programming constructs with a meaningful **scientific model** (the steady-state heat equation).

## Instructions

1. Search for lines containing "FIXME" in the `heat_equilibrium.c` source code
2. Compile and run the code with `gcc heat_equilibrium.c -o heat_equilibrium && ./heat_equilibrium`
3. When prompted, enter:
   - The number of grid points `N` (e.g., 20).
   - The left and right boundary temperatures `T0` and `TL` (e.g., 1.0 and 5.0).
4. The program will iteratively solve for the temperature at each interior point until convergence.
5. Observe how the printed temperature profile varies linearly between the two boundary values.
6. **Bonus:**
   - Try different boundary temperatures and resolutions (`N`).
   - Modify the tolerance or maximum iterations.
   - Print the intermediate profiles every few iterations to see convergence behavior.

### Example Output
```
Enter number of points: 10
Enter left boundary temperature T0: 100
Enter right boundary temperature TL: 50

Steady-state temperature distribution after 356 iterations:
x =  0.00, T = 100.0000
x =  0.11, T =  94.4444
x =  0.22, T =  88.8889
x =  0.33, T =  83.3333
x =  0.44, T =  77.7778
x =  0.56, T =  72.2222
x =  0.67, T =  66.6667
x =  0.78, T =  61.1111
x =  0.89, T =  55.5556
x =  1.00, T =  50.0000
```

### Extension Ideas
- Compare the numerical result with the analytical linear solution.
- Add an internal heat source term.
- Visualize the results using a plotting tool (e.g., gnuplot or Python).
