#include<stdio.h>
#include<stdlib.h>
int X(int n) {
	if (n == 1) {
		return 1;
	}if (n == 2) {
		return 1;
	}
	return X(n - 1) + (n-1) * X(n - 2);
}
void main() {
	int n;
	printf("nhap n: ");
	scanf_s("%d", &n);
	if (n < 3) {
		printf("\nnhap lai n: ");
		scanf_s("%d", &n);
	}
	printf("\nso X can tim la: %d", X(n));
}