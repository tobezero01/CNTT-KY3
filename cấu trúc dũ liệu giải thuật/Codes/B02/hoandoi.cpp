#include<bits/stdc++.h>
using namespace std;

void hoandoi(float &a, float &b)
{
	float tg;
	tg = a;  
	a = b;
	b = tg;
}


int main() {
     float x, y;
     cout<<"Nhap x, y: ";   
     cin>>x>>y;
     cout<< "x = "<< x <<" y = "<<y<<endl;
     hoandoi(x,y);
     cout<< "x = "<< x <<" y = "<<y;
     //getch();
	 return 0; 
}

