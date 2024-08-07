#include <iostream>
using namespace std;

void calculate(int* pa, int* pb, int& sum, int& diff, int& prod, float& quot) {
    sum = *pa + *pb;
    diff = *pa - *pb;
    prod = *pa * *pb;
    if (*pb != 0) {
        quot = static_cast<float>(*pa) / *pb;
    }
    else {
        quot = 0; // Tránh chia cho 0
    }
}

int main() {
    int a, b;
    cout << "Nhap so a: ";
    cin >> a;
    cout << "Nhap so b: ";
    cin >> b;

    int* pa = &a;
    int* pb = &b;
    int sum, diff, prod;
    float quot;

    calculate(pa, pb, sum, diff, prod, quot);

    cout << "Tong: " << sum << " (dia chi: " << &sum << ")" << endl;
    cout << "Hieu: " << diff << " (dia chi: " << &diff << ")" << endl;
    cout << "Tich: " << prod << " (dia chi: " << &prod << ")" << endl;
    cout << "Thuong: " << quot << " (dia chi: " << &quot << ")" << endl;

    return 0;
}
