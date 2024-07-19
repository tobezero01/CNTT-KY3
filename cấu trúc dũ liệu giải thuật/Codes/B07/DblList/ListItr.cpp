#include"List.cpp"
//Lop bo lap cua lop danh sach lien ket kep
template <class T>
class ListItr{     //list iterator
	private :
		 List<T>* theList;
		 Node<T>* cur;	
	public:
		ListItr(List<T> *L)
		{
			theList = L;		
			cur = theList->first();
		}
		void reset(){
             cur = theList->first();
        }
		int hasNext(){
			return cur!=NULL;				
		 }
		//----------------------------------------
		T next()
		{
			T o;
			o = cur->getElem();
			cur = cur->getNext();
			return o;
		}
};//End of class ListItr
