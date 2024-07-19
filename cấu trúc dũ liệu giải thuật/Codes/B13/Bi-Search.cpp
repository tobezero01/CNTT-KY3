#include<bits/stdc++.h>
using namespace std;

template<class T>//Keys trung voi gia tri
int BinarySearch(T *S,T k,int n)
{
	int Found = 0;
	int i = 0;
	int j = n - 1;
	while(i<=j && Found!=1){
         mid = (i+j) / 2;
	    if(k==S[mid])
          Found = 1;  
       else	    
          if  (k < S[mid]) 
		       j = mid – 1;
          else
	    	    i = mid+1;
   }
	return Found;
}
