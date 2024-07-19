//factoria of bignumber
#include<bits/stdc++.h>
//#include"vector.cpp"

using namespace std;

void mul(int k,vector<int> &V)
{
	long long n=0;
	for(auto &x:V) 
	{
		n+=x*k;
		x=n%10;
		n/=10;
	}
	while(n) V.push_back(n%10),n/=10;
	/* Vi du: tinh 720*7 = 5040
	V = {027}, n = 0
	x = 0 --> n = 0 + 0*7 = 0, x = 0%10 = 0 (--> V[0] = 0), n = 0/10 = 0
	x = 2 --> n = 0 + 2*7 = 14, x = 14%10 = 4 (--> V[1] = 4), n = 14/10 = 1
	x = 7 --> n = 1 + 7*7 = 50, x = 50%10 = 0 (--> V[2] = 0), n = 50/10 = 5
	--> V = {040}
	Thuc hien vong while: V.push_back(5%10=5), n=5/10=0 --> V = {0405}
	*/
}
int main()
{
	int n;
	cin>>n;
	vector<int> V(1,1); 
	for(int i=2;i<=n;i++) mul(i,V);
	//for(auto it=V.rbegin();it!=V.rend();it++) cout<<*it;
	for(int i=V.size()-1;i>=0;i--) cout<<V[i];
}


