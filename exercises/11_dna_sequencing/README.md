# DNA Sequence Analysis for Disease-Associated Patterns

## Goal

Write a program to detect motifs in a DNA sequence associated with an increased
risk of a hypothetical disease.

## Learning Outcomes

- Define and use `struct`s for organizing biological data.
- Work with **arrays of structs**.
- Implement string search algorithms in C.
- Translate biological problems into computational algorithms.
- Compute and interpret a simple **risk score** based on sequence patterns.

## Instructions

1. Review the `struct DNASequence` definition in the C code.
2. Notice how each sequence has an **ID**, **name**, and the **sequence string**.
3. The program defines a set of **motifs** associated with disease risk.
4. The program scans each sequence and counts motif occurrences.
5. For each sequence, it prints:
   - The **ID**
   - The **name**
   - The computed **risk score**
6. Your tasks:
   - Modify or add more DNA sequences.
   - Add additional motifs and adjust the program to calculate their contribution to risk.
   - Optionally, read sequences from a file or introduce weighted motifs for more advanced scoring.
