#include<stdio.h>
#include<stdlib.h>
int y(int n);
int x(int n);
int x(int n) {
	if (n == 0)
	{
		return 1;
	}
	return x(n - 1) + y(n - 1);
}
int y(int n) {
	if (n == 0)
	{
		return 0;
	}
	return 3 * x(n - 1) + 2 * y(n - 1);
}
//void main() {
//	int n;
//	printf("nhap so can tinh: ");
//	scanf_s("%d", &n);
//	printf("\nx thu n la: %d", x(n));
//	printf("\ny thu n la: %d", y(n));
//}