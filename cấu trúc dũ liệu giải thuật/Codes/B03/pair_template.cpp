#include<bits/stdc++.h>
using namespace std;

template <class T, class Y>
class CPair { 
		T a;
		Y b; 
	public: 
	CPair(){ }
	CPair (T a1, Y b1){
	      a=a1; b=b1;} 
	T getmax (); 
};

template <class T, class Y >
T CPair<T,Y>::getmax () {
    T retval;
     retval = a>b? a : b;
     return retval;
}

int main () {
    CPair<float, int> p1 (100, 75); 
    CPair<float,float> p2(10.2,10.5) ;
    cout << p1.getmax(); 
    cout<<endl<<p2.getmax(); 
    return 0;
} 

