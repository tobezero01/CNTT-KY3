//con tro this
#include<bits/stdc++.h>
using namespace std;

struct ps
{
	int t,m;
	ps(int t=0,int m=1)
	{
		this->t=t;
		this->m=m;	
	}
	friend ostream &operator<<(ostream &os,ps p)
	{
		os<<p.t<<"/"<<p.m;
		return os;
	}
	friend ps operator+(ps p,ps q)
	{	
		return ps(p.t*q.m+p.m*q.t,p.m*q.m);
	}
	friend ps operator*(ps p,ps q)
	{	
		return ps(p.t*q.t,p.m*q.m);
	}
	ps operator++()  //++p
	{ 
		t+=m;
		return ps(t,m);
	}
	ps operator++(int) //p++
	{ 
		int t1=t;
		t+=m;
		return ps(t1,m);
	}
};
int main()
{
	ps p(3,4),q(7,5),r(2,3);
//	cout<<"Phan so : "<<p<<" va phan so q: "<<q;
//	cout<<"s=p+q*r "<<p+q*r;
	r= ++p*q;	
	cout<<"\np="<<p;
	cout<<"\nr="<<r;
}


