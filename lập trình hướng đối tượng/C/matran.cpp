#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE*f;
	f=fopen("input.txt","r");
	int m,n,i,j,**a;
	fscanf(f,"%d",m,n);
	a=(int**)calloc(m,sizeof(int*));
	for(i=1;i<=m;i++) a[i]=(int*)calloc(n,sizeof(int));
	for (i=1;i<=m;i++)
	for(j=1;j<=n;j++)
	 fscanf(f,"%d",a[i][j])
}
