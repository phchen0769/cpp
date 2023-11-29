#include <stdio.h>
#include <math.h>
#include <omp.h>

double func(double x, double k) {
    return k * pow(x, k);
}

double trapezoidal(double a, double b, int n, double k) {
    double h = (b - a) / n;
    double sum = (func(a, k) + func(b, k)) / 2.0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += func(x, k);
    }

    return sum * h;
}

int main() {
    double a = -10.0; // Lower limit of integration range
    double b = 10.0; // Upper limit of integration range
    double k = 3.0; // Your variant number (the number listed in the journal)

    int nsteps1 = 40000000; // Number of steps for the first measurement
    int nsteps2 = 80000000; // Number of steps for the second measurement

    double result1, result2;
    double analyticIntegral = (b * pow(b, k+1) - a * pow(a, k+1)) / (k + 1);

    int maxThreads = omp_get_max_threads();

    printf("Number of Threads\tExecution Time (nsteps = %d)\tAcceleration\n", nsteps1);
    for (int numThreads = 1; numThreads <= maxThreads; ++numThreads) {
        omp_set_num_threads(numThreads);

        double start = omp_get_wtime();
        result1 = trapezoidal(a, b, nsteps1, k);
        double end = omp_get_wtime();
        double time1 = end - start;
        double relativeError1 = fabs((result1 - analyticIntegral) / analyticIntegral);

        printf("%d\t\t\t%.4f seconds\t\t\t%.4f\n", numThreads, time1, 1.0 / time1);
    }

    printf("\n");

    printf("Number of Threads\tExecution Time (nsteps = %d)\tAcceleration\n", nsteps2);
    for (int numThreads = 1; numThreads <= maxThreads; ++numThreads) {
        omp_set_num_threads(numThreads);

        double start = omp_get_wtime();
        result2 = trapezoidal(a, b, nsteps2, k);
        double end = omp_get_wtime();
        double time2 = end - start;
        double relativeError2 = fabs((result2 - analyticIntegral) / analyticIntegral);

        printf("%d\t\t\t%.4f seconds\t\t\t%.4f\n", numThreads, time2, 1.0 / time2);
    }

    return 0;
}