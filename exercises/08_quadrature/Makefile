CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra
CLIBS = -lm

all: quadrature

quadrature: quadrature.c
	$(CC) $(CFLAGS) $(CLIBS) -o $@ $<

clean:
	$(RM) quadrature $(wildcard *.o)
	$(RM) $(wildcard core.*) core
