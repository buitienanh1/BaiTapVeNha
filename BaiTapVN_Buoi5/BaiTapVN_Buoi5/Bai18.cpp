#include<stdio.h>
#include<stdlib.h>
int X_Bai18(int n) {
	if (n == 0) {
		return 1;
	}if (n == 1) {
		return 2;
	}
	int Tong = 0;
	for (int i = 0; i < n; i++) {
		Tong += (n - i) * X_Bai18(i);
	}
	return Tong;
}
void main() {
	int n;
	printf("nhap n: ");
	scanf_s("%d", &n);
	printf("\nso X can tim la: %d", X_Bai18(n));
}