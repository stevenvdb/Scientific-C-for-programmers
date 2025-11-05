# Handwriting recognition

## Goal

- Train a model that can recognize handwritten digits

## Learning outcomes

- Work with HDF5 and BLAS libraries

## Instructions

- Use https://github.com/AndrewCarterUK/mnist-neural-network-plain-c/ as a
  starting point.
- Add checkpointing: allow storing parameters at the end of training in HDF5
  format. Also allow reading them back in as initial guess to resume training.
- Replace the linear algebra operations by calls to BLAS. Compare the performance
  with the original implementation.
