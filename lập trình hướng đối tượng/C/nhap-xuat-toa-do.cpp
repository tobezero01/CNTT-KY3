#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define fpf fprintf
#define fsf fscanf
#define pf printf

typedef struct
{
    int x;
	int y;	
} td;

void doc(td *a, int n, FILE *f)
{
	int i;
	for(i=0 ;i<n ;i++)
		fscanf(f,"%d %d\n" , &a[i].x , &a[i].y);
}

void print(td *a, int n, FILE *f)
{
	int i;
	for(i=0 ;i<n ;i++)
		printf("toa do: x = %d , y = %d\n" , a[i].x , a[i].y);
}

int main() {
	FILE *f;
	f=fopen("toado.txt","r");
	if(f == NULL)
		printf("Loi!");
	int n; 
	td *a;
	fscanf(f,"%d", &n);
	a=(td*)calloc(n+1, sizeof(td));
	doc(a, n, f);
	print(a, n, f);
}


