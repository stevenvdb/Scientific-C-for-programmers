CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra

all: dna_sequencing

dna_sequencing: dna_sequencing.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) dna_sequencing $(wildcard *.o)
	$(RM) $(wildcard core.*) core
