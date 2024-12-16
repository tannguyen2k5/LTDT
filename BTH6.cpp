#include <stdio.h>
#include <stdlib.h>
#include <stack>
#define vc 999

int a[100][100], s;
int n, f, v;


void docfile() {
    FILE *f;
    f = fopen("cteuler.txt", "r");
    if (f == NULL) {
        printf("Khong co tap tin!");
        exit(0);
    } else {
        fscanf(f, "%d", &n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                fscanf(f, "%d", &a[i][j]);
    }
    fclose(f);
}


void infile() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}


void euler(int v) {
    std::stack<int> S;
    int out[50], t = 0, ke;
    S.push(v);

    while (!S.empty()) {
        int u = S.top();
        ke = 0;
        for (int i = 1; i <= n; i++) {
            if (a[u][i] != 0) {
                S.push(i);
                a[u][i] = 0; 
                a[i][u] = 0; 
                ke = 1;
                break;
            }
        }
        if (ke == 0) {
            S.pop();
            out[t] = u;
            t++;
        }
    }

    
    for (int i = t - 1; i >= 0; i--)
        printf("%d ", out[i]);
}

int main() {
    int v;
    docfile();
    infile();
    printf("Nhap dinh bat dau: ");
    scanf("%d", &v);
    euler(v);
    return 0;
}

