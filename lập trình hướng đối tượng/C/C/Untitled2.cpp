#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
void nhap(FILE *f, int n, int *a){
	for(int i=0;i<n;i++){
		fscanf(f,"%d\n",a+i);
	}
}
void xuat( int n, int *a){
	printf ("%d\n",n);
	for(int i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
}
int main(){
	FILE *f;
	f = fopen ("nhap.txt","r");
	int *a;int n;
	fscanf(f,"%d\n",&n);
	a = (int *)malloc((n+1) *sizeof(int ));
	nhap(f,n,a);
	xuat( n, a);
	fclose(f);
}
