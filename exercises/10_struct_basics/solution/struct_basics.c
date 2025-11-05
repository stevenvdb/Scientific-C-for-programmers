#include <stdio.h>
#include <stdarg.h>


struct Person {
    double height;
    double weight;
    int year_of_birth;
    char initial;
};


double sumWeights(int n, ...) {
    va_list persons;
    va_start(persons, n);
    double totalweight = 0.0;
    for (int i=0; i<n; i++) {
        struct Person p = va_arg(persons, struct Person);
        totalweight += p.weight;
    }
    va_end(persons);
    return totalweight;
}

int main(void) {


    printf("The size of struct Person is %zu bytes\n", sizeof(struct Person));

    // Explicitly initialize all members
    struct Person p1;
    p1.height = 183.0;
    p1.weight = 84.2;
    p1.year_of_birth = 1988;
    p1.initial = 's';

    // Initialize directly, can be dangerous if order of members changes
    struct Person p2 = {178.0, 76.6, 2000, 'a'}; 

    printf("The total weight is %f\n", sumWeights(2, p1, p2));
    return 0;
}
