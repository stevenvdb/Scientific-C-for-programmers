# DNA Sequence Analysis for Disease-Associated Patterns

## Goal

Write a program to detect motifs in a DNA sequence associated with an increased
risk of a hypothetical disease

## Learning Outcomes

- Define and use `struct`s for organizing biological data
- Work with arrays of structs
- Work with string functions from the string header (hint: https://cplusplus.com/reference/cstring/strncmp/)

## Instructions

- Consider the following hypothetical DNA sequences:

  | ID  |  Name | Sequence |
  | --- | ----- | -------- |
  | seq1 | Alice | ATCGGGTAATCG |
  | seq2 | Bob  | GGTAATCGGGTA |
  | seq3 | Carol | ATCGATCGGGTA |
  | seq4 | Dave | GGGGATCGATCG |
  | seq5 | Eve | ATCGGGGGGGTA |

  Imagine that the number of times one of the following motifs is present,
  increases the risk to carry a certain disease:

  | Motif | Disease |
  | ----- | ------- |
  | ATCG  | Disease1 |
  | GGTA  | Disease2 |

- Construct `struct`s to represent DNA sequences and motifs
- Compute for each sequence and for each disease the risk factor
