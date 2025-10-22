# Logistic map

The [logistic map](https://en.wikipedia.org/wiki/Logistic_map) is a dynamic
system characterized by the difference equation:
$$x_{n+1} = r x_n\left( 1 - x_n \right)$$
This can be used to model for instance the evolution of a population (with
$x_n$ the (relative) population at time $n$). Depending on the chosen value
for $r$, this system can show chaotic behavior.

## Goal of the program

- Write the time evolution according to the logistic map to a file
- Read the initial value and $r$ parameter as input from the user

## Learning outcomes

- Write your first function
- Write code that asks for a user's input

## Instructions

- Implement the `update_population` function. Compile and run to code and
  check your implementation is correct. You can plot the output (if gnuplot
  is available) by running `gnuplot -p plot.plt`.
- Instead of writing the initial population in the code, ask a user to
  provide it at runtime.
- [Bonus]: find a value of $r$ that should show chaotic behavior. Compare two
  simulations with nearly identical initial populations to show that the
  populations decorrelate over time. 
