#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// a. Xuất các số cực tiểu
void xuatSoCucTieu(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size() - 1; ++i) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// b. Xóa phần tử tại vị trí k
void xoaPhanTu(vector<int>& arr, size_t k) {
    if (k >= arr.size()) {
        throw out_of_range("Vi tri k vuot qua kich thuoc mang.");
    }
    arr.erase(arr.begin() + k);
}

// c. Thêm phần tử x tại vị trí k
void themPhanTu(vector<int>& arr, int x, size_t k) {
    if (k > arr.size()) {
        throw out_of_range("Vi tri k vuot qua kich thuoc mang.");
    }
    arr.insert(arr.begin() + k, x);
}

// d. Chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng
void chuyenChanLenDau(vector<int>& arr) {
    vector<int> chan, le;
    for (int num : arr) {
        if (num % 2 == 0) {
            chan.push_back(num);
        }
        else {
            le.push_back(num);
        }
    }
    arr.clear();
    arr.insert(arr.end(), chan.begin(), chan.end());
    arr.insert(arr.end(), le.begin(), le.end());
}

// e. Kiểm tra mảng có chứa chẵn lẻ xen kẽ không?
bool kiemTraChanLeXenKe(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if ((arr[i] % 2) == (arr[i - 1] % 2)) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8 };

    cout << "Cac so cuc tieu: ";
    xuatSoCucTieu(arr);

    try {
        xoaPhanTu(arr, 2);
        cout << "Mang sau khi xoa phan tu tai vi tri 2: ";
        for (int num : arr) cout << num << " ";
        cout << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    try {
        themPhanTu(arr, 10, 2);
        cout << "Mang sau khi them phan tu 10 tai vi tri 2: ";
        for (int num : arr) cout << num << " ";
        cout << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    chuyenChanLenDau(arr);
    cout << "Mang sau khi chuyen so chan len dau: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    cout << "Mang co chua chan le xen ke khong? " << (kiemTraChanLeXenKe(arr) ? "Co" : "Khong") << endl;

    return 0;
}
