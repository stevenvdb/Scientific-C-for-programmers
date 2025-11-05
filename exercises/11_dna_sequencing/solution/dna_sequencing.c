#include <stdio.h>
#include <string.h>

#define MAX_SEQ 5
#define MAX_SEQ_LENGTH 1024
#define MAX_NAME_LENGTH 64
#define NUM_MOTIFS 2

// Define a struct suitable to store a DNA sequence and metadata
struct DNASequence {
    char id[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    char sequence[MAX_SEQ_LENGTH];
};

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
    struct DNASequence sequences[MAX_SEQ] = {
        {"seq1", "Alice", "ATCGGGTAATCG"},
        {"seq2", "Bob",   "GGTAATCGGGTA"},
        {"seq3", "Carol", "ATCGATCGGGTA"},
        {"seq4", "Dave",  "GGGGATCGATCG"},
        {"seq5", "Eve",   "ATCGGGGGGGTA"}
    };

    // Motifs associated with hypothetical disease
    const char *motifs[NUM_MOTIFS] = {"ATCG", "GGTA"};

    // Analyze sequences; for each DNA sequence, compute the risk score for
    // each motif, but counting the number of times the motif appears
    for (int i = 0; i < MAX_SEQ; i++) {
        int risk_score = 0;

        for (int j = 0; j < NUM_MOTIFS; j++) {
            risk_score += count_motif(sequences[i].sequence, motifs[j]);
        }

        printf("ID: %s, Name: %s, Risk Score: %d\n",
               sequences[i].id, sequences[i].name, risk_score);
    }

    return 0;
}
