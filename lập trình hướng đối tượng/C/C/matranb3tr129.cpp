#include <stdio.h>
#include <stdlib.h>
// bài 3 sbt tr 129
// ma tran
void nhap( float *a ,int n, int m,int N){
	for(int i=0 ; i<n ; i++){
		for( int j=0 ; j<m ; j++){
			printf("a[%d][%d]=  ",i,j);
			scanf("%f ",a + i*N + j);
	   }
    }
}
void xuat(float *a ,int n, int m, int N){
	printf ("%d x %d\n",n,m);
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=m ; j++){
			printf("%f ", *(a + i*N + j));
		}
		printf("\n");
	}
}
void nhapfile(char *tenfile,float *a ,int n, int m, int N){
	FILE*f= fopen("matran.txt", "r");
	fscanf (f,"%d %d", &n,&m);
	for ( int i =1; i<=n; i++) {
		for ( int j =1; j<=m; j++) {
		    fscanf (f,"%f ", *(a + i*N + j)); 
		}
	}  
	fclose (f);}
void xuatfile(char *tenfile,float *a ,int n, int m, int N){
	FILE*f= fopen("matran1.txt", "wt");
	fprintf (f,"%d %d",n,m);
	for ( int i =1; i<=n; i++) {
		for ( int j =1; j<=m; j++) {
		    fprintf (f,"%f ", *(a + i*N + j)); 
		}
	}  
	fclose (f);}
void ghinhiphan (char *tenfile,float *a ,int n, int m){
	FILE *fp;
	if ((fp = fopen("matran2.txt","wb"))== NULL) printf(" khong mo dc file \n"); exit(1);
	for ( int i =1; i<=n; i++) {
		for ( int j =1; j<=m; j++) {
	        fwrite (&a, sizeof(float),1,fp);
		}
	}fclose (fp);	
}
void docnhiphan (char *tenfile,float *a ,int n, int m){
	FILE *fp;
	if ((fp = fopen("matran3.txt","wb"))== NULL) printf(" khong mo dc file \n"); exit(1);
	for ( int i =1; i<=n; i++) {
		for ( int j =1; j<=m; j++) {
	        fread (&a, sizeof(float),1,fp);
		}
	}fclose (fp);	
}
int main (){
	FILE *f; FILE *fp;
    int m,n,i,j;
    scanf ("%d%d", &n,&m);
    float a[50][50];
    //nhap((float*)a , n ,m, 50);
    //xuat((float*)a ,n, m,50);
    nhapfile("matran.txt",(float*)a ,n, m,50);
	//xuatfile("matran1.txt",(float*)a ,n, m,50);
	xuat((float*)a ,n, m,50);
	xuatfile("matran1.txt",(float*)a ,n, m,50);
	xuat((float*)a ,n, m,50);
	ghinhiphan ("matran2.txt",(float*)a ,n, m);
	docnhiphan ("matran3.txt",(float*)a ,n, m);
	}
    
	
