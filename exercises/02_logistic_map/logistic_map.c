#include <stdio.h>

<return type> update_population(<list of arguments (type + local name>) {
}

int main() {
    const int Nsteps = 100;

    double growth_rate;
    double current_population = 0.5;

    printf("Please enter the growth rate: ");
    scanf("%lf", &growth_rate);

    FILE *outputfile = fopen("population.txt", "w");

    for (int i=0; i < Nsteps; i++){
        current_population = update_population(current_population, growth_rate);
        fprintf(outputfile, "%d %12.6f\n", i, current_population);
    }

    fclose(outputfile);
    return 0;
}
