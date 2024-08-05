#include<stdio.h>
#include<stdlib.h>
int u(int n) {
	if (n == 0)
	{
		return n;
	}
	for (int i = (n-1); i >(n-6); i--)
	{
		return u(i);
	}
	
}
//void main() {
//	int n;
//	printf("nhap n: ");
//	scanf_s("%d", &n);
//	if (n < 6) {
//		printf("nhap lai n: ");
//		scanf_s("%d", &n);
//	}
//	printf("so u can tim la: %d", u(n));
//}