#include<bits/stdc++.h>
using namespace std;
int main()
{
	int s,f,n,k,m;
	cin>>n>>k>>m>>s>>f;
	queue<int> Q;  //van hanh cho thuat toan BFS
	map<int,int> M;    //do do sau  M[11]=2;  M[4]=3
	M[s]=1;
	Q.push(s);
	while(Q.size())
	{
		int u=Q.front(); Q.pop();
		if(u+k <=n && !M[u+k] ) {M[u+k]=M[u]+1; Q.push(u+k);}
		if(u-m >0  && !M[u-m] ) {M[u-m]=M[u]+1; Q.push(u-m);}
		if(M[f]) {cout<<M[f]-1; return 0;}
	}
	cout<<-1;
}
