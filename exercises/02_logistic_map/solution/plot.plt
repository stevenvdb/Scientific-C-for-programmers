#!/usr/bin/gnuplot -persist

set term png
set output 'population.png'
plot 'populationA.txt' with lines, 'populationB.txt' with lines
