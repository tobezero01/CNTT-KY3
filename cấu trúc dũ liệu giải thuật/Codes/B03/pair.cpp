//kieu pair
#include<bits/stdc++.h>
using namespace std;

typedef pair<string,int> sv;
#define ten first
#define diem second
int main()
{
	sv A,B,C;
	A.ten="Ho Ngoc Anh Ha";
	A.diem=5;
	B.ten="Le Quanh Vinh";
	B.diem=A.diem;
	C=A;
	cout<<"Sinh vien thu nhat "<<A.ten<<" co diem "<<A.diem;
	sv D=make_pair("Hai Lua",10);
	cout<<"\nSinh vien thu tu "<<D.ten<<" co diem "<<D.diem;
	sv E={"Tai Em",7};
	cout<<"\nSinh vien thu nam "<<E.ten<<" co diem "<<E.diem;
	
	

}


