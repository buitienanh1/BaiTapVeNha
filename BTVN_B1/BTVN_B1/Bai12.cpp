#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// a. Tìm phân số lớn nhất/nhỏ nhất
pair<double, double> timPhanSoLonNhatNhoNhat(const vector<double>& phanSo) {
    double lonNhat = numeric_limits<double>::lowest();
    double nhoNhat = numeric_limits<double>::max();

    for (double ps : phanSo) {
        if (ps > lonNhat) {
            lonNhat = ps;
        }
        if (ps < nhoNhat) {
            nhoNhat = ps;
        }
    }

    return { lonNhat, nhoNhat };
}

// b. Xóa phần tử tại vị trí k
void xoaPhanTu(vector<double>& phanSo, int k) {
    if (k >= 0 && k < phanSo.size()) {
        phanSo.erase(phanSo.begin() + k);
    }
    else {
        cout << "Vi tri khong hop le!" << endl;
    }
}

// c. Thêm phần tử x tại vị trí k
void themPhanTu(vector<double>& phanSo, double x, int k) {
    if (k >= 0 && k <= phanSo.size()) {
        phanSo.insert(phanSo.begin() + k, x);
    }
    else {
        cout << "Vi tri khong hop le!" << endl;
    }
}

int main() {
    vector<double> phanSo = { 1.5, 2.3, 0.7, 4.1, 3.6 };

    // Tìm phân số lớn nhất và nhỏ nhất
    pair<double, double> ketQua = timPhanSoLonNhatNhoNhat(phanSo);
    double lonNhat = ketQua.first;
    double nhoNhat = ketQua.second;

    cout << "Phan so lon nhat: " << lonNhat << endl;
    cout << "Phan so nho nhat: " << nhoNhat << endl;

    // Xóa phần tử tại vị trí 2
    xoaPhanTu(phanSo, 2);
    cout << "Sau khi xoa phan tu tai vi tri 2: ";
    for (double ps : phanSo) {
        cout << ps << " ";
    }
    cout << endl;

    // Thêm phần tử 5.0 tại vị trí 1
    themPhanTu(phanSo, 5.0, 1);
    cout << "Sau khi them phan tu 5.0 tai vi tri 1: ";
    for (double ps : phanSo) {
        cout << ps << " ";
    }
    cout << endl;

    return 0;
}
