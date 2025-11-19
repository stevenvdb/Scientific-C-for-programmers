#include <stdio.h>
#include <assert.h>

int isLeapYear(int year) {
    /* Return 1 if year is a leap year and return 0 otherwise
       A year is a leap year if:
       - it is divisible by 4 but not by 100 OR
       - it is disisible by 400
    */
    return 0;
}

int main() {
    // Implement the isLeapYear function body
    assert(isLeapYear(1996));
    assert(!isLeapYear(1995));
    assert(!isLeapYear(1900));
    assert(isLeapYear(2000));

    // Multiply i by 8 and store it in j, but without making use of the * operator
    // Hint: use a bitwise operator 
    int i = 5;
    int j = -1;
    assert(j == 40);

    // Compute c as the minimal value of a and b without using an if-else statement
    int a = 126;
    int b = 45;
    int c = -1;
    assert(c == b);

    printf("All checks passed!\n");

    return 0;
}
