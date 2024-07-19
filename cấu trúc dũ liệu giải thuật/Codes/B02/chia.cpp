#include<bits/stdc++.h>
using namespace std;

template <class T>
T chia(T a,T b) {
	return a/b;
}

int main()
{
	int bb = chia(32,5);
	double cc = chia(32.0,5.0);
	cout<<bb<<endl<<cc<<endl;
	
	//cout<<chia<int>(32,5)<<"\n";
	//cout<<chia<double>(32.0,5.0)<<"\n";
}


