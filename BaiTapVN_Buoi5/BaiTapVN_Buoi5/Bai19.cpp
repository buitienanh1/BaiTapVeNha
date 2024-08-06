#include<stdio.h>
#include<stdlib.h>
int a(int n) {
    if (n == 1) {
        return 1;  // A1 = 1
    }
    if (n % 2 == 0) {
        int m = n / 2;  // n là số chẵn
        return m + a(m) + 2;  // A2n = n + An + 2
    }
    else {
        int m = n / 2;  // n là số lẻ
        return m * m + a(m) * a(m + 1) + 1;  // A2n+1 = n^2 + An.An+1 + 1
    }
}
void main() {
	int n;
	printf("nhap n: ");
	scanf_s("%d", &n);
	printf("\nso A tai vi tri %d can tim la: %d",n, a(n));
}