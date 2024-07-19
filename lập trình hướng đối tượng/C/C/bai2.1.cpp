#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
//2.1
struct sinhvien {
	char ht[30];
	float sd;
	char dv[30];
};
typedef sinhvien sv;

void read(FILE *f, sv *a1,int n);
void xuatfile(FILE *f1,sv *a1,int n);
void tong(FILE *f1,sv *a1,int n);
void tim(FILE *f1,sv *a1,int n);

int main (){
	FILE *f,*f1;
	f= fopen("input.txt","r");
	int n; sinhvien *a1;
	fscanf(f,"%d\n",&n);
	a1= (sinhvien*)malloc((n+1)*sizeof(sinhvien));
	read(f,a1,n);
	fclose(f);
	f1=fopen("output.txt","w");
	xuatfile(f1,a1,n);
	tong (f1,a1,n);
	tim(f1,a1,n);
	fclose(f1);
}
void read(FILE *f, sv *a1,int n){
	for (int i=0; i<n; i++){
		fscanf(f,"%[^\n]\n", a1[i].ht);fflush(stdin);
		fscanf(f,"%f\n", &a1[i].sd);
		fscanf(f,"%[^\n]\n", a1[i].dv);
	}
}
void xuatfile(FILE *f1,sv *a1,int n){
	fprintf(f1,"%d\n",n);
	for (int i=0; i<n; i++){
		fprintf(f1,"%s\n", a1[i].ht);fflush(stdin);
		fprintf(f1,"%.1f\n", a1[i].sd);
        fprintf(f1,"%s\n", a1[i].dv);
    }
}
void tong(FILE *f1,sv *a1,int n){
	float ta=0,tb=0,tc=0;
	for (int i=0; i<n; i++){
		if (strcmp(a1[i].dv, "A")==0) ta +=a1[i].sd;
		if (strcmp(a1[i].dv, "B")==0) tb +=a1[i].sd;
		if (strcmp(a1[i].dv, "C")==0) tc +=a1[i].sd;
	}
	fprintf(f1,"diem cua don vi a la %.1f",ta);
	fprintf(f1,"\ndiem cua don vi b la %.1f",tb);
	fprintf(f1,"\ndiem cua don vi c la %.1f\n",tc);
	if (ta > tb && ta>tc) fprintf ( f1,"don vi a co diem lon nhat");
	if ( tb>ta && tb>tc) fprintf ( f1,"don vi b co diem lon nhat");
	if (tc>ta&&tc>tb) fprintf ( f1,"don vi c co diem lon nhat");	
}
void tim(FILE *f1,sv *a1,int n){
	fprintf (f1,"\n3 thi sinh co diem cao nhat la \n");
	sv k;
    for (int i=0; i<n-1; i++){
    	for (int j=i+1; j<n; j++){
    		if (a1[i].sd < a1[j].sd){
    			k = a1[i];
    			a1[i] = a1[j];
    			a1[j] = k;
    		}
    	}
    }
    for (int i=0;i<3;i++){
    fprintf(f1,"%s %.1f %s \n", a1[i].ht,a1[i].sd ,a1[i].dv);}
}
