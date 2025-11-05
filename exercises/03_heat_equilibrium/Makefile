CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra

all: heat_equilibrium

heat_equilibrium: heat_equilibrium.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) heat_equilibrium $(wildcard *.o)
	$(RM) $(wildcard core.*) core
