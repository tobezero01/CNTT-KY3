#ifndef NODE_H
#define NODE_H 1
#include "iostream"
using namespace std;
template <class Keys,class T>
class Node{
private:
    Keys key;   
	T elem;
	Node<Keys,T> *next;
public:
	Node() {next = NULL;}
	Keys getKey(){ return key;}
	void setKey(Keys k){ key = k;}
	Node<Keys,T>  *getNext();          //Tra lai dia chi cua doi tuong do thanh phan Next tro den
	void    setNext(Node<Keys,T>*);		//Dat thanh phan Next tro vao doi tuong la doi cua phuong thuc
	T       getElem();			// Tra lai dia chi cua phan tu luu trong Node
	void    setElem(T);	// Dat thay the phan tu luu trong Node bang phan tu moi
};
//------------------------------------------------------------------
template <class Keys,class T>
Node<Keys,T>* Node<Keys,T>::getNext()
{
	return next;
}
//------------------------------------------------------------------
template <class Keys,class T>
void Node<Keys,T>::setNext(Node<Keys,T> * p)
{
	next = p;
}
//------------------------------------------------------------------
template <class Keys,class T>
T Node<Keys,T>::getElem()
{
	return elem;
}
//------------------------------------------------------------------
template <class Keys,class T>
void Node<Keys,T>::setElem(T e)
{
	elem = e;
}
#endif





     
     
