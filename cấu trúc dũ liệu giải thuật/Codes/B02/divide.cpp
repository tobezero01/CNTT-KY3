#include<bits/stdc++.h>
using namespace std;

int divide (int a=10, int b=2) {
    int r; 
    r=a/b;
    return (r); 
} 

int main() { 
	cout<<divide()<<endl;
	cout << divide (12)<<endl; 
	cout << divide (12, 4); 
	return 0; 
} 

