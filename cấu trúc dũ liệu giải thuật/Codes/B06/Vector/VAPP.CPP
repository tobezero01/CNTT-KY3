#include"conio.h"
#include"stdio.h"
#include"iostream"
#include"..\Vector\Vector.cpp"
#include"..\Vector\VItr.cpp"
using namespace std;
class VectorApp  //Lop ung dung lop vector va lop VectorItr
{
	private:
			Vector<float> v;
	public:
		int menu(); //Tao danh muc chuc nang cho nguoi dung
		void run(); //quan ly qua trinh chay cua ung dung
		void GetElement();
		void InsertElement();
		void RemoveElement();
		void ReplaceElement();
		void ListElement();
};
int VectorApp::menu()
{
	cout<<"\n1.Chen mot phan tu vao vector";
	cout<<"\n2.Xoa mot phan tu cua vector";
	cout<<"\n3.Thay the gia tri cua mot phan tu";
	cout<<"\n4.Lay gia tri cua mot phan tu";
	cout<<"\n5.In danh sach cac phan tu co trong vector";
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
	  cout<<"\n";
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
  }while(ch!=6);
}
void VectorApp::InsertElement()
{
	 float x;
	 int r;
	 cout<<"Nhap gia tri:";
	 cin>>x;
	 cout<<"Vi tri chen:";
	 cin>>r;
	 if(v.insertAtRank(r,x))
		cout<<"Chen phan tu thanh cong!";
	else
		cout<<"Chen pt khong thanh cong. Loi do vi tri chen";
	getch();
}
void VectorApp::RemoveElement()
{
  float x;
  int r;
  cout<<"Nhap vi tri cua phan tu can xoa bo:";
  cin>>r;
  if(v.removeAtRank(r,x))
	  cout<<"Phan tu bi xoa di :"<<x;
  else
	  cout<<"Xoa phan tu khong thanh cong. Loi do vi tri xoa";
  getch();
}
void VectorApp::ReplaceElement()
{
	 float x;
	 int r;
	 cout<<"Nhap gia tri can thay the:";
	 cin>>x;
	 cout<<"Nhap vi tri can thay the:";
	 cin>>r;
	 if(v.replaceAtRank(r,x))
		 cout<<"Thay the phan tu thanh cong";
	 else
		cout<<"Thay the pt khong thanh cong. Loi do vi tri thay the";
	getch();
}
 void VectorApp::GetElement()
 {
	float x;
	int r;
	cout<<"Nhap vi tri can lay phan tu:";
	cin>>r;
	if(v.getAtRank(r,x))
		 cout<<"Phan tu lay duoc:"<<x;
	else
		cout<<"Lay phan tu khong thanh cong. Loi do vi tri lay";
	getch();
}
 void VectorApp::ListElement()
 {
	VectorItr<float> Itr(&v);
	cout<<"Danh sach cac phan tu:";
	while(Itr.hasNext())
	  cout<<Itr.next()<<" ";
	getch();
 }
