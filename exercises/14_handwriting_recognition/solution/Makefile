CC ?= gcc
CFLAGS = -O2 -Wall
CLIBS = -lm -lhdf5
DEPS = mnist_file.c checkpointing.c neural_network.c

all: training inference

training: training.c $(DEPS)
	$(CC) $(CFLAGS) $< $(DEPS) -o $@ $(CLIBS)
inference: inference.c $(DEPS)
	$(CC) $(CFLAGS) $< $(DEPS) -o $@ $(CLIBS)

clean:
	$(RM) training inference $(wildcard *.o)
	$(RM) $(wildcard core.*) core
