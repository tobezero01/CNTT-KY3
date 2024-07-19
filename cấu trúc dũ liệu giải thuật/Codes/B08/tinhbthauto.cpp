//Tinh gia tri cua bieu thuc hau to
#include<bits/stdc++.h>
using namespace std;

int f(int u,int v,char p)
{
	if(p=='+') return u+v;
	if(p=='-') return u-v;
	if(p=='*') return u*v;
	return u/v;
}
int main()
{
	string x;   //x=45+63*-
	stack<int> S;
	cin>>x;
	for(auto c:x)
		if('0'<=c && c<='9') S.push(c-'0');
		else
		{
			int v=S.top(); S.pop();
			S.top()=f(S.top(),v,c);
		}
	cout<<S.top();
}


