#ifndef CHECKPOINTING_H_
#define CHECKPOINTING_H_

int read_latest_parameters(neural_network_t *network);
void write_to_hdf5(neural_network_t *network, int step);

#endif
