#include"conio.h"
#include"stdio.h"
#include"iostream"
#include"Vector.cpp"
#include"VItr.cpp"
#include"Student.cpp"
using namespace std;
class VectorApp  //Lop ung dung lop vector va lop VectorItr
{
	private:
		Vector<Student>  v;
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
	cout<<"1.Them mot sinh vien moi";
	cout<<"\n2.Xoa mot sinh vien";
	cout<<"\n3.Thay the mot sinh vien";
	cout<<"\n4. Lay thong tin mot sinh vien";
	cout<<"\n5.In danh sach sinh vien";
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
	 Student x;
	 int r;
	 cout<<"Nhap thong tin cua sinh vien:";
	 cin>>x;
	 cout<<"Vi tri chen:";
	 cin>>r;
	if(v.insertAtRank(r,x)==1)
		cout<<"Chen phan tu thanh cong!";
	
	else
		cout<<"Chen phan tu khong thanh cong. Loi do vi tri chen";

}
void VectorApp::RemoveElement()
{
  Student x;
  int r; 
  cout<<"Nhap vi tri cua sinh vien can xoa bo:";
  cin>>r;
  if(v.removeAtRank(r,x)==1)
	  cout<<"Phan tu bi xoa di :"<<x;
  else
	  cout<<"Xoa phan tu khong thanh cong. Loi do vi tri xoa"; 
}
void VectorApp::ReplaceElement()
{
	 Student x;
	 int r;	
	 cout<<"Nhap thong tin sinh vien:";
	 cin>>x;
	 cout<<"Nhap vi tri can thay the:";
	 cin>>r;
	 if(v.replaceAtRank(r,x)==1)
	     cout<<"Thay the phan tu thanh cong";
	 else
		 cout<<"Thay the phan tu khong thanh cong. Loi do vi tri thay the";   
}
 void VectorApp::GetElement()
 {
	Student x;
	int r;	
	cout<<"Nhap vi tri can lay phan tu:";
	cin>>r;
	if(v.getAtRank(r,x)==1)
	 cout<<"Phan tu lay duoc:"<<x;
	else
	  cout<<"Lay phan tu khong thanh cong. Loi do vi tri lay";    
 }
 void VectorApp::ListElement()
 {
	VectorItr<Student> Itr(&v);
	cout<<"Danh sach cac sinh vien:\n";
	while(Itr.hasNext())
	  cout<<Itr.next()<<"\n";
	
 }
