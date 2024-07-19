#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char ht[35];
	float sd;
	char dv;
}sinhvien;
void nhap(FILE *f, int n, sinhvien *sv)
{	int i;
	for (i=0;i<n;i++){
		fscanf(f,"%[^\n]\n",&sv[i].ht);
		fscanf(f,"%f\n",&sv[i].sd);
		fscanf(f,"%c\n",&sv[i].dv);
	}
}
void xuat(sinhvien *sv, int n)
{
	for (int i=0;i<n;i++)
	{	
		printf("\n%-25s | %.1f | %c",sv[i].ht,sv[i].sd,sv[i].dv);
	}		
}
float max(float a, float b, float c){
	float max=(a>b)?a:b;
	max=(max>c)?max:c;
	return max;
}
void tong(sinhvien *sv, int n, float *a){
	for (int i=0;i<n;i++)
	{
		if (sv[i].dv=='A') a[0]+=sv[i].sd;
		if (sv[i].dv=='B') a[1]+=sv[i].sd;
		if (sv[i].dv=='C') a[2]+=sv[i].sd;
	}	
}
char find(sinhvien *sv, int n, float *a, float *max1){
	*max1=max(a[0],a[1],a[2]);
	int vt=0;
	char donvi[4]={'A','B','C'};
	for (int i=0;i<3;i++)
		if ((*max1)==a[i]) vt=i;
	return donvi[vt];
}
void swap(sinhvien *s1, sinhvien *s2){
	sinhvien c;
	c=*s1;
	*s1=*s2;
	*s2=c;
}
void sapxepgiam(sinhvien *sv, int n)
{
	int i,j,k;
	for (i=0;i<n;i++){
		k=i;
		for (j=i+1;j<n;j++){
			if (sv[j].sd > sv[k].sd ){
				k=j;	
			}
		}
		swap(&sv[k],&sv[i]);
	}
}
void in_kq(FILE *f, sinhvien *sv, int n, float *a, float *max1, char donvi){
	f=fopen("ketqua.txt","w");
	fprintf(f,"A: %.2f | B: %.2f | C: %.2f\n",a[0],a[1],a[2]);
	fprintf(f,"Don vi co tong diem lon nhat: %c",donvi);
	for (int i=0;i<n;i++){
		fprintf(f,"\n%-25s | %.1f | %c",sv[i].ht,sv[i].sd,sv[i].dv);
	}
}

int main(){
	FILE *f;
	if((f=fopen("input21.txt","r"))==NULL)
	{
		printf("Error!");
//		getch();
		exit(1);
	}
	sinhvien *sv;
	int n;
	fscanf(f,"%d\n",&n);
//	printf("%d",n);
	sv=(sinhvien*)calloc(n,sizeof(sinhvien));
	nhap(f,n,sv);
//	xuat(sv,n);
	float *a,*maxsd;
	a=(float*)calloc(3,sizeof(float));
	maxsd=(float*)calloc(1,sizeof(float));
	tong(sv,n,a);
	for (int i=0;i<3;i++){
		printf("%.2f ",a[i]);
	}
	char c=find(sv,n,a,maxsd);
	printf("\nDon vi co tong diem lon nhat: %c",c);
	printf("\n");
	sapxepgiam(sv,n);
	printf("3 thi sinh co diem cao nhat: \n");
	for (int i=0;i<3;i++){
		printf("\n%s\t | %.1f | %c",sv[i].ht,sv[i].sd,sv[i].dv);
	}

	in_kq(f,sv,n,a,maxsd,c);
	fclose(f);
	free(sv); free(a); free(maxsd);
}
