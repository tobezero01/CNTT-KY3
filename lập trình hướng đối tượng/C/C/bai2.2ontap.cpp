#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct sach {
	char tens[30];
	char nxb[30];
	int gia;
};
typedef sach s;

void read(FILE *f, s *a,int n);
void xuat(s *a,int n);
void dem(s *a,int n, char *ten);
void xuatfile(FILE *f1,s *a,int n);
void swap(s *a, int n);

int main (){
	FILE *f,*f1;char ten[30]; 
	int n;
	f= fopen ("input.txt", "r");
	sach *a;
	fscanf(f,"%d\n",&n);
	a= (sach*)malloc((n+1)*sizeof(sach));
	read(f,a,n);
	xuat(a,n);
	fclose(f);
    printf("\n");
	fflush(stdin); gets(ten);
	dem(a,n, ten);
	f1=fopen("output.txt","w");
	xuatfile(f1,a, n);
	printf ("\n\n");
	swap(a,  n);
	xuat(a,n);
	fclose(f1);
	free(a);
}
void read(FILE *f, s *a,int n){
	for (int i=0; i<n; i++){
		fscanf(f,"%[^\n]\n", a[i].tens);fflush(stdin);
		fscanf(f,"%[^\n]\n", a[i].nxb);
		fscanf(f,"%d\n", &a[i].gia);
	}
}
void xuat(s *a,int n){
	printf("%d\n",n);
	for (int i=0; i<n; i++){
		printf("%s\n", a[i].tens);fflush(stdin);
        printf("%s\n", a[i].nxb);
        printf("%d\n", a[i].gia);
    }
}
void dem(s *a,int n,char* ten){
	int dem = 0;
    for (int i=0; i<n; i++){
    	if ( strcmp(a[i].nxb , ten ) == 0) {
		dem+=1 ;
		}
    }
    printf ("\nso cuon sach co nha xuat ban ten %s la %d ",ten,dem);
}
void xuatfile(FILE *f1,s *a,int n){
	fprintf(f1,"%d\n",n);
	for (int i=0; i<n; i++){
		fprintf(f1,"%s\n", a[i].tens);fflush(stdin);
        fprintf(f1,"%s\n", a[i].nxb);
        fprintf(f1,"%d\n", a[i].gia);
    }
}
void swap(s *a, int n) {
	s k;
    for (int i=0; i<n-1; i++){
    	for (int j=i+1; j<n; j++){
    		if (a[i].gia < a[j].gia){
    			k = a[i];
    			a[i] = a[j];
    			a[j] = k;
    		}
    	}
    }
}
