#include<bits/stdc++.h>
using namespace std;

long long giaithua(int n) {
	long long x = 1;
	for (int i = 1; i <=n; i++)
		x = x * i;
		
	return x;
}

int main() {
	long long x = giaithua(12);
	cout<<"Ket qua: "<<x;
}
