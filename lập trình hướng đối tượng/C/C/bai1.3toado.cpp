#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//  bai 1.3
void nhap(FILE *f, float *x, float *y, int n);
void xuat( float *x, float *y, int n);
void xuatfile( FILE *f1,float *x, float *y, int n);
void khoangcach(float *x, float *y, int n);
void filekhoangcach(FILE *f1,float *x, float *y, int n);
void doanainhat(float *x, float *y, int n);
void filedoanainhat(FILE *f1,float *x, float *y, int n);

int main () {
	FILE *f,*f1;
	f = fopen( "toado.txt", "r");
	float *x,*y; 
	int n;
	fscanf(f,"%d\n",&n);
	x = (float *)malloc((n+1) *sizeof(int ));
	y = (float *)malloc((n+1) *sizeof(int ));
	nhap(f, x, y,n);
	fclose(f);
	xuat( x, y, n);
	f1=fopen ("xuattoado.txt","w");
	xuatfile( f1,x,y,n);
	khoangcach(x, y, n);
	filekhoangcach(f1,x,y,n);
	doanainhat(x, y,n);
	filedoanainhat(f1,x,y,n);
	fclose(f1);
	free(x);
	free(y);	
}
void nhap(FILE *f, float *x, float *y, int n){
	for (int i =0;i<n;i++){
		fscanf ( f, "(%f,%f)\n", &x[i],&y[i]);
	}	
}
void xuat( float *x, float *y, int n){
	printf ( "ma tran cua nhap la :\n");
	printf ( "%d\n",n);
	for (int i =0;i<n;i++){
		printf ("(%.0f,%.0f)\n", x[i],y[i]);
	}
}
void xuatfile( FILE *f1,float *x, float *y, int n){
	fprintf ( f1,"ma tran cua nhap la : \n");
	fprintf ( f1,"%d\n",n);
	for (int i =0;i<n;i++){
		fprintf (f1,"(%.0f,%.0f)\n", x[i],y[i]);
	}
}
void khoangcach(float *x, float *y, int n){
	float d;
	printf (" khoang cach cac diem den truc hoanh la :\n");
	for (int i =0;i<n;i++){
		d = abs(y[i]);
		printf ("d((x[%d],y[%d])) = %.3f\n", i,i,d);
	}
}
void filekhoangcach(FILE *f1,float *x, float *y, int n){
	float d;
	fprintf (f1," khoang cach cac diem den truc hoanh la :\n");
	for (int i =0;i<n;i++){
		d = abs(y[i]);
		fprintf (f1,"d((x[%d],y[%d])) = %.1f\n", i,i,d);
	}
}
void doanainhat(float *x, float *y, int n){
	float s[50][50];
	float max = s[0][0];
	int a,b;
	for (int i =0;i<n-1;i++){
		for (int j =i+1;j<n;j++){
			s[i][j] = sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
		}
	}
	for (int i =0;i<n-1;i++){
		for (int j =i+1;j<n;j++){
			if (s[i][j] > max){
				max = s[i][j];
				a=i; b=j;
			}
		}
	}
	printf ( "\n do dai doan thang dai nhat giua n diem la x[%d]y[%d] --> x[%d]y[%d] = %.f", a,a,b,b,max);
}
void filedoanainhat(FILE *f1,float *x, float *y, int n){
	float s[50][50];
	float max = s[0][0];
	int a,b;
	for (int i =0;i<n-1;i++){
		for (int j =i+1;j<n;j++){
			s[i][j] = sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
		}
	}
	for (int i =0;i<n-1;i++){
		for (int j =i+1;j<n;j++){
			if (s[i][j] > max){
				max = s[i][j];
				a=i; b=j;
			}
		}
	}
	fprintf (f1, "\n do dai doan thang dai nhat giua n diem la x[%d]y[%d] --> x[%d]y[%d] = %.f", a,a,b,b,max);
}
