#include <stdio.h>
#define MAX_SIZE 100

void inputArray(int arr[], int *size) {
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", size);
    
    printf("Nhap cac phan tu trong mang:\n");
    for (int i = 0; i < *size; i++) {
        printf("Phan tu %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void printElementAtIndex(int arr[], int size, int x) {
    if (x >= 0 && x < size) {
        printf("Gia tri phan tu thu %d la: %d\n", x, arr[x]);
    } else {
        printf("Chi so %d vuot qua gioi han mang.\n", x);
    }
}

void findMax(int arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    printf("Vi tri max: %d, gia tri max: %d\n", maxIndex, arr[maxIndex]);
}

void findMin(int arr[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    printf("Vi tri min: %d, gia tri min: %d\n", minIndex, arr[minIndex]);
}

void printOddNumbers(int arr[], int size) {
    printf("Cac so le trong mang: ");
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    printf("Tong gia tri cua cac phan tu trong mang: %d\n", sum);
}

int main() {
    int arr[MAX_SIZE];
    int size;
    int x;

    inputArray(arr, &size);

    printf("Nhap chi so x de lay phan tu: ");
    scanf("%d", &x);
    printElementAtIndex(arr, size, x);

    findMax(arr, size);
    findMin(arr, size);
    printOddNumbers(arr, size);
    sumArray(arr, size);

    return 0;
}

