#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, k;
	cin>>n>>k;
	//int A[n]; 
	//for(auto &x:A) cin>>x;
	int A[] = {8, 8, 7, 4, 4, 3, 2, 2};
	sort(A,A+n,greater<int>()); //sap xep giam dan
	queue<int> Q;
	int T=0;
	for(auto x:A) 
	{
		Q.push(x);
		if(Q.front()>=k+x) Q.pop(); //Neu phan tu dau hang doi lon hon hoac bang x+k thi loai ra khoi hang doi
		else T+=x;
		
		// 4 7 2 8 4 8 3 2 (k=2) --> 8 8 7 4 4 3 2 2
		// Q = {8} --> k+x = 2 + 8 = 10 --> khong pop 8 ra khoi Q
		// Q = {8,8} --> k+x = 2 + 8 = 10 --> khong pop 8 ra khoi Q
		// Q = {8,8,7} --> k+x = 2 + 7 = 9 --> khong pop 8 ra khoi Q
		// Q = {8,8,7,4} --> k+x = 2 + 4 = 6 --> pop 8 ra khoi Q --> Q = {8,7,4}
		// Q = {8,7,4,4} --> k+x = 2 + 4 = 6 --> pop 8 ra khoi Q --> Q = {7,4,4}
		// Q = {7,4,4,3} --> k+x = 2 + 3 = 5 --> pop 7 ra khoi hang doi --> Q = {4,4,3}
		// Q = {4,4,3,2} --> k+x = 2+2 --> pop 4 ra khoi hang doi --> Q = {4,3,2}
		// Q = {4,3,2,2} --> k+x = 2+2 --> pop 4 ra khoi hang doi --> Q = {3,2,2}
		//Ket qua: 3, 23
	}
	cout<<Q.size()<<" "<<T; 
}
