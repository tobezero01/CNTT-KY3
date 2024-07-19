#ifndef LIST_CPP
#define LIST_CPP 1
#include"Node.cpp"
template<class T>
class  List
{
	private:
		Node<T> *header;
		Node<T> *trailer;
		long count;  //luu so phan tu hien co cua danh sach
	public:
		List()
		{
			 header  = NULL;
			 trailer = NULL;
			 count   = 0;
		}
		long size()
		{   //Phuong thuc tra lai so phan tu hien co cua danh sach
			 return count;
		}
		//Phuong thuc cho biet danh sach co rong hay khong
		int  isEmpty()
		{ 
		   return count==0;
		}
		Node<T> *first(){ return header;}
		Node<T> *last() { return trailer;}
		///------- cac phuong thuc nay cai dat ben ngoai lop ----------------
		void replace(Node<T>*p,T e);
		Node<T> *insertAfter(Node<T> *p, T e);
		Node<T> *insertBefore(Node<T> *p, T e);
		Node<T> *insertFirst(T e);
		Node<T> *insertLast(T e);
		void remove(Node<T> *p);
		Node<T> *getNode(int i);
	};
	template<class T>
	void List<T>::replace(Node<T>*p, T e)
	{
		p->setElem(e);
	}
	//
	template<class T>
	Node<T>* List<T>::insertAfter(Node<T>*p, T e)
	{
		 Node<T>* q;
		 q = new Node<T>;
		 q->setElem(e);
		 if(p==trailer) //p la phan tu cuoi cua danh sach
		 {
			 p->setNext(q);
			 q->setPre(p);
			 trailer = q;
		 }
		 else //p khong la phan tu cuoi
		 {
			 q->setNext(p->getNext());
			 p->getNext()->setPre(q);
			 q->setPre(p);
			 p->setNext(q);
		 }
		 count++;
		 return q;
	 }
	 //-------------------------------------------------------------
	template <class T>
	Node<T>* List<T>::insertBefore(Node<T>*p, T e)
	{
		 Node<T>* q;
		 q = new Node<T>;
		 q->setElem(e);
		 if(p==header)    //p trung voi phan tu dau cua danh sach
		 {
			header->setPre(q);
			q->setNext(header);
			header = q;
		 }
		 else            //p khong trung voi phan tu dau cua danh sach
		 {
			  p->getPre()->setNext(q);
			  q->setPre(p->getPre());
			  q->setNext(p);
			  p->setPre(q);
		 }
		 count++;
		 return q;
	  }
	 //--------------------------------------------------------------
	  template <class T>
		Node<T>* List<T>::insertFirst(T e)
		{
			Node<T>* q;
			q = new Node<T>;
			q->setElem(e);
			if(isEmpty())
			{
				trailer = q;
				header  = q;
			}
			else
			{
			  q->setNext(header);
			  header->setPre(q);
			  header = q;
			}
			count++;
			return q;
		}
		//------------------------------------------------------------------
		template <class T>
		Node<T> * List<T>::insertLast(T e)
		{
			Node<T>* q;
			q = new Node<T>;
			q->setElem(e);
			if(isEmpty())
			{
				trailer = q;
				header  = q;
			}
			else
			{
				trailer->setNext(q);
				q->setPre(trailer);
				trailer = q;
			}
			count++;
			return q;
		}
	  //----------------------------------------------------------------------
		template <class T>
		void List<T>::remove(Node<T> *p)
		{
			if(p==header)
			{
				header = header->getNext();
				if(header!=NULL)
					header->setPre(NULL);
			}
			else
			if(p==trailer)
			{
				trailer = trailer->getPre();
				if(trailer!=NULL)
				   trailer->setNext(NULL);
			}
			else
			{
					p->getNext()->setPre(p->getPre());
					p->getPre()->setNext(p->getNext());
			 }
			 delete p;
			 count--;  
		}
	//--------------
 template<class T>
 Node<T>* List<T>::getNode(int i)
 {
	if(i<0 || isEmpty())
	  return NULL;
	Node<T> *p;
	int dem=0;
	p = header;
	while(dem<i && p!=NULL){
	  dem++;
	  p = p->getNext();
	}
	return p;
 }
#endif

