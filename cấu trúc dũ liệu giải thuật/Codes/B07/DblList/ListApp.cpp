#include"conio.h"
#include"stdio.h"
#include"iostream"
#include"List.cpp"
#include"ListItr.cpp"
#include"student.cpp"
using namespace std;
class ListApp  //Lop ung dung lop List va lop ListItr
{
	private:
		List<Student> list;
	public:
		int menu();
		void run();
	  //	void GetElement();
		void InsertFirst();
		void InsertLast();
		void RemoveElement();
		void ListElement();
};
int ListApp::menu()
{
	cout<<"1.Them mot phan tu vao dau danh sach";
	cout<<"\n2.Them mot phan tu vao cuoi danh sach";
	cout<<"\n3.Xoa bo mot phan tu";
	cout<<"\n4.In danh sach cac phan tu co trong danh";
	cout<<"\n5.Ket thuc chuong trinh";
	cout<<"\nChon chuc nang tu 1..5:";
	int n;
	cin>>n;
	return n;
}
void ListApp::run()
{
  int ch;
  do{
	  system("cls");
	  ch = menu();
	  system("cls");
	  switch(ch)
	  {
		 case 1:
			  InsertFirst();
			  break;
		 case 2:
			  InsertLast();
			  break;
		 case 3:
			  RemoveElement();
			  break;
		 case 4:
			  ListElement();
			  break;
	 }
	 getch();   
  }while(ch!=5);
}
void ListApp::InsertFirst()
{
	 Student x;	
	 cout<<"Nhap thong tin sinh vien:";
	 cin>>x;
	 list.insertFirst(x);
	 cout<<"Them phan tu vao dau danh sach thanh cong!";	
}
void ListApp::InsertLast()
{
	 Student x;	
	 cout<<"Nhap thong tin sinh vien:";
	 cin>>x;
	 list.insertLast(x);
	 cout<<"Them phan tu vao cuoi danh sach thanh cong!";	
}
void ListApp::RemoveElement()
{
	 int x;	 
	 cout<<"Nhap ma sinh vien can xoa:";
	 cin>>x;
	 Node<Student>* p;
	 p=list.first();
	 while(p!=NULL && p->getElem().getMasv()!=x)
		p = p->getNext();
	 if(p==NULL)
		cout<<"Khong tim thay sinh vien co ma "<<x;
	 else
	 {
		 list.remove(p);
		 cout<<"Da xoa sinh vien co ma "<<x;
	 }	
}
 void ListApp::ListElement()
 {
	ListItr<Student> Itr(&list);
	cout<<"Danh sach sinh vien:\n";
	while(Itr.hasNext())
	   cout<<Itr.next()<<"\n";	
 }
//the end of listapp
