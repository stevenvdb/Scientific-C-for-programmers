CC ?= gcc

all: mc_pi
opt: CFLAGS = -O2
opt: mc_pi
noopt: CFLAGS = -O0
noopt: mc_pi
debug: CFLAGS = -g -O0 -Wall -Wextra -DPRINT_PROGRESS
debug: mc_pi

mc_pi: mc_pi.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) mc_pi $(wildcard *.o)
	$(RM) $(wildcard core.*) core
