#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void nhap(FILE *f, int n , int m, float *a, float *b);
float tinh(int n, float *a, int d1);	
void Hieu(float*a,float *b,int n,float *c, int m);
int main(){
	FILE*f; 
	float *a,*b, *c;float p,q;
	int n,m, d1,d2;
	f= fopen("input.txt", "r");
	fscanf(f,"%d %d", &n,&m);
	// cap phat bo nho
	a=(float*)malloc((n+1)*sizeof(int));
	b=(float*)calloc(m+1,sizeof(int));
	nhap(f,n,m,a,b);
	fclose(f);
	scanf ("%d%d",&d1,&d2);
	f=fopen("output.txt","w");
	printf ( "px / qx = %f",tinh(n,a,d1)/tinh(m,b,d2));
	fprintf (f, "px / qx = %f",tinh(n,a,d1)/tinh(m,b,d2));
	fclose(f);
	Hieu(a,b,n,c,m);
}
void nhap(FILE *f, int n , int m, float *a, float *b){
	for (int i=0;i<=n; i++) fscanf(f,"%f", a+i);
	for (int i =0;i<=m;i++) fscanf(f,"%f" , b+i);
}
float tinh(int n, float *a, int d1){
	float p =0;
	for(int i=0;i<=n;i++) {
		p=p+a[i]*pow(d1,i);
	}
return p;
}
void Hieu(float*a,float *b,int n,float *c, int m)
{   int k,i;
    if(n>m) { 
	   k=n;
	   for(i=0;i<=m;i++){
	      c[i]=a[i]-b[i];}
	  
	   for(i=m+1;i<=n;i++) c[i]=a[i];
    }else{
	   k=m;
	   for(i=0;i<=n;i++){
	      c[i]=b[i]-a[i];}
	   for(i=n+1;i<=m;i++) c[i]=-b[i];
       } 
       for(i =0 ;i<= k;i++){
	   printf ( " %d " , c[i]);}}
	
	
	
	
