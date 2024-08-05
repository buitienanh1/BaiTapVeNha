#include<stdio.h>
#include<stdlib.h>
int fibonacci_Dc(int n) {
    if (n < 0) {
        return -1;
    }
    else if (n == 0 || n == 1) {
        return n;
    }
    else {
        return fibonacci_Dc(n - 1) + fibonacci_Dc(n - 2);
    }
}
//int main() {
//    int i;
//    printf("10 so dau tien cua day so Fibonacci: \n");
//    for (i = 0; i < 10; i++) {
//        printf("%d ", fibonacci_Dc(i));
//    }
//}