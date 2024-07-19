#ifndef NODE_CPP
#define NODE_CPP 1
#include"iostream"
using namespace std;
template <class T>
class Node{
private:
	T elem;
	Node *next;
public:
	Node();
	Node *getNext();          //Tra lai dia chi cua doi tuong do thanh
							  //phan Next tro den
	void setNext(Node<T>*);   //Dat thanh phan Next tro
							  //vao doi tuong la doi cua phuong thuc
	T  getElem();			  // Tra lai dia chi cua phan tu luu trong Node
	void  setElem(T);	      // Dat thay the phan tu luu trong Node
                              // bang phan tu moi
};
//------------------------------------------------------------------
template <class T>
Node<T>::Node(){
	next = NULL;
}
//-----------------------------------------------------------------
template <class T>
Node<T> *Node<T>::getNext(){
	return next;
}
//------------------------------------------------------------------
template <class T>
void Node<T>::setNext(Node<T> *p){
	next = p;
}
//------------------------------------------------------------------
template <class T>
T Node<T>::getElem(){
	return elem;
}
//------------------------------------------------------------------
template <class T>
void Node<T>::setElem(T e){
	elem = e;
}
#endif
