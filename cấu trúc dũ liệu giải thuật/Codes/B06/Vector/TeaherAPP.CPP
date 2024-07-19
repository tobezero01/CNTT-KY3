#include"conio.h"
#include"stdio.h"
#include"iostream"
#include"..\Vector\Vector.cpp"
#include"..\Vector\VItr.cpp"
#include"..\Vector\Teacher.cpp"
using namespace std;
class VectorApp  //Lop ung dung lop vector va lop VectorItr
{
	private:
		Vector<Teacher>  v;
	public:
		int menu();
		void run();
		void GetElement();
		void InsertElement();
		void RemoveElement();
		void ReplaceElement();
		void ListElement();
};
int VectorApp::menu()
{
	cout<<"1.Chen mot giao vien vao danh sach";
	cout<<"\n2.Xoa mot giao vien khoi danh sach";
	cout<<"\n3.Thay the mot giao vien trong danh sach";
	cout<<"\n4. Lay thong tin cua mot giao vien";
	cout<<"\n5.In danh sach giao vien";
	cout<<"\n6.Ket thuc chuong trinh";
	cout<<"\nChon chuc nang tu 1..6:";
	int n;
	cin>>n;
	return n;
}
void VectorApp::run()
{
  int ch;
  do{
	  system("cls");
	  ch = menu();
	  system("cls");
	  switch(ch)
	  {
		 case 1:
			  InsertElement();
			  break;
		 case 2:
			  RemoveElement();
			  break;
		 case 3:
			  ReplaceElement();
			  break;
		 case 4:
			  GetElement();
			  break;
		 case 5:
			  ListElement();
			  break;
	 }
	 getch();
  }while(ch!=6);
}
void VectorApp::InsertElement()
{
	 Teacher x;
	 int r;	 
	 cout<<"Nhap thong tin cua giao vien:";
	 cin>>x;
	 cout<<"Vi tri chen:";
	 cin>>r;
	if(v.insertAtRank(r,x)==1)
       cout<<"Chen Giao vien thanh cong!";
    else
	   cout<<"Chen Giao vien khong thanh cong. Loi do vi tri chen";	
}
void VectorApp::RemoveElement()
{
  Teacher x;
  int r;
  cout<<"Nhap vi tri cua giao vien can xoa bo";
  cin>>r;
  if(v.removeAtRank(r,x)==1)
 	 cout<<"Giao vien bi xoa di :"<<x;
  else
   	 cout<<"Xoa Giao vien khong thanh cong. Loi do vi tri xoa";
}
void VectorApp::ReplaceElement()
{
	 Teacher x;
	 int r;
	 cout<<"Nhap thong tin giao vien:";
	 cin>>x;
	 cout<<"Nhap vi tri can thay the:";
	 cin>>r;
	 if(v.replaceAtRank(r,x)==1)
		 cout<<"Thay the Giao vien thanh cong";
	 else
		cout<<"Thay the Giao vien khong thanh cong. Loi do vi tri thay the";
}
 void VectorApp::GetElement()
 {
	Teacher x;
	int r;
	cout<<"Nhap vi tri can lay Giao vien:";
	cin>>r;
	if(v.getAtRank(r,x)==1)
	   cout<<"Giao vien lay duoc:"<<x;
	else
	  cout<<"Lay Giao vien khong thanh cong. Loi do vi tri lay";
 }
 void VectorApp::ListElement()
 {
	VectorItr<Teacher> Itr(&v, v.size());
	cout<<"Danh sach cac giao vien:\n";
	while(Itr.hasNext())
	  cout<<Itr.next()<<"\n";
 }
