#include<bits/stdc++.h>
using namespace std;

int binarySearch(int A[], int l, int r, int x) {
	if (r >= l) {
		int mid = (l + r) / 2; // Tinh vi tri giua mang
		
		if (A[mid] == x)       // Neu A[mid] = x, tra ve chi so va ket thuc.
			return mid;
			
		// Neu A[mid] > x, thuc hien tim kiem nua trai cua mang
		if (A[mid] > x)
			return binarySearch(A, l, mid - 1, x);
			
		// Neu A[mid] < x, thuc hien tim kiem nua phai cua mang
		return binarySearch(A, mid + 1, r, x);
	}
	
	return -1;
}


int main()
{
	int A[] = {1, 4, 7, 8, 9, 14, 16, 18}; //Day duoc sap tang dan
	int n = sizeof(A)/sizeof(A[0]);
	int x;
	
	cout<<"Nhap phan tu can tim: ";
	cin>>x;
	
	int i = binarySearch(A, 0, n - 1, x);
	
	cout<<"Mang so nguyen: ";
	for (int i = 0; i < n; i++)
		cout<<A[i]<<" ";
	
	if (i >= 0)
		cout<<endl<<"Tim thay tai vi tri: "<<i;
	else
		cout<<endl<<"Khong tim thay!";
	
	return 0;
}


