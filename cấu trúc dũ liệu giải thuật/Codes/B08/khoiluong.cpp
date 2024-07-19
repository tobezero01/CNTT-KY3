//khoi luong hoa chat
#include<bits/stdc++.h>
using namespace std;
void solve(string x) //x = CH3(CH2)8COOH
{
	stack<int> S;
	for(auto c:x) { 
		if(c=='C' || c=='O' || c=='H' || c=='(') {
			if (c=='C') S.push(12);
			else if (c=='O') S.push(16);
			else if (c=='H') S.push(1);
			else S.push(0);
		} else if(c==')') {
			int t=0; 
			while(S.top()!=0) {
				t+=S.top();
				S.pop();
			}			
			S.top() = t;
		} 
		else S.top()*=c-'0';
	}
	
	int t=0; 
	while(S.size()) {
		t+=S.top();
		S.pop();
	}
	cout<<"Khoi luong phan tu: "<<t<<"\n";
}
int main()
{
	string x = "CH3(CH2)8COOH";
	cout<<"Chuoi cong thuc hoa hoc: "<<x<<endl;
	solve(x);
}
