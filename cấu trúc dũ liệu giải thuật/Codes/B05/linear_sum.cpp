#include<bits/stdc++.h>
using namespace std;

long LinearSum(int A[], int n) {
	if (n==1) return A[0];
	else return LinearSum(A, n-1) + A[n-1];
}

int main() {
	int A[] = {4, 3, 6, 2, 5};
	long x = LinearSum(A, sizeof(A)/sizeof(A[0]));
	cout<<"Tong day la: "<<x;
	return 0;
}
