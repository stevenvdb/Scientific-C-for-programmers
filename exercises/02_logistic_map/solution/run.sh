#!/bin/bash

make
echo 3.8 0.500 | ./logistic_map
mv population.txt populationA.txt
echo 3.8 0.495 | ./logistic_map
mv population.txt populationB.txt
gnuplot -p plot.plt
