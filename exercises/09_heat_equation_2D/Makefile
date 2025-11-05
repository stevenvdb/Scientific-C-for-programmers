CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra

all: heat_equation_2D

heat_equation_2D: heat_equation_2D.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) heat_equation_2D $(wildcard *.o)
	$(RM) $(wildcard core.*) core
