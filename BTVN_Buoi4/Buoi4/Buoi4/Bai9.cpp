#include <stdio.h>

double factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

double S1_recursive(int n) {
    if (n == 1) return 1.0 / (1 * 2 * 3);
    return 1.0 / (n * (n + 1) * (n + 2)) + S1_recursive(n - 1);
}

double S1_iterative(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (i * (i + 1) * (i + 2));
    }
    return sum;
}

int S2_recursive(int n) {
    if (n == 1) return 1;
    return n * n + S2_recursive(n - 1);
}

int S2_iterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

int sum_to_n(int n) {
    if (n == 1) return 1;
    return n + sum_to_n(n - 1);
}

int S3_recursive(int n) {
    if (n == 1) return 1;
    return sum_to_n(n) + S3_recursive(n - 1);
}

int S3_iterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * (i + 1) / 2;
    }
    return sum;
}

double factorial_double(int n) {
    if (n == 0) return 1.0;
    return n * factorial_double(n - 1);
}

double S4_recursive(int n) {
    if (n == 1) return (1.0 * (2 - 1)) / factorial_double(2);
    double term = (2 * n - 1 + 2 * n) / factorial_double(2 * n);
    if (n % 2 == 0) term = -term;
    return term + S4_recursive(n - 1);
}

double S4_iterative(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        double term = (2 * i - 1 + 2 * i) / factorial_double(2 * i);
        if (i % 2 == 0) term = -term;
        sum += term;
    }
    return sum;
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf_s("%d", &n);

    printf("S1_recursive(%d) = %f\n", n, S1_recursive(n));
    printf("S1_iterative(%d) = %f\n", n, S1_iterative(n));

    printf("S2_recursive(%d) = %d\n", n, S2_recursive(n));
    printf("S2_iterative(%d) = %d\n", n, S2_iterative(n));

    printf("S3_recursive(%d) = %d\n", n, S3_recursive(n));
    printf("S3_iterative(%d) = %d\n", n, S3_iterative(n));

    printf("S4_recursive(%d) = %f\n", n, S4_recursive(n));
    printf("S4_iterative(%d) = %f\n", n, S4_iterative(n));

    return 0;
}
