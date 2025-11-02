CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra

all: struct_basics

struct_basics: struct_basics.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) struct_basics $(wildcard *.o)
	$(RM) $(wildcard core.*) core
