#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void nhap(int n,int m, float *a, float *b,FILE *f)
{
	int i;
    for(i=0;i<=n;i++) fscanf(f,"%f",a+i);
	for(i=0;i<=m;i++) fscanf(f,"%f",b+i);
}
float TinhDT(int n, float *a, float d1)
{
	int i;
	float P=0;
		for(i=0;i<=n;i++) 
		
	
		P=P+a[i]*pow(d1,i);
return P;
}
int main()
{
	FILE *f;
	f=fopen("input.txt","r");
	int i,n,m;
	float *a,*b,d1,d2;
	float  Q,P;
	fscanf(f,"%d",&n);
	fscanf(f,"%d",&m);
	a=(float*)malloc((n+1)*sizeof(int));
	b=(float*)calloc(m+1,sizeof(int));
	
     nhap(n,m,a,b,f);
     fclose(f);
	scanf("%f%f",&d1,&d2);
	f=fopen("output.txt","w");
	printf("P(d1)/Q(d2) = %.2f",TinhDT(n,a,d1)/TinhDT(m,b,d2));
	fprintf(f,"%.2f",TinhDT(n,a,d1)/TinhDT(m,b,d2));
	fclose(f);
}
