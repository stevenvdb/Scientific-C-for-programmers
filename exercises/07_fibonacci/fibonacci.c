#include <stdio.h>
#include <assert.h>

unsigned long fibonacci_recursive(unsigned long N) {
    // FIXME Get the Nth element of the Fibonacci sequence using recursion
}


unsigned long fibonacci_loop(unsigned long N) {
    // FIXME Get the Nth element of the Fibonacci sequence using a loop
}

int main() {
    unsigned long N = 10;
    assert(fibonacci_recursive(N) == 55);
    assert(fibonacci_loop(N) == 55);
    return 0;
}
