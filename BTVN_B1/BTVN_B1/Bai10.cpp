#include <iostream>
#include <cstring>

using namespace std;

// Ham in tung ky tu cua chuoi
void inKyTu(char* st) {
    cout << "Gia tri tung ky tu cua chuoi: ";
    for (int i = 0; *(st + i) != '\0'; i++) {
        cout << *(st + i) << " ";
    }
    cout << endl;
}

// Ham chuyen tat ca ky tu thanh chu hoa
void chuyenTatCaThanhChuHoa(char* st) {
    for (int i = 0; *(st + i) != '\0'; i++) {
        if (*(st + i) >= 'a' && *(st + i) <= 'z') {
            *(st + i) = *(st + i) - 32; // Chuyen ve chu hoa
        }
    }
}

// Ham chuyen ky tu dau moi tu thanh chu hoa
void chuyenKyTuDauCuaTuThanhChuHoa(char* st) {
    bool tuMoi = true; // Bien danh dau bat dau tu moi
    for (int i = 0; *(st + i) != '\0'; i++) {
        if (*(st + i) == ' ') {
            tuMoi = true; // Gap dau cach, danh dau tu moi
        }
        else if (tuMoi && *(st + i) >= 'a' && *(st + i) <= 'z') {
            *(st + i) = *(st + i) - 32; // Chuyen ky tu dau tien cua tu thanh chu hoa
            tuMoi = false; // Danh dau khong phai la ky tu dau cua tu nua
        }
        else {
            tuMoi = false; // Khong phai ky tu dau cua tu
        }
    }
}

int main() {
    char st[100];

    cout << "Nhap vao chuoi: ";
    cin.getline(st, 100); // Nhap chuoi co dau cach

    // a. Xuat gia tri tung ky tu
    inKyTu(st);

    // b. Chuyen tat ca ky tu thanh chu hoa
    chuyenTatCaThanhChuHoa(st);
    cout << "Chuoi sau khi chuyen tat ca ky tu thanh chu hoa: " << st << endl;

    // c. Khoi phuc chuoi goc de thuc hien yeu cau c
    cout << "Nhap lai chuoi de chuyen ky tu dau moi tu thanh chu hoa: ";
    cin.getline(st, 100);
    chuyenKyTuDauCuaTuThanhChuHoa(st);
    cout << "Chuoi sau khi chuyen ky tu dau moi tu thanh chu hoa: " << st << endl;

    return 0;
}
