#ifndef NODE_CPP
#define NODE_CPP 1
#include"iostream"
using namespace std;
template<class T>
class Node
{
	private:
		T elem;
		Node *next;
		Node *pre;
	public:
		Node(){ next = NULL; pre = NULL;}		
		Node *getNext()
		{
			return next;
		}
		void setNext(Node *p)
		{
		    next = p;
		}
	 //---------------------------------
		Node *getPre()
		{
		  return pre;
		}
	 //---------------------------------
	  void setPre(Node *p)
	  {
		  pre = p;
	  }
	 //---------------------------------
		T getElem()
		{
			return elem;
		}
	 //----------------------------------
		void setElem(T e)
		{
		  elem = e;
		}
 };
#endif
