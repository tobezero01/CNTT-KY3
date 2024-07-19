#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//2,5
struct oto {
	int bks;
	float tt;
	char cty[30];
};

typedef oto o;

void readfile(FILE *f, o *a,int n){
	for (int i=0;i<n;i++){
		fscanf(f,"%d\n",&a[i].bks);
		fscanf(f,"%f\n",&a[i].tt);
		fscanf(f,"%[^\n]\n",a[i].cty);fflush(stdin);
	} 
}
void xuatfile(FILE *f1,o *a, int n){
	fprintf(f1,"%d\n",n);
	for (int i=0;i<n;i++){
		fprintf(f1,"%d\n",a[i].bks);fflush(stdin);
		fprintf(f1,"%.1f\n",a[i].tt);
		fprintf(f1,"%s\n",a[i].cty);
	}
}
void count(FILE *f1,o *a, int n){
	int count=0;
	for (int i=0;i<n;i++){
		if (strcmp(a[i].cty,"B") ==0 && a[i].bks % 3 ==0){
			count ++;
		}
	}fprintf (f1, "so o to cua cong ty b co bks chia het 3 la %d",count);
}
void tim(FILE *f1,o *a,int n){
	fprintf (f1,"\n3 oto co trong tai nho nhat la \n");
	o k;
    for (int i=0; i<n-1; i++){
    	for (int j=i+1; j<n; j++){
    		if (a[i].tt > a[j].tt){
    			k = a[i];
    			a[i] = a[j];
    			a[j] = k;
    		}
    	}
    }
    for (int i=0;i<3;i++){
    fprintf(f1,"%d %.1f %s \n", a[i].bks,a[i].tt ,a[i].cty);}
}
int main (){
	FILE *f,*f1; 
	f = fopen ("oto.txt","r");
	int n;
	oto *a;
	fscanf(f,"%d\n",&n);
	a = (oto *)malloc((n+1) *sizeof(oto ));
	readfile(f,a,n);
	fclose(f);
	f1=fopen ("output.txt","w");
	xuatfile(f1,a,n);
	count(f1,a, n);
	tim(f1,a,n);
	fclose(f1);
}
