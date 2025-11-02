#include <stdio.h>

int main() {
    float fahr, celcius;
    float lower, upper, step;

    lower = 0;   // Lowest temperature in Fahrenheit
    upper = 100; // Highest temperature in Fahrenheit
    step = 10;   // Increment of temperature

    fahr = lower;
    while (fahr <= upper) {
        celcius = (5.0 / 9) * (fahr - 32);
        printf("%8.1f %8.1f\n", fahr, celcius);
        fahr = fahr + step;
    }
    return 0;
}
