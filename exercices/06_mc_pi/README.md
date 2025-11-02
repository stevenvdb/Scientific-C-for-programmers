# Compute $\pi$ using Monte Carlo

## Goal

- Write a program that approximates $\pi$ by using a Monte Carlo algorithm

## Learning outcomes

- Write a loop and use control flow

## Instructions

- The quarter unit circle in the first quadrant has area $\frac{\pi}{4}$. Approximate this
area by generating uniformly distributed points in $[0,1] \times [0,1]$ (`get_random_double` is provided) and selecting
points inside a unit circle
- Edit `mc_pi.c` and write a loop that samples random points and use this to estimate pi
- How does the estimate converge with the number of samples?
