CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra

all: operators

operators: operators.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) operators $(wildcard *.o)
	$(RM) $(wildcard core.*) core
