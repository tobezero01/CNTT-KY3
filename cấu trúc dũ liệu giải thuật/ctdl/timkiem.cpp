#include<bits/stdc++.h>
using namespace std;
// ti kiem tuan tu
void sequenseSearch(float *a,int n){
	float x;
	int found=-1;
	cout<<"nhap phan tu can tim kiem : ";
	cin>> x;
	for (int i=0;i<n;i++){
		if(a[i]==x){
			found=i;
			break;
		}
	}
	if(found ==-1) {
		cout<<"khong tim thay !";
	}else{
		cout <<"phan tu can tim "<<x<<" o vi tri "<<found;
	}
}
// ti kiem nhi phan pp de quy
int binarySearch(float *a, int l, int r,int k) {
	
	if (r >= l) {
		int mid = (l + r) / 2; //tim mid la vi tri giua
		
		if (a[mid] == k)   //hi huu phan tu o giua = x thi xuat ra man hinh
			return mid;
			
		if (a[mid] > k)   //x >pt o giua thi xet tu giua ve 0
			return binarySearch(a, l, mid - 1,k);
			// ngc lai thi xet tu mid ve cuoi mang
		return binarySearch(a, mid + 1, r,k);
	}
	
	return -1;
}
// tim kiem nhi phan pp lap
int binarySearchlap(float *a, int l, int r, int k) {
    while(l <= r) {
        int mid = (l + r) / 2;
 
        if (a[mid] == k)
            return mid;
 
        if (k < a[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
 
    return -1;
}
void Swap(float &a, float &b) { 
	float tg =a; 
	a = b; 
	b = tg; 
} 

void BubbleSort(float *a , int n) {  
	for (int i=0 ; i<n-1 ; i++) 
		for(int  j=n-1 ; j>i ; j--) 
			if(a[j] < a[j-1]) 
			Swap(a[j],a[j-1]);  
} 
int main (){
	int n;
	cout <<"nhap so phan tu cua mang : ";
	cin >> n; 
	
	float *a; a=new float[n];
	for (int i=0;i<n;i++){
		cout<<"a["<<i<<"] = ";
		cin>>a[i];
	}
	cout <<"tim tuan tu \n";
	sequenseSearch(a,n);
	BubbleSort(a ,n); // sap xep lai mang tang dan
	cout<<"\nmang sau sap xep la ";
	for (int i=0;i<n;i++){
		cout<<endl<<"a["<<i<<"] = ";
		cout <<a[i];
	}
	cout << "\n\nnhi phan de quy\n";
	int k;
	cout << "nhap phan tu can tim k : ";cin>>k;
	if (binarySearch(a, 0, n-1,k) >=0) cout <<"tim thay o vi tri thu : "<<binarySearch(a, 0, n-1,k);
	else cout <<"khong tim thay phan tu ";
	
	cout << "\n\nnhi phan lap\n";
	if (binarySearchlap(a, 0, n-1,k) >=0) cout <<"tim thay o vi tri thu : "<<binarySearchlap(a, 0, n-1,k);
	else cout <<"khong tim thay phan tu ";
	
	return 0;
}
