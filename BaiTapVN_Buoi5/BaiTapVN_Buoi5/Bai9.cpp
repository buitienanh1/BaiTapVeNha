#include<stdio.h>
#include<stdlib.h>
#include<cmath>
double Cau9_1(int a) {
	if (a == 0) {
		return 0;
	}
	double chia=0;
	chia = (1.0 / (a * (a + 1) * (a + 2)));
	return chia + (Cau9_1(a - 1));
}
int Cau9_2(int n) {
	if (n == 0) {
		return 0;
	}
	return pow(n,2) + Cau9_2(n - 1);
}
int Cau9_3(int n) {
	if (n == 0) {
		return 0;
	}
	int tong = 0 ;
	for (int i = 1; i <= n; i++)
	{
		tong += i;
	}
	return tong + Cau9_3(n - 1);
}
int giaiThua(int n)
{
	if (n == 1)
		return 1;
	return n * giaiThua(n - 1);
}
int Cau9_4(int n) {
	if (n == 0) {
		return 0;
	}
	return ((2*n-1)+(2*n))/(giaiThua(2*n)) + Cau9_2(n - 1);
}

//void main() {
//	int n;
//	printf("nhap so can tinh: ");
//	scanf_s("%d", &n);
//	printf("Tong phep tinh 1/(1*2*3)+...+1/(n*(n+1)*(n+2) la %.5f", Cau9_1(n));
//	printf("\nTong phep tinh 1 mu 2+...+ n mu 2 la %d", Cau9_2(n));
//	printf("\nTong phep tinh 1+...+ (n+..+1) la %d", Cau9_3(n));
//	printf("\nTong phep tinh (1+2/2!)+...+ ((2n-1)+(2n)/2n!) la %d", Cau9_4(n));
//}
