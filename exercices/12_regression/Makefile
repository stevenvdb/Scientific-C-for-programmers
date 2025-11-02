CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra

all: regression

regression: regression.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) regression $(wildcard *.o)
	$(RM) $(wildcard core.*) core
