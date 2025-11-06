CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra -lgsl -lgslcblas

all: balancing_equations

balancing_equations: balancing_equations.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) balancing_equations $(wildcard *.o)
	$(RM) $(wildcard core.*) core
