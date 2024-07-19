#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> mi = {1, 2, 6, 8};
	int m[] = {6, 8, 9, 90};
	
	int n = sizeof(m)/sizeof(m[0]);
	
	vector<int> mi2(m, m + n);
	
	for (int i =0; i <mi2.size(); i++)
		cout<<mi2[i]<<" ";
	cout<<endl;
	for (int i =0; i <mi.size(); i++)
		cout<<mi[i]<<" ";
	vector<int> mi3(5, 100);
	cout<<endl;
	for (int i =0; i <mi3.size(); i++)
		cout<<mi3[i]<<" ";
	cout<<endl;
	cout<<"Kich thuoc cua vector mi3 la: "<<mi3.size()<<endl;
	cout<<"Capacity cua vector mi3 la: "<<mi3.capacity()<<endl;
	mi3.push_back(8);
	cout<<"Kich thuoc cua vector mi3 la: "<<mi3.size()<<endl;
	cout<<"Capacity cua vector mi3 la: "<<mi3.capacity()<<endl;
	vector<int>::iterator it;
	for (it = mi3.begin();it != mi3.end();++it)
		cout<<*it<<" ";
	
	return 0;
}
