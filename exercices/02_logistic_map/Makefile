CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra

all: logistic_map

logistic_map: logistic_map.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) logistic_map $(wildcard *.o)
	$(RM) $(wildcard core.*) core
