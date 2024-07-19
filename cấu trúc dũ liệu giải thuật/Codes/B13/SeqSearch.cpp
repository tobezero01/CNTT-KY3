#include<bits/stdc++.h>
using namespace std;

template<class T>
int SeqSearch(T *S, int n, T k){
    int found = 0;
    int i= 0;
    while(i<n && found==0){
         if(S[i]==k) 
           found = 1;
         i++;    
    }
    return found;
}

int main()
{
	int A[] = {1, 4, 7, 8, 9, 14, 16, 18}; //Day duoc sap tang dan
	int n = sizeof(A)/sizeof(A[0]);
	int x;
	
	cout<<"Nhap phan tu can tim: ";
	cin>>x;
	
	int i = SeqSearch(A, n - 1, x);
	
	cout<<"Mang so nguyen: ";
	for (int i = 0; i < n; i++)
		cout<<A[i]<<" ";
	
	if (i >= 0)
		cout<<endl<<"Tim thay tai vi tri: "<<i;
	else
		cout<<endl<<"Khong tim thay!";
	
	return 0;
}

