#include<stdio.h>
#include<stdlib.h>
int A(int n) {
	if (n == 1) {
		return 1;
	}
	for (int i = n-1; i >0 ; i--)
	{
		return n * A(i);
	}
}
//void main() {
//	int n;
//	printf("nhap n: ");
//	scanf_s("%d", &n);
//	printf("so A can tim la: %d", A(n));
//}