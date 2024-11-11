#include <stdio.h>
#include <stdlib.h>
int a[10][10],n;
void docfile(){
	FILE * f;
	f= fopen("matranke.txt","r");
	if(f == NULL)
	{
		printf("K co tap tin !");
		exit(0);
	}else 
	{
		fscanf(f,"%d", &n);
		for(int i=1; i<=n; i++)
		for(int j=1; j<=n;j++){
			fscanf(f,"%d", &a[i][j]);
		}
	}
	fclose(f);
}
void infile(){
	for(int i=1;i<=n;i++){
		for(int j=1; j<=n;j++)
		printf("%d",a[i][j]);
		printf("\n");
	}
}
int checkSymmetric() {
    int symmetric = 1; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = 0; 
                break;
            }
        }
    }
    return Symmetric;
}
int tinhbac(int x){
	int bac = 0;
	for(int j=1;j<=n;j++)
	sum = sum
}
