#ifndef HASHTABLE_H
#define HASHTABLE_H 1
#include"SList.cpp"
template<class Keys,class T>
class Hashtable
{
	 private:
		 int N;
		 SingleList<Keys,T> *table;
	 public:
		 Hashtable(int n);
		 Node<Keys,T> *Add(Keys key, T obj,  int (*hash)(Keys,int));
		 void Remove(Keys key, int (*hash)(Keys,int));
		 Node<Keys,T> * Find(Keys key, int (*hash)(Keys,int));
		 int Contains(Keys key, int (*hash)(Keys,int));
		 int Count();
};
template<class Keys,class T>
Hashtable<Keys,T>::Hashtable(int n)
 {
		N = n;
		table=  new SingleList<Keys,T>[N];
 }
template<class Keys,class T>
Node<Keys,T>* Hashtable<Keys,T>::Add(Keys key, T obj, 
                                  int (*hash)(Keys,int))
{
	  Node<Keys,T> *p;
	  int h = hash(key,N); //hash la mot con tro ham
	  p = table[h].getNode(key);
	  if(p==NULL)
		 return table[h].insertLast(key,obj);
	  else
		 return NULL;
 }
template<class Keys,class T>
void Hashtable<Keys,T>::Remove(Keys key, 
                                 int (*hash)(Keys,int))
{
	 int h = hash(key,N);
	 Node<Keys,T> *p;
	 p = table[h].getNode(key);
	 if(p!=NULL)
		 table[h].remove(p);
}
template<class Keys,class T>
Node<Keys,T> * Hashtable<Keys,T>::Find(Keys key, 
                                int (*hash)(Keys,int))
{
	 int h = hash(key,N);
	 return  table[h].getNode(key);
}
template<class Keys,class T>
int Hashtable<Keys,T>::Contains(Keys key, int (*hash)(Keys,int))
{
	 int h = hash(key,N); //hash la mot con tro ham
	 if(table[h].getNode(key)==NULL)
		 return 0;
	 else
		 return 1;
}
template<class Keys,class T>
int Hashtable<Keys,T>::Count()
{
	  int t = 0;
	  for(int i=0;i<N;i++)
		 t = t + table[i].size();
	  return t;
}
#endif
