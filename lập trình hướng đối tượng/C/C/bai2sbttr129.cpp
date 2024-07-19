#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 #include<string.h>
 // bai 2 trang 129 laptrinhnangcao
struct hanghoa {
	char tenhang[30];
	int soluong;
	char loaihang[30];
};

typedef hanghoa HH;
void nhap(HH a[], int n){
   for(int i = 1; i<= n; ++i){
    printf("\nNhap HH thu %d:", i);
    printf("\nNhap ten hang : "); fflush(stdin); gets(a[i].tenhang);
    printf("Nhap loai hang: "); gets(a[i].loaihang);
    printf("Nhap so luong hang: "); scanf("%d", &a[i].soluong);
	}
}
void xuat(char *tenFile,HH a[], int n){
	FILE* f = fopen("hanghoa.txt", "wt");
	for(int i = 1;i <= n;i++){
		struct hanghoa HH = a[i];
		fprintf(f,"\nNhap HH thu %d:", i);
        fprintf(f,"\nten hang : %s", a[i].tenhang);fflush(stdin);
        fprintf(f,"\nloai hang : %s", a[i].loaihang);
        fprintf(f,"\nso luong hang : %d", a[i].soluong);
    }fclose (f);
}

void xuatN( HH a[], int n){
    for(int i = 1;i <= n;i++){
    	printf("\nhang hoa thu %d:", i);
        printf("\nten hang : %s", a[i].tenhang);fflush(stdin);
        printf("\nloai hang : %s", a[i].loaihang);
        printf("\nso luong hang : %d", a[i].soluong);;
    } 
}
void timhanghoa(char *ten,HH a[], int n){
	int found = 0;
	printf (" ten hang hoa can tim la ");
    fflush(stdin); gets(ten);
    for(int i=1; i<=n; ++i){
        if(strcmp(a[i].tenhang,ten)==0) {
           xuatN(a,n);
           found = 1;
        }
        if ( found == 0) printf ( " khong tim thay hang hoa");}
}
int main (){
	int n; char ten[30];
	do{
        printf("\nNhap n : "); scanf("%d", &n);
    }while(n <= 0);
    HH a[n];
    nhap(a,  n);
    xuatN( a, n);
    xuat("hanghoa.txt",a, n);
    fflush(stdin); gets(ten);
    timhanghoa("n",a, n);
}
    
