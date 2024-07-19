#ifndef STUDENT_CPP
#define STUDENT_CPP 1
#include"conio.h"
#include"iostream"
using namespace std;
class Student
{
    private:
    	int masv;
    	char hoten[30];
    	int ngay, thang, nam;
    	char gioi[4];
    	char que[50];
    public:
    	friend istream & operator >>(istream &is, Student &s);
    	friend ostream & operator <<(ostream &os, Student s);
};
istream & operator >>(istream &is, Student &s)
{
	 cout<<"\nNhap ma sv:";
	 is>>s.masv;
	 cout<<"Nhap ho va ten:";
	 is.ignore(1);
	 is.get(s.hoten,30);
	 cout<<"Nhap ngay thang nam sinh:";
	 is>>s.ngay>>s.thang>>s.nam;
	 cout<<"Nhap gioi tinh:";
	 is.ignore(1);
	 is.get(s.gioi,4);
	 cout<<"Nhap que quan:";
	 is.ignore(1);
	 is.get(s.que,50);
	 return is;
}
ostream & operator <<(ostream &os, Student s)
{
     os<<s.masv<<"\t"<<s.hoten<<"\t"<<s.ngay<<"/"<<s.thang;
     os<<"/"<<s.nam<<"\t"<<s.gioi<<"\t"<<s.que;
	 return os;
}
#endif
