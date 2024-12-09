#include <stdio.h>
#include <stdlib.h>
#define vc 999

int a[30][30], s;
int n,f;
int truoc[50], tam[50];
int d[50], l[50];

void docfile(){
	FILE * f;
	f = fopen("mtk.txt", "r");
	if(f == NULL){
		printf("Khong co tap tin!");
		exit(0);
	}else
	{
		fscanf(f,"%d",&n);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			fscanf(f,"%d",&a[i][j]);
		}
		fclose(f);
	}

void infile(){
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
			printf("%d",a[i][j]);
			printf("\n");
	}
}

int vitrimin(){
	int min = vc;
	int vt;
	for(int i=1; i<=n; i++)
	{
		if(min > l[i] && d[i]==0)
		{
			min = l[i];
			vt = i;
		}
	}
	return vt;
}

void khoitao(int s){
	for(int i=1;i<=n;i++)
	{
	l[i] = vc;
	d[i] = 0;
	}
	l[s] = 0;	
}

void capnhat(int vt)
{
	for(int i=1; i<=n; i++){
		if(a[vt][i]!=0 && d[i]==0)
		if(l[i] > l[vt] + a[vt][i])
		l[i] = l[vt] + a[vt][i];
	}
}

void timduong(int f){
	printf("DO DAI DDNN TU DINH %d la: %d \n", s,f,l[f]);
	tam[0]=f;
	int i=1;
	while(truoc[f]!=0){
		tam[i]= truoc[f];
		i++;
		f=truoc[f];
	}
}

int main()
{
	docfile();
	infile();
	printf("Nhap dinh bat dau: ");
	scanf("%d",&s);
	khoitao(s);
	int vt = vitrimin(); 
	capnhat(vt);
	d[vt] = 1;
	for(int i=1;i<=n;i++){
		printf("%d", l[i]);
	}
	printf("Nhap dinh ket thuc:");
	scanf("%d", &f);
	timduong(f);
	for(int i=n;i>=0;i--){
		printf("%d", tam[i]);
	}
}
