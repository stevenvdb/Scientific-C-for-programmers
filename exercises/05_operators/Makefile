CC ?= gcc
CFLAGS = -g -O0 -Wall -Wextra

all: hello

hello: hello.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) hello $(wildcard *.o)
	$(RM) $(wildcard core.*) core
