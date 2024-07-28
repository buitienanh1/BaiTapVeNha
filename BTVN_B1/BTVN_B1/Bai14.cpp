#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main() {
    string hoTen;
    int ngay, thang, nam;
    char gioiTinh;

    // Nhap thong tin nguoi lao dong
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap ngay sinh (dd mm yyyy): ";
    cin >> ngay >> thang >> nam;

    cout << "Nhap gioi tinh (M/F): ";
    cin >> gioiTinh;

    // Lay thoi gian hien tai
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now); // Sử dụng localtime_s để an toàn hơn

    int namHienTai = 1900 + ltm.tm_year;
    int thangHienTai = 1 + ltm.tm_mon;
    int ngayHienTai = ltm.tm_mday;

    // Tinh tuoi
    int tuoi = namHienTai - nam;
    if (thangHienTai < thang || (thangHienTai == thang && ngayHienTai < ngay)) {
        tuoi--;
    }

    // Quy dinh nghi huu
    int tuoiNghiHuu = (gioiTinh == 'M' || gioiTinh == 'm') ? 60 : 55;
    int thoiGianNghiHuu = tuoiNghiHuu - tuoi;

    // Kiem tra thoi gian nghi huu
    if (thoiGianNghiHuu < 0) {
        cout << "Nguoi lao dong da du tuoi nghi huu." << endl;
    }
    else {
        cout << "Thoi gian nguoi lao dong duoc nghi huu: " << thoiGianNghiHuu << " nam." << endl;
    }

    return 0;
}
