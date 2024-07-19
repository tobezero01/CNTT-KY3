#include <stdio.h>
#include <math.h>
// bài 3 sbt tr 129
// ma tran
void nhap( int a[] ,int n, int m){
	for(int i=0 ; i<n ; i++){
		for( int j=0 ; j<m ; j++){
			printf("a[%d][%d]=  ",i,j);
			scanf("%d",&a[i][j]);
	   }
    }
}
void xuat(int a[] ,int n, int m){
	printf ("%d x %d\n",n,m);
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=m ; j++){
			printf("%2.f ", a[i][j]);
		}
		printf("\n");
	}
}
void nhapfile(char *tenfile,int a[] ,int n, int m){
	FILE*f= fopen("matran.txt", "r");
	fscanf (f,"%d %d", &n,&m);
	for ( int i =1; i<=n; i++) {
		for ( int j =1; j<=m; j++) {
		    fscanf (f,"%f", a[i][j]); 
		}
	}  
	fclose (f);}
void xuatfile(char *tenfile,int a[] ,int n, int m){
	FILE*f= fopen("matran1.txt", "wt");
	fprintf (f,"%d %d",n,m);
	for ( int i =1; i<=n; i++) {
		for ( int j =1; j<=m; j++) {
		    fprintf (f,"%f",a[i][j] ); 
		}
	}  
	fclose (f);}
int main (){
	FILE *f;
    int m,n,i,j;
    scanf (" %d %d", &n,&m);
    int a[50][50];
    //nhap((float*)a , n ,m, 50);
    //xuat((float*)a ,n, m,50);
    nhapfile("matran.txt",a ,n, m);
	//xuatfile("matran1.txt",(float)a ,n, m,50);
	xuat(a ,n, m);
	xuatfile("matran1.txt",a ,n, m);
	xuat(a ,n, m);
	}
    
	
