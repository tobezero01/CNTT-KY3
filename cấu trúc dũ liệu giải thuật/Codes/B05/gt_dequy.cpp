#include<bits/stdc++.h>
using namespace std;

long long gt(int n) {
	if (n==0) return 1;
	else return n*gt(n-1);
}

int main() {
	long long x = gt(12);
	cout<<"Ket qua: "<<x;
		
	return 0;
}
