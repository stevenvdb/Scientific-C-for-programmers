CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra

all: data_type_sizes

data_type_sizes: data_type_sizes.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) data_type_sizes $(wildcard *.o)
	$(RM) $(wildcard core.*) core
