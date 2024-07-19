//
#include<bits/stdc++.h>
using namespace std;

long long Fib(int n)
{ 
	if (n<=1)
		return 1;
	else 
		return Fib(n-1) + Fib(n-2);
		
	//return n<=1?1:(Fib(n-1)+Fib(n-2));
}
int main()
{
	for(int i=0;i<=45;i++) cout<<Fib(i)<<" ";

	return 0;
}


