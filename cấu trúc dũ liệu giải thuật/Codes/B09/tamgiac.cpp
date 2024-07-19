#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, res=0;
	vector<int> a;
	
	cin>>n;
	for(int i=0;i<n;i++) 
		cin>>a[i];
	sort(a.begin(), a.end(), greater<int>());
	queue<int> Q;
	for(int i=0;i<n;i++)
	{
	    while(Q.size()>1 && Q.front()>=Q.back()+a[i]) Q.pop();
		Q.push(a[i]);
		if(res<Q.size()) res=Q.size();
	}
	if(res<3) cout<<"Khong the tao ra day thoa man";
	else cout<<res;
}

//Vi du: 3 1 2 1 2 3
