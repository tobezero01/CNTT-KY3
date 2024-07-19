#include<bits/stdc++.h>
using namespace std;

long long power(int x, int n) {
	if (n==0) return 1;
	if (n%2==1) {
		int y = power(x, (n - 1)/ 2);
		return x*y*y;
	} else {
		int y = power(x, n/ 2);
		return y*y;
	}
}

int main(){
	int x = 2, n = 6;
	long long p = power(x, n);
	
	cout<<"Ket qua la: "<<p;
	return 0; 
}

