#include<bits/stdc++.h>
using namespace std;

template<class T>
void Nhapday(T *a, int n, char ch){
    for(int i=0; i<n; i++){
        cout<<ch<<"["<<i<<"]=";
        cin>>a[i]; 
       }
    cout<<endl;
  }

template<class D>
void Inday(D *a, int n){
   for(int i=0; i<n; i++)
        cout<<a[i] <<" ";
    cout<<endl;
}

int main(){
	int m,n;
	float a[100];
	long  b[100];
	cout<<"Nhap m,n: ";
	cin>>m>>n;
	Nhapday(a,m,'a');
	Nhapday(b,n,'b');
	Inday(a,m);
	Inday(b,n);
}

