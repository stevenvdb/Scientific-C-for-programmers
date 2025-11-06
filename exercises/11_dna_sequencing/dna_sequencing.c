#include <stdio.h>
#include <string.h>

#define MAX_SEQ 5
#define MAX_SEQ_LENGTH 1024
#define MAX_NAME_LENGTH 64
#define NUM_MOTIFS 2

// Define a struct suitable to store a DNA sequence and metadata

// Define a struct suitable to store motifs and metadata

// Function to count occurrences of a motif in a sequence
int count_motif(const char *sequence, const char *motif) {
    int count = 0;
    int motif_len = strlen(motif);
    int seq_len = strlen(sequence);

    for (int i = 0; i <= seq_len - motif_len; i++) {
        if (strncmp(&sequence[i], motif, motif_len) == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    // Initialize DNA sequences

    // Initialize motifs

    // Analyze sequences; for each DNA sequence, compute the risk score for
    // each motif, but counting the number of times the motif appears

    return 0;
}
