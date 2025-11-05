# Balancing equations

## Goal

Write a program that balances a chemical equation by solving a linear system
of equations using GSL.

## Learning outcomes

Learn how to call functions in GSL.

## Instructions

- Consider the chemical equation $a C_3H_8 + b O_2 \leftrightarrow c CO_2 + d H_2O$.
  Write a program that determines values for a,b,c,d such that the equation is
  balanced (i.e., each element appears as often on the left hand side as on the right
  hand side). Make use of [GSL linear algebra functions](http://gnu.ist.utl.pt/software/gsl/manual/html_node/Linear-Algebra-Examples.html)
  to do this.
- [Bonus]: Find a way to make sure the coefficients are integer
