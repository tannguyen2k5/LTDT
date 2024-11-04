#include <stdio.h>

#define MAX 100

void inputMatrix(int matrix[MAX][MAX], int n) {
    printf("Nhap ma tran %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printRowMax(int matrix[MAX][MAX], int n, int x) {
    int max = matrix[x][0];
    for (int j = 1; j < n; j++) {
        if (matrix[x][j] > max) {
            max = matrix[x][j];
        }
    }
    printf("Phan tu lon nhat tren hang %d: %d\n", x, max);
}

void printColMin(int matrix[MAX][MAX], int n, int y) {
    int min = matrix[0][y];
    for (int i = 1; i < n; i++) {
        if (matrix[i][y] < min) {
            min = matrix[i][y];
        }
    }
    printf("Phan tu nho nhat tren cot %d: %d\n", y, min);
}

void printRowSum(int matrix[MAX][MAX], int n, int k) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += matrix[k][j];
    }
    printf("Tong cac phan tu tren hang %d: %d\n", k, sum);
}

void printColSum(int matrix[MAX][MAX], int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][m];
    }
    printf("Tong cac phan tu tren cot %d: %d\n", m, sum);
}

void printEvenSum(int matrix[MAX][MAX], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] % 2 == 0) {
                sum += matrix[i][j];
            }
        }
    }
    printf("Tong cac phan tu co gia tri chan: %d\n", sum);
}

void checkDiagonalZero(int matrix[MAX][MAX], int n) {
    int allZero = 1; // Gi? s? toàn b? là 0
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] != 0) {
            allZero = 0; // Có ph?n t? khác 0
            break;
        }
    }
    if (allZero) {
        printf("Duong cheo bang 0\n");
    } else {
        printf("Duong cheo khac 0\n");
    }
}

void checkAllLessThanOrEqualOne(int matrix[MAX][MAX], int n) {
    int allLessThanOrEqualOne = 1; // Gi? s? t?t c? d?u <= 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > 1) {
                allLessThanOrEqualOne = 0; // Có ph?n t? l?n hon 1
                break;
            }
        }
    }
    if (allLessThanOrEqualOne) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

void checkSymmetric(int matrix[MAX][MAX], int n) {
    int symmetric = 1; // Gi? s? ma tr?n d?i x?ng
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = 0; // Không d?i x?ng
                break;
            }
        }
    }
    if (symmetric) {
        printf("DOI XUNG\n");
    } else {
        printf("KHONG DOI XUNG\n");
    }
}

int main() {
    int n, matrix[MAX][MAX];

    printf("Nhap kich thuoc ma tran (n): ");
    scanf("%d", &n);

    inputMatrix(matrix, n);

    int x, y, k, m;
    printf("Nhap x (hang): ");
    scanf("%d", &x);
    printRowMax(matrix, n, x);

    printf("Nhap y (cot): ");
    scanf("%d", &y);
    printColMin(matrix, n, y);

    printf("Nhap k (hang): ");
    scanf("%d", &k);
    printRowSum(matrix, n, k);

    printf("Nhap m (cot): ");
    scanf("%d", &m);
    printColSum(matrix, n, m);

    printEvenSum(matrix, n);
    checkDiagonalZero(matrix, n);
    checkAllLessThanOrEqualOne(matrix, n);
    checkSymmetric(matrix, n);

    return 0;
}

