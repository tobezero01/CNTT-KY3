#include"conio.h"
#include"stdio.h"
#include"hashtbl.cpp"
#include"iostream"
using namespace std;
int h(int key, int n)
{
	 return key % n;
}
int main()
{
	  Hashtable<int, float> ht(97);
	  Node<int,float> *p;
	  int key;
	  system("cls");
	  ht.Add(1,45.5,h);
	  ht.Add(3,4.23,h);
	  ht.Add(10,100.23,h);
	  cout<<"\nSo phan tu hien co trong bang bam " 
         <<ht.Count();
	  cout<<"\nNhap khoa can tim:";
	  cin>>key;
	  p=ht.Find(key,h);
	  if(p==NULL)
		  cout<<"Khong tim thay phan tu co khoa = "<<key;
	  else
		  cout<<"Tim thay phan tu co khoa = "<<key
           <<" gia tri cua no="<<p->getElem();
	  getch();
	  return 0;
}

