#include<bits/stdc++.h>
using namespace std;

template <class T>
void Swap(T &a, T &b) {
    T tg =a;
    a= b;
    b=tg;
}

template <class T>
void Merge(T *a, int l, int m, int r) { // left ,mid ,right
{
	int *arrtam; // mang tam
	int i = l; // Vi tri dau mang con ben trai
	int j = m + 1; // Vi trimdau  mang con ben phai

	arrtam = new int[r - l + 1];

	for (int k = 0; k <= r - l; k++) {  // Kiem phan tu cua mang con ben trai va ben phai
		if (a[i] < a[j]) {
			// Neu a[i] < a[j] thi copy phan tu ben trai vao mang tam
			arrtam[k] = a[i]; 
			i++; 
		}
		else { // Nguoc lai copy phan tu cua mang con ben phai vao mang tam
			arrtam[k] = a[j];
			j++;
		}

		// Kiem tra mang con ben trai con phan tu ko
		if (i == m + 1) {
			//  dua cac phan tu con lai cua mang con ben phai vao mang tam
			while (j <= r) {
				k++;
				arrtam[k] = a[j];
				j++;
			}
			break;
		}

		// Kiem tra mang con ben phai con phan tu ko
		if (j == r + 1) {
			// Nguoc lai dua cac phan tu con lai cua mang con ben phai vao mang tam
			while (i <= m) {
				k++;
				arrtam[k] = a[i];
				i++;
			}
			break;
		}
	}
	for (int k = 0; k <= r - l; k++) // Chep mang tam vao mang chinh
		a[l + k] = arrtam[k];
	delete arrtam;
}}
   
template <class T>
void Mergesort(T *a, int l, int r) {
    if(l<r) {
        int m=(l+r)/2;
	    Mergesort(a, l, m);
	    Mergesort(a, m+1,r);
       	Merge(a, l, m, r);
    }
}  

template<class T>
void Pushdown (T *a, int i, int n) {
    int j = i; 
    int kt=0;
    int max;
    while (j<=n/2 && kt==0)
    {
       if(j*2==n)
           max = 2*j;
       else 
          if (a[2*j]<=a[2*j+1])
              max = 2*j+1;
          else  
			  max = 2*j;
       if (a[j]<a[max])  
       {
          Swap (a[j], a[max]);
          j = max;
       }
       else 
         kt=1;
     }
  }
template<class T>
void HeapSort(T *a, int n) {  
    int i; 
    for(i=(n-1)/2 ; i>= 0 ; i--)
        Pushdown(a,i, n-1);
        
    for(i=n-1 ; i>=2 ; i--) {
        Swap(a[0],a[i]);
	    Pushdown(a,0,i-1);
    }
} 
template<class T>
void nhap(T *a,int n)  {
	for (int i=0;i<n;i++){
		cout <<"phan tu thu "<<i<<" : ";
		cin>>a[i];
	}
}
template<class T>
void xuat(T *a,int n)  {
	for (int i=0;i<n;i++){
		cout << a[i]<<" ";
	}
}
int main() {
	int n; cout <<"nhap n : ";
	cin >> n;
	int a[n];int b[n];
	cout << "mergeSort \n";
	nhap(a,n);
	Mergesort(a, 0, n-1);
	xuat(a,n);	
	cout <<"\nheapSort \n";
	nhap(b,n);
	HeapSort(b, n);
	xuat(b,n);
	return 0;
}
 
