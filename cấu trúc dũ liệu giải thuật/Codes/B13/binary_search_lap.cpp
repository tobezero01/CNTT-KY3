#include<bits/stdc++.h>
using namespace std;

int binarySearch(int A[], int l, int r, int x) {
    int mid;
 
    while(l <= r) {
        // Lay vi tri giua left va right
        mid = (l + r) / 2;
 
        // Neu phan tu o giua bang x thi tra ve vi tri cua no
        if (A[mid] == x)
            return mid;
 
        // Neu x lon hon phan tu o giua thi tim ben nua ben phai.
        if (x > A[mid])
            l = mid + 1;
        else //Nguoc lai thi tim ben nua ben trai.
            r = mid - 1;
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


