CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra

all: fibonacci

fibonacci: fibonacci.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) fibonacci $(wildcard *.o)
	$(RM) $(wildcard core.*) core
