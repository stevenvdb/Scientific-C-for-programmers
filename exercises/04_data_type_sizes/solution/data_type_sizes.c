#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <float.h>


int main() {

    printf("The size of char is %zu bytes; it ranges from %d to %d\n",
           sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("The size of int is %zu bytes; it ranges from %d to %d\n",
           sizeof(int), INT_MIN, INT_MAX);
    printf("The size of unsigned long int is %zu bytes; its max is %lu\n",
           sizeof(unsigned long int), ULONG_MAX);
    printf("The size of uint32_t is %zu bytes\n", sizeof(int16_t));

    printf("The largest double that can be represented is %6.1e\n", DBL_MAX);
    printf("The smallest positive double that can be represented is %6.1e\n", DBL_MIN);
    printf("The machine epsilon is %6.1e\n", DBL_EPSILON);
    printf("The number of digits is %d\n", DBL_DIG);

    return 0;
}
