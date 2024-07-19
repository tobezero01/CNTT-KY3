#include<bits/stdc++.h>
using namespace std;

int uscln(int x, int y){
	int r;
	while (y!=0) {
		r = x % y;
		x = y;
		y = r;
	}
	
	return x;
}

int main(){
	int x = uscln (10, 30);
	cout<<"Uoc so chung lon nhat la: " <<x;
	return 0;
}

