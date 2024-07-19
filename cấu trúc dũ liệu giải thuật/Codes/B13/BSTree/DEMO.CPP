#include "conio.h"
#include "Btree.cpp"
#include "iostream"
using namespace std;
void visit(BNode<int,char*>*p)
{
	  cout<<p->getElem()<<"  ";	
}
int main(){
	BTree<int,char*> tree;
	BNode<int,char*> *p;
	//BNode<int,float> *p;
	system("cls");
	tree.insert(100,"100");
	tree.insert(70,"70");
	tree.insert(150,"150");
	tree.insert(120,"120");
	//tree.preOrder(tree.getRoot(),visit);
	cout<<"\nDuyet cay theo thu tu giua:";	
	tree.inOrder(tree.getRoot(),visit);
   //	cout<<"\n";
   //	tree.postOrder(tree.getRoot(),visit);
   //tree.remove(150);
    cout<<"\n";
	//tree.inOrder(tree.getRoot(),visit);
	p = tree.search(100, tree.getRoot());
	if(p!=NULL)
	  cout<<"Tim thay khoa 100, Co gia tri "<<p->getElem();
	else
	  cout<<"Khong tim thay khoa 100.";
	  
    tree.remove(120);
    tree.remove(100);
    tree.remove(70);    
    cout<<"\nDuyet cay theo thu tu giua:";
   	tree.inOrder(tree.getRoot(),visit);
	getch();
	return 0;
}

