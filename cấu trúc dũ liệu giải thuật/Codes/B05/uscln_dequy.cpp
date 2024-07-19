#include<bits/stdc++.h>
using namespace std;

int uscln(int x, int y) {
	if (y==0) return x;
	else uscln(y, x%y);
}

int main(){
	int x = uscln (10, 30);
	cout<<"Uoc so chung lon nhat la: " <<x;
	return 0;
}
