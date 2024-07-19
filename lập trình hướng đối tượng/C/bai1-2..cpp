#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"

void nhap(int &n,int &m,int **a,FILE *f){
	fscanf(f,"%d%d",&n,&m);
	*a=(int*)malloc(m*n*sizeof(int));
	for(int i=0;i<m*n;i++){
		fscanf(f,"%d",*a+i);
	}
}

void xuat(int n,int m,int *a){
	printf("%d %d\n",n,m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%3d",*(a+i*m+j));
		}
		printf("\n");
	}
	
}

float tbc(int n,int m,int *a){
	float s=0;
	int kt=0;
	for(int i=0;i<n*m;i++){
		
		if(a[i]<0){
			
			s=s+a[i];
			kt=kt+1;
			
		}
	}

	if(kt==0){
		return 0;
	}else return s/kt;
}

void timmax(int n,int m,int *a){
	int max;
	
	if(tbc(n,m,a)==0){
		printf("\nkhong co so am!!");
		return;
	}
	else
	{
		for(int i=0;i<n*m;i++){
			
		if(a[i]<0){
			
			max=a[i];
			
		}
	}
		for(int i=0;i<n*m;i++){
			
		if(a[i]<0){
			
			if(max<a[i]) max=a[i];
			
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
			
			if(*(a+i*m+j)==max){
				printf("\ngt am lon nhat la:%2d",max);
				printf("\nhang:%2d cot:%2d",j,i*m/2);
				return;
			}
		}
		}
	}
	}
}

int main(){
	int n,m;
	int *a;
	FILE *f;
	f=fopen("bai1-2.txt","r");
	nhap(n,m,&a,f);
	xuat(n,m,a);
	if(tbc(n,m,a)==0){
		printf("\nkhong co gia tri am !\n");
	}else{
		printf("\ngia tri tbc:%.2f",tbc(n,m,a));
	}
	timmax(n,m,a);
} 
