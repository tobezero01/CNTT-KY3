#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//  bai 2
void nhap(FILE *f, float *a, int m, int n,int N);
void xuat(float *a, int m, int n,int N)	;
void xuattep(FILE *f1,float *a, int m, int n,int N);
float trungbc(float *a, int m, int n,int N );
float timamdau(float *a, int m, int n,int N);
void ammax(float *a, int m, int n,int N);
void ammaxfile(FILE *f1,float *a, int m, int n,int N);
void tichhangvamin(float *a, int m, int n,int N);
void filetichhangvamin(FILE *f1,float *a, int m, int n,int N);
int countduong(float *a, int m, int n,int N);

int main() {
	FILE *f, *f1;
	f= fopen ("matran.txt","r");
	int m, n;
	float **a;
	fscanf(f,"%d %d\n",&m,&n);
	a = (float **)malloc(m *sizeof(int *));
	for (int j=0 ; j<n ; j++){
		a[j]= (float *)malloc (n *sizeof(int));
	}
	nhap(f, *a, m, n, 50); 
	fclose(f);
	xuat(*a,m,n, 50);
	f1= fopen ("xuatmatran.txt","w");
	xuattep(f1,*a,m,n, 50);
	printf ( "trung binh cong cac so am cua ma tran la %0.5f",trungbc(*a, m,n,50) );
	fprintf (f1, "trung binh cong cac so am cua ma tran la %0.5f",trungbc(*a, m,n,50) );
	timamdau(*a,m,n,50);
	ammax( *a,m, n,50);
	fprintf (f1,"\nphan tu am dau tien cua ma tran la %f",timamdau(*a,m,n,50));
	ammaxfile(f1,*a, m,n,50);
	tichhangvamin(*a, m,  n, 50);
	filetichhangvamin(f1, *a, m,  n,50);
	printf ("so phan tu duong cua ma tran la %d",countduong(*a,m, n,50));
	fprintf (f1,"so phan tu duong cua ma tran la %d",countduong(*a,m, n,50));
	fclose(f1);
	free (a);
}	
void nhap(FILE *f, float *a, int m, int n,int N){
	for (int i=0; i<m;i++){
		for (int j=0 ; j<n ; j++){
			fscanf (f,"%f  ", a+i*N+j);
		}
	}
}
void xuat(float *a, int m, int n,int N){
	printf ("ma tran vua nhap la :\n");
	printf ("%d %d\n",m,n);
	for (int i=0; i<m;i++){
		for (int j=0 ; j<n ; j++){
			printf ("%1.f ", *(a+i*N+j));
		}
		printf ("\n");
	}
}
void xuattep(FILE *f1,float *a, int m, int n,int N){
	fprintf (f1,"%d %d\n",m,n);
	for (int i=0; i<m;i++){
		for (int j=0 ; j<n ; j++){
			fprintf (f1,"%1.f ", *(a+i*N+j));
		}
		fprintf (f1,"\n");
	}
}	
float trungbc(float *a, int m, int n,int N ){
	float sum = 0;
	int count = 0;
	for (int i=0; i<m;i++){
		for (int j=0 ; j<n ; j++){
			if ( *(a+i*N+j) < 0){
				sum +=*(a+i*N+j);
				count ++;
			}
		}
	}return sum/count;
}
float timamdau(float *a, int m, int n,int N){
	for (int i=0; i<m;i++){
		for (int j=0 ; j<n ; j++){
			if ( *(a+i*N+j) < 0) return *(a+i*N+j);
		}
	}
}
void ammax(float *a, int m, int n,int N){
	float max = timamdau(a,m,n,50);
	int luui,luuj;
	for (int i=0; i<m;i++){
		for (int j=0 ; j<n ; j++){
			if ( *(a+i*N+j) < 0 && *(a+i*N+j) > max){
				max = *(a+i*N+j); luui = i; luuj = j;
			}
		}
	}
	printf ("\n gia tri am lon nhat la a[%d][%d] = %.1f",luui,luuj,max);
}
void ammaxfile(FILE *f1,float *a, int m, int n,int N){
	float max = timamdau(a,m,n,50);
	int luui,luuj;
	for (int i=0; i<m;i++){
		for (int j=0 ; j<n ; j++){
			if ( *(a+i*N+j) < 0 && *(a+i*N+j) > max){
				max = *(a+i*N+j); luui = i; luuj = j;
			}
		}
	}
	fprintf (f1,"\n gia tri am lon nhat la a[%d][%d] = %.1f",luui,luuj,max);
}
void tichhangvamin(float *a, int m, int n,int N){
	int count = 0;
	float t[50];
	for (int i=0; i<m;i++){
		t[i] = 1;
		for (int j=0 ; j<n ; j++){
			t[i] *= *(a+i*N+j);
		}
		printf ("\ntich hang thu %d la %.1f ",count, t[i]);
		count ++;
	}
	float min = t[0]; int k;
	for (int i=0; i<m;i++){
		for (int j=0 ; j<n ; j++){
			if ( min > t[i]){
				min =  t[i];
				k=i;
			}
		}
	}
	for (int i=0; i<m;i++){
	    if ( min == t[i]) printf("\ntich min la cua hang thu %d = %.1f\n", k, min);
	}
}
void filetichhangvamin(FILE *f1,float *a, int m, int n,int N){
	int count = 0;
	float t[50];
	for (int i=0; i<m;i++){
		t[i] = 1;
		for (int j=0 ; j<n ; j++){
			t[i] *= *(a+i*N+j);
		}
		fprintf (f1,"\ntich hang thu %d la %.1f ",count, t[i]);
		count ++;
	}
	float min = t[0]; int k;
	for (int i=0; i<m;i++){
		for (int j=0 ; j<n ; j++){
			if ( min > t[i]){
				min =  t[i];
				k=i;
			}
		}
	}
	for (int i=0; i<m;i++){
	    if ( min == t[i]) fprintf(f1,"\ntich min la cua hang thu %d = %.1f\n", k, min);
	}
}
int countduong(float *a, int m, int n,int N){
	int count = 0;
	for (int i=0; i<m;i++){
		for (int j=0 ; j<n ; j++){
			if (*(a+i*N+j) > 0 ) count ++;
		}
	}
	return count;
}
