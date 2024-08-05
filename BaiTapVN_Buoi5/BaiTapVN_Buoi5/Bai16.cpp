#include<stdio.h>
#include<stdlib.h>
int Y(int n) {
	if (n == 1) {
		return 1;
	}if (n == 2) {
		return 2;
	}
	if (n == 3)
	{
		return 3;
	}
	return Y(n - 1) + 2 * Y(n - 2) + 3 * Y(n - 3);
}
void main() {
	int n;
	printf("nhap n: ");
	scanf_s("%d", &n);
	if (n < 4) {
		printf("\nnhap lai n: ");
		scanf_s("%d", &n);
	}
	printf("\nso Y can tim la: %d", Y(n));
}