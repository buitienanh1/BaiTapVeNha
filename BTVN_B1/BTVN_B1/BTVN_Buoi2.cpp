#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define _CRT_SECURE_NO_WARNINGS

// 1. Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// 1. Liệt kê các số nguyên tố nhỏ hơn n
void listPrimesLessThanN(int n) {
    bool found = false;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
            found = true;
        }
    }
    if (!found) {
        printf("Khong co so nguyen to nao nho hon %d", n);
    }
    printf("\n");
}

// 2. Tính tổng các phần tử có chữ số đầu là chữ số lẻ
int sumOddFirstDigit(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        int firstDigit = arr[i];
        while (firstDigit >= 10) {
            firstDigit /= 10;
        }
        if (firstDigit % 2 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}

// 3. Liệt kê số lần xuất hiện của các phần tử trong mảng
void countOccurrences(int arr[], int size) {
    int* counts = (int*)calloc(100000, sizeof(int)); // Tăng kích thước bộ nhớ
    for (int i = 0; i < size; i++) {
        counts[arr[i]]++;
    }
    for (int i = 0; i < size; i++) {
        if (counts[arr[i]] > 0) {
            printf("%d xuat hien %d lan\n", arr[i], counts[arr[i]]);
            counts[arr[i]] = 0;
        }
    }
    free(counts);
}

// 4. Sắp xếp mảng có số chẵn tăng dần, số lẻ giảm dần
int compareEvenAsc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int compareOddDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

void sortEvenAscOddDesc(int arr[], int size) {
    int* evens = (int*)malloc(size * sizeof(int));
    int* odds = (int*)malloc(size * sizeof(int));
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evens[evenCount++] = arr[i];
        }
        else {
            odds[oddCount++] = arr[i];
        }
    }
    qsort(evens, evenCount, sizeof(int), compareEvenAsc);
    qsort(odds, oddCount, sizeof(int), compareOddDesc);
    int index = 0;
    for (int i = 0; i < evenCount; i++) {
        arr[index++] = evens[i];
    }
    for (int i = 0; i < oddCount; i++) {
        arr[index++] = odds[i];
    }
    free(evens);
    free(odds);
}

// 5. Tìm dãy con giảm dài nhất
void longestDecreasingSubsequence(int arr[], int size) {
    int* lis = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        lis[i] = 1;
    }
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    int max = lis[0];
    for (int i = 1; i < size; i++) {
        if (max < lis[i]) {
            max = lis[i];
        }
    }
    printf("Do dai day con giam dai nhat: %d\n", max);
    free(lis);
}

// 6. Tìm số nhỏ thứ 2 trong mảng
void findSecondSmallest(int arr[], int size) {
    int first, second;
    if (size < 2) {
        printf("Khong the tim so nho thu 2 trong mang\n");
        return;
    }
    first = second = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        }
        else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }
    if (second == INT_MAX) {
        printf("Khong co so nho thu 2 trong mang\n");
    }
    else {
        printf("So nho thu 2 trong mang: %d\n", second);
    }
}

// 7. Tìm các phần tử chứa chữ số của x
bool containsDigits(int num, int x) {
    char numStr[20], xStr[20];
    sprintf_s(numStr, "%d", num);
    sprintf_s(xStr, "%d", x);
    for (char* p = xStr; *p != '\0'; p++) {
        if (strchr(numStr, *p) == NULL) {
            return false;
        }
    }
    return true;
}

void findElementsContainingDigits(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (containsDigits(arr[i], x)) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

// 8. Sắp xếp mảng chẵn tăng dần, lẻ giữ nguyên vị trí
void sortEvenKeepOddPosition(int arr[], int size) {
    int* evens = (int*)malloc(size * sizeof(int));
    int evenCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evens[evenCount++] = arr[i];
        }
    }
    qsort(evens, evenCount, sizeof(int), compareEvenAsc);
    evenCount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            arr[i] = evens[evenCount++];
        }
    }
    free(evens);
}

// 9. Sắp xếp mảng: số lẻ ở đầu, số chẵn ở cuối
void sortOddFirstEvenLast(int arr[], int size) {
    int* temp = (int*)malloc(size * sizeof(int));
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            temp[index++] = arr[i];
        }
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            temp[index++] = arr[i];
        }
    }
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
    free(temp);
}

// Menu
void menu() {
    int choice, n, x, size;
    printf("Nhap so phan tu cua mang: ");
    scanf_s("%d", &size);
    int* arr = (int*)malloc(size * sizeof(int));
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < size; i++) {
        scanf_s("%d", &arr[i]);
    }

    while (1) {
        printf("\nMENU:\n");
        printf("1. Liet ke cac so nguyen to nho hon n\n");
        printf("2. Tinh tong cac phan tu co chu so dau la chu so le\n");
        printf("3. Liet ke so lan xuat hien cua cac phan tu trong mang\n");
        printf("4. Sap xep mang co so chan tang dan, so le giam dan\n");
        printf("5. Tim day con giam dai nhat trong a\n");
        printf("6. Tim so nho thu 2 trong mang\n");
        printf("7. Tim cac phan tu chua chu so cua x\n");
        printf("8. Sap xep mang chan tang dan, le giu nguyen vi tri\n");
        printf("9. Sap xep mang: so le o dau, so chan o cuoi\n");
        printf("0. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap n: ");
            scanf_s("%d", &n);
            listPrimesLessThanN(n);
            break;
        case 2:
            printf("Tong cac phan tu co chu so dau la chu so le: %d\n", sumOddFirstDigit(arr, size));
            break;
        case 3:
            countOccurrences(arr, size);
            break;
        case 4:
            sortEvenAscOddDesc(arr, size);
            printf("Mang sau khi sap xep: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 5:
            longestDecreasingSubsequence(arr, size);
            break;
        case 6:
            findSecondSmallest(arr, size);
            break;
        case 7:
            printf("Nhap x: ");
            scanf_s("%d", &x);
            findElementsContainingDigits(arr, size, x);
            break;
        case 8:
            sortEvenKeepOddPosition(arr, size);
            printf("Mang sau khi sap xep: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 9:
            sortOddFirstEvenLast(arr, size);
            printf("Mang sau khi sap xep: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 0:
            free(arr);
            exit(0);
        default:
            printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
