CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra
CLIBS= -lgsl -lgslcblas

all: balancing_equations

balancing_equations: balancing_equations.c
	$(CC) $(CFLAGS) -o $@ $< $(CLIBS)

clean:
	$(RM) balancing_equations $(wildcard *.o)
	$(RM) $(wildcard core.*) core
