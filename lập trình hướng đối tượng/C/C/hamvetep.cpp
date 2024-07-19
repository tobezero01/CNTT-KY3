#include <stdio.h>
#include <conio.h>
#include <math.h>
void nhap(char *tenFile, int *a, int n);
void xuat(char *tenFile, int *a, int n);

main()
{   int n; int a[100];
    int i;
    FILE *f;
    nhap ( "input.txt",a,n);
	// in ra man hinh de kiem tra
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	printf("\n");
	getch();
	// xuat ra file
	xuat("output.txt", a, n);
}
void nhap(char *tenFile, int *a, int n){
	
	// mo file de doc
	FILE* f = fopen("input.txt", "r");
	if (f == NULL) printf("Khong mo duoc tap tin!");
    
	//doc du lieu
	fscanf(f, "%d", &n);

	for (int i = 1; i <= n; i++) fscanf(f, "%d", &a[i]);

	//dong file
	fclose(f);
}
void xuat(char *tenFile, int *a, int n){
	//mo file de ghi
	FILE* f = fopen("output.txt", "wt"); // wt = write (ghi) + text (dang van ban)
	//ghi du lieu ra file
	for (int i = 1; i <=n; i++)
		fprintf(f, "%d ", a[i]);
	// dong file
	fclose(f);  
}

