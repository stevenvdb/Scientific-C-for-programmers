CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra

all: convert_temperatures

convert_temperatures: convert_temperatures.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) convert_temperatures $(wildcard *.o)
	$(RM) $(wildcard core.*) core
