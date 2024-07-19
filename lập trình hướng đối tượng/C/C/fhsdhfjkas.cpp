#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
void nhap(FILE *f, int n,int m ,float *a,int N){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		fscanf(f,"%f ",a+i*N+j);
		}
	}
}
void xuat( int n,int m ,float *a,int N){
	printf ("%d\n",n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		    printf("%.0f  ",*(a+i*N+j));
		}printf("\n");
	}
}
void tbc(int n,int m ,float *a,int N){
	float t=0;
	float d=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if (*(a+i*N+j)<0) {
				t+=*(a+i*N+j); d++;
			}
		}
	}
	printf("trung binh cong so am la %f",t/d);
}
int main(){
	FILE *f;
	f = fopen ("nhap.txt","r");
	float **a;int n,m;
	fscanf(f,"%d %d\n",&m,&n);
	a = (float **)malloc((n+1) *sizeof(int *));
	for(int j=0;j<n;j++){
		a[j] = (float *)malloc((m+1) *sizeof(int ));
	}
	nhap(f,n,m ,*a,50);
	xuat(n,m ,*a,50);
	tbc(n,m ,*a,50);
}
	
