#include<stdio.h>
#include<stdlib.h>
double findGeometricTerm(int n, double a, double q) {
    if (n == 1) {
        return a; // Điều kiện dừng
    }
    return q * findGeometricTerm(n - 1, a, q); // Đệ quy
}
//void main() {
//    int n;
//    double a, q;
//    printf("nhap hang dau a: ");
//    scanf_s("%f", &a);
//    printf("\nnhap cong boi q: ");
//    scanf_s("%f", &q);
//    printf("\nnhap so hang thu n: ");
//    scanf_s("%d", &n);
//    double result = findGeometricTerm(n, a, q);
//    printf("gia tri phan tu thu %d cua cap so nhan: %.5f", n, result);
//}