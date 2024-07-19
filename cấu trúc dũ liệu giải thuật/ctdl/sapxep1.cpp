//#ifndef SORT_NN_H 
#define SORT_NN_H 1 
#ifndef ARRAY_H 
#define ARRAY_H 0 
#include<bits/stdc++.h> 

using namespace std;

template <class T>
int comp(T a, T b) {
	if (a > b) return 1;
	else return 0;
}

template <class T>
void input(T *a , int n) {
	for (int i=0 ; i<n ; i++) {
		cout<<"a[" << i << "] = ";
		cin >> a[i];
	}
}

template <class T>
void output(T *a , int n) {
	for (int i=0 ; i<n ; i++) {
		cout<< a[i] << " ";
	}
}

template <class T> 
void Swap(T &a, T &b) { 
	T tg =a; 
	a = b; 
	b = tg; 
} 

template <class T> 
void BubbleSort(T *a , int n) {  
	for (int i=0 ; i<n-1 ; i++) 
		for(int  j=n-1 ; j>i ; j--) 
			if(a[j] < a[j-1]) 
			Swap(a[j],a[j-1]);  
  
} 
template<class T> 
void SelectionSort(T *a , int n) {  
	int min; 
	for(int i=0 ; i < n-1 ; i++) {  
		min = i; // coi a[i] min
		for(int j = i + 1 ; j < n ; j++) //tim min tu a[i] den a[n-1]
			if (a[j] < a[min]) { // a[j] nho hon a[min] thi a[j] la nho nhat 
				min = j;// luu vi tri min moi tim dc
			}
			if (min != i)  Swap(a[i],a[min]); // min ko giong ban dau thi swap
	} 
}

template<class T>
void InsertionSort(T *a,int n, int (*comp)(T,T)) {
     T x;
     int i, j;
     for(i=1; i<n ; i++){
        j = i-1; 
        x = a[i]; //luu lai x 
        while(comp(a[j],x==0) && j>=0){
           a[j+1] = a[j];
           j--;
        }   
        a[j+1]= x;
     }      
}
#endif 
int main () {
	float a[100];
	int n;cout << "nhap n : " ;cin >> n;
	input(a,n);
	BubbleSort(a , n);
	cout<< "sap xep kieu Bubblesort : " ;
	output(a,n);
	SelectionSort(a ,n);
	cout<< "\nsap xep kieu Selectionsort : " ;
	output(a,n);
	InsertionSort(a , n ,&comp);
	cout<< "\nsap xep kieu Insertionsort : ";
	output(a,n);
}


