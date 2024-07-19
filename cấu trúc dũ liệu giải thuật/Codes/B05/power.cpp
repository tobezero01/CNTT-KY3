#include<bits/stdc++.h>
using namespace std;

long long power(int x, int n) {
	if (n==0) return 1;
	else return x*power(x, n-1);
}

int main(){
	int x = 2, n = 6;
	long long p = power(x, n);
	
	cout<<"Ket qua la: "<<p;
	return 0; 
}

