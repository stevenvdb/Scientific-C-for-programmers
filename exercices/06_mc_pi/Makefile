CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra

all: mc_pi

mc_pi: mc_pi.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) mc_pi $(wildcard *.o)
	$(RM) $(wildcard core.*) core
