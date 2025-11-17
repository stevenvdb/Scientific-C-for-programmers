#!/usr/bin/gnuplot -persist

set term png
set output 'population.png'
plot 'population.txt' with lines
