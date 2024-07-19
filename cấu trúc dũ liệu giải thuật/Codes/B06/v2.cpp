#include<bits/stdc++.h>
using namespace std;

int main() {
	
	vector<int> v1 = {1, 2, 3, 4, 5};
	
	vector<int>::iterator it;
	for (it = v1.begin(); it!=v1.end();it++)
		cout<<*it;
	cout<<endl<<v1.size();
	cout<<endl<<v1.capacity();
	v1.push_back(6);
	cout<<endl<<v1.size();
	cout<<endl<<v1.capacity();
	for (int i = 7; i<=11;i++)
		v1.push_back(i);
	cout<<endl<<v1.size();
	cout<<endl<<v1.capacity();
	
}
