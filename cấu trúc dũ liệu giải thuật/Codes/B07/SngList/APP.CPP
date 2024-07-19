#include "conio.h"
#include "stdio.h"
#include "iostream"
#include "Slist.cpp"
#include "SLItr.cpp"
#include "Student.cpp"
using namespace std;

#define SIZE 1
#define INSERT_FIRST 2
#define INSERT_LAST 3
#define INSERT_AFTER 4
#define REPLACE 5
#define REMOVE 6
#define DISPLAY_LIST 7
class AppSingleList{
private:
	SingleList<Student> *list;
public:
	AppSingleList();
	void listSize();
	void insertFirst();
	void insertLast();
	void insertAfter();
	void replace();
	void remove();
	void displayList();
	int menu();
	void run();
};
//--------------------------------------------------------------------------------------
AppSingleList::AppSingleList(){
	list = new SingleList<Student>();
}
//--------------------------------------------------------------------------------------
void AppSingleList::listSize(){
	cout<<"So sinh vien hien co la:"<<list->size();
}
//--------------------------------------------------------------------------------------
void AppSingleList::insertFirst(){
	Student x;
	cout<<"Nhap thong tin sinh vien:";
	cin>>x;	
	if(list->insertFirst(x))
		cout<<"Da them sinh vien vao dau thanh cong.";
	else
		cout<<"Them sinh vien khong thanh cong.";
}
//--------------------------------------------------------------------------------------
void AppSingleList::insertLast(){
	Student x;	
	cout<<"Nhap thong tin cua sinh vien:";
	cin>>x;	
	if(list->insertLast(x))
		cout<<"Da them sinh vien vao cuoi thanh cong.";
	 else
		cout<<"Them sinh vien khong thanh cong.";
}
//--------------------------------------------------------------------------------------
void AppSingleList::replace(){
	Student x;
	Node<Student> *p;
	int i;
	cout<<"Nhap thong tin sinh vien can thay:";
	cin>>x;
	cout<<"Thay the sinh vien thu may (<"<<list->size()<<"):";
	cin>>i;	
	p = list->getNode(i);
	if(p!=NULL){
		list->replace(p,x);
		cout<<"Thay the thanh cong.";
	}
	else
		cout<<"Thay the khong thanh cong.";
}
//--------------------------------------------------------------------------------------
void AppSingleList::insertAfter(){
	Student x;
	Node<Student> *p;
	int i;
	cout<<"Nhap thong tin sinh vien:";
	cin>>x;
	cout<<"Chen sau sinh vien thu may(<"<<list->size()<<"):";
	cin>>i;
	p = list->getNode(i);
	if(p!=NULL){
		list->insertAfter(p,x);
		cout<<"Chen sinh vien thanh cong.";
	}
	else
		cout<<"Chen sinh vien khong thanh cong.";
}
//--------------------------------------------------------------------------------------
void AppSingleList::remove(){
	int i;
	Node<Student> *p;
	cout<<"Xoa sinh vien o vi tri thu may("<<list->size()<<"):";
	cin>>i;
	p = list->getNode(i);
	if(p!=NULL){
		list->remove(p);
		cout<<"Da xoa thanh cong.";
	}
	else
		cout<<"Xoa khong thanh khong.";
}
//--------------------------------------------------------------------------------------
void AppSingleList::displayList(){
	SingleListItr<Student> itr(list);
	cout<<"Cac sinh vien hien co trong danh sach: ";
	while(itr.hasNext())
		cout<<"\n"<<itr.next();	
}
//--------------------------------------------------------------------------------------
int AppSingleList::menu(){
	int n; 
	cout<<"1. Kich thuoc hien tai cua danh sach.\n";
	cout<<"2. Chen phan tu vao dau danh sach. \n";
	cout<<"3. Chen phan tu vao cuoi danh sach. \n";
	cout<<"4. Chen phan tu vao sau mot phan tu nao do trong danh sach.\n";
	cout<<"5. Thay the phan tu hien co cua mot node. \n";
	cout<<"6. Loai bo mot node khoi danh sach.\n";
	cout<<"7. Hien thi toan bo danh sach:\n";
	cout<<"8. Ket thuc.\n";
	cout<<"   Hay nhap vao so 1..8:";
	cin>>n;
	return n;
}
 //--------------------------------------------------------------------------------------
void AppSingleList::run(){
	int choise;
	do{
		system("cls");
		choise = menu();
	    system("cls");
		switch(choise){
			case SIZE:
				listSize();
				break;
			case INSERT_FIRST:
				insertFirst();
				break;
			case INSERT_LAST:
				insertLast();
				break;
			case INSERT_AFTER:
				insertAfter();
				break;
			case REPLACE:
				replace();
				break;
			case REMOVE:
				remove();
				break;
			case DISPLAY_LIST:
				displayList();
				break;
		}
		getch();
	}while(c