#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void doc_ma_tran_tu_file(const char *filename, int a[MAX][MAX], int *n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Khong the mo tep.\n");
        exit(1);
    }

    fscanf(file, "%d", n);
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            fscanf(file, "%d", &a[i][j]);
        }
    }
    fclose(file);
}

void xuat_ma_tran(int a[MAX][MAX], int n) {
    printf("Ma tran vua doc:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int kiem_tra_doi_xung(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

void xac_dinh_do_thi(int a[MAX][MAX], int n) {
    if (kiem_tra_doi_xung(a, n)) {
        printf("Ten: Don do thi vo huong\n");
    } else {
        printf("Ten: Don do thi co huong\n");
    }
}

int main() {
    int a[MAX][MAX];
    int n;

    doc_ma_tran_tu_file("matranbinhthuong.txt", a, &n);
    xuat_ma_tran(a, n);
    xac_dinh_do_thi(a, n);

    return 0;
}



