#include <stdio.h>
#include <assert.h>

unsigned long fibonacci_recursive(unsigned long N) {
    if (N == 0)
        return 0;
    else if (N == 1)
        return 1;
    else
        return fibonacci_recursive(N - 1) + fibonacci_recursive(N - 2);
}


unsigned long fibonacci_loop(unsigned long N) {
    unsigned long f_old, f_new, tmp;
    if (N == 0)
        return 0;
    else if (N == 1)
        return 1;
    else {
        f_old = 0;
        f_new = 1;
        for (unsigned long i = 2; i <= N; i++) {
            tmp = f_new;
            f_new = f_new + f_old;
            f_old = tmp;
        }
        return f_new;
    }
}

int main() {
    unsigned long N = 10;
    assert(fibonacci_recursive(N) == 55);
    assert(fibonacci_loop(N) == 55);
    return 0;
}
