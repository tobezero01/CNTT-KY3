#ifndef SINGLELIST_H
#define SINGLELIST_H 1
#include "node.cpp"
#include "iostream"
using namespace std;
template <class Keys, class T>
class SingleList{
private:
	Node<Keys,T> *header;	
	Node<Keys,T> *trailer; 
	long sz;
public:
	SingleList();
	long   size();
	int    isEmpty();
	Node<Keys,T>* insertLast(Keys key,T e);  //Chen them mot node vao cuoi danh sach
	void replace(Node<Keys,T>* p,Keys k, T e);
    void remove(Node<Keys,T> *p);		 // Loai bo node do con tro p tro toi
	Node<Keys,T>* getNode(Keys k);
};
//-------------------------------------------------------------------------------------------------------------------------------
template <class Keys, class T>
SingleList<Keys,T>::SingleList()
{
	header	= NULL;
	trailer = NULL;
	sz		= 0;
}
//-------------------------------------------------------------------------------------------------------------------------------
template <class Keys, class T>
long SingleList<Keys,T>::size ()
{
	return sz;
}
//-------------------------------------------------------------------------------------------------------------------------------
template <class Keys, class T>
int SingleList<Keys,T>::isEmpty()
{
	return header == NULL;	
}
// Thay the phan tu luu trong node do co dia chi luu trong p bang phan tu co gia tri e
template <class Keys, class T>
void SingleList<Keys,T>::replace(Node<Keys,T>* p,
                                         Keys k, T e)
{
	p->setKey(k);
	p->setElem(e);
}
//-------------------------------------------------------------------------------------------------------------------------------
template <class Keys, class T>
Node<Keys,T>* SingleList<Keys,T>::insertLast(Keys k, T e)
{
	Node<Keys,T> *q;
	q = new Node<Keys,T>;
	q->setKey(k);
	q->setElem(e);
	if(header==NULL)
	{
		header = q;
		trailer= q;
	}
	else{
		trailer->setNext(q);
		trailer = q;
	}
	sz++;
	return q;
}
//-------------------------------------------------------------------------------------------------------------------------------
template <class Keys, class T>
void SingleList<Keys,T>:: remove(Node<Keys,T>* p)
{
	Node<Keys,T> *p1;
	if(p==header)
	{
		if(size()==1)
		{
			header = NULL;
			trailer = NULL;
		}
		else
			header = header->getNext();
		sz--;
	}
	else
	{
		p1	= header;
		while(p1->getNext()!=p)			// Vong lap tim den vi tri cua node truoc node p
			p1 = p1->getNext();
		if(p1!=NULL)
		{					//Tim thay node can xoa
			if(p!=trailer)
				p1->setNext(p->getNext());
			else{
				trailer = p1;
				p1->setNext(NULL);
			}
			sz--;
		}
	}
	delete p;
}
template <class Keys, class T>
 Node<Keys,T>* SingleList<Keys,T>::getNode(Keys k)
 {
	Node<Keys,T> *p;
	p = header;
	while(p!=NULL && p->getKey()!=k)
	  p = p->getNext();
	return p;
 }
#endif
