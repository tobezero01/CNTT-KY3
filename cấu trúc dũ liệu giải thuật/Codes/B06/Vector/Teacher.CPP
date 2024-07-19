#ifndef STUDENT_CPP
#include"conio.h"
#include"iostream.h"
class Teacher
{
private:
	int magv;
	char hoten[30];
	char gioi[4];
	char bomon[50];
	char trinhdo[20];
public:
	friend istream & operator >>(istream &is, Teacher &s);
	friend ostream & operator <<(ostream &os, Teacher s);
};
istream & operator >>(istream &is, Student &s)
{
	 cout<<"\nNhap ma giao vien:";
	 is>>s.magv;
	 cout<<"Nhap ho va ten:";
	 is.ignore(1);
	 is.get(s.hoten,30);
	 cout<<"Nhap gioi tinh:";
	 is.ignore(1);
	 is.get(s.gioi,4);
	 cout<<"Nhap bo mon:";
	 is.ignore(1);
	 is.get(s.bomon,50);
	 cout<<"Nhap trinh do:";
	 is.ignore(1);
	 is.get(s.trinhdo,20);
	 return is;
}
ostream & operator <<(ostream &os, Student s)
{
	  os<<s.magv<<"  "<<s.hoten<<"   " <<s.gioi<<"   "<<s.bomon<<"    "<<s.trinhdo;
	 return os;
}





#endif