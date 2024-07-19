#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//  bai 1.4 hinh chu nhat
void nhap(FILE *f, float *x, float *y, int n);
void xuat( float *x, float *y, int n);
void xuatfile(FILE *f1, float *x, float *y, int n);
float dientichtb(float *x, float *y, int n);
void timsmax(float *x, float *y, int n);
void filetimsmax(FILE *f1,float *x, float *y, int n);

int main () {
	FILE *f,*f1;
	f = fopen( "chunhat.txt", "r");
	float *x,*y; int n;
	fscanf(f,"%d\n",&n);
	x = (float *)malloc((n+1) *sizeof(int ));
	y = (float *)malloc((n+1) *sizeof(int ));
	nhap(f, x, y,n);
	fclose(f);
	f1 = fopen( "xuatchunhat.txt", "w");
	xuat( x, y, n);
	xuatfile(f1,x,y,n);
	printf ("\ndien tich trung binh cua cac hcn la %.3f",dientichtb(x, y, n));
	fprintf(f1,"\ndien tich trung binh cua cac hcn la %.3f",dientichtb(x, y, n));
	timsmax(x, y, n);
	filetimsmax(f1,x,y,n);
	fclose(f1);
	free(x);
	free(y);
}
void nhap(FILE *f, float *x, float *y, int n){
	for (int i =0;i<n;i++){
		fscanf ( f, "%f,%f\n", &x[i],&y[i]);
	}	
}
void xuat( float *x, float *y, int n){
	printf ( "cac hinh chu nhat vua nhap la :\n");
	printf ( "%d\n",n);
	for (int i =0;i<n;i++){
		printf ("%.1f,%.1f\n", x[i],y[i]);
	}
}
void xuatfile(FILE *f1, float *x, float *y, int n){
	fprintf (f1, "cac hinh chu nhat vua nhap la :\n");
	fprintf (f1, "%d\n",n);
	for (int i =0;i<n;i++){
		fprintf (f1,"%.1f,%.1f\n", x[i],y[i]);
	}
}
float dientichtb(float *x, float *y, int n){
	float s= 0;
	for (int i =0;i<n;i++){
		s += x[i]*y[i];
	}	
	return s/n;
}
void timsmax(float *x, float *y, int n) {
	float max = x[0]*y[0];
	int a;
	float b,c;
	for (int i =0;i<n;i++){
		if ( x[i]*y[i] > max  ) {
			max = x[i]*y[i];
			a = i; 
			b = x[i]; 
			c = y[i];
		}
	}
	printf ("\n\nhcn co dien tich max la hing thu %d co kich thuoc %.1f,%.1f la %.2f ", a,b,c,max);
}
void filetimsmax(FILE *f1,float *x, float *y, int n) {
	float max = x[0]*y[0];
	int a;
	float b,c;
	for (int i =0;i<n;i++){
		if ( x[i]*y[i] > max  ) {
			max = x[i]*y[i];
			a = i; 
			b = x[i]; 
			c = y[i];
		}
	}
	fprintf (f1,"\n\nhcn co dien tich max la hinh thu %d co kich thuoc %.1f,%.1f la %.2f ", a,b,c,max);
}
			
