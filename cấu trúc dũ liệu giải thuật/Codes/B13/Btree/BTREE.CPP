#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP 1
#include "BTreeNod.cpp"
template <class T>
class BTree {
private:
	BTreeNode<T>* root;
	int n;
public:
    BTree(){ root=NULL;  n=0;}
	BTreeNode<T>* getRoot(){ return root;}
	int isEmpty(){
        return root==NULL;
    }           
	int size(){return n;}
	int isInternal(BTreeNode<T>*v){
	   return(v->hasLeft()|| v->hasRight()) ;           
    }
	int isExternal(BTreeNode<T>*v) {
	    return (!v->hasLeft()) && (!v->hasRight()) ;           
	}
	int isRoot(BTreeNode<T>*v){
		return v->getParent()==NULL;           
	}
	void preOrder(BTreeNode<T>*,void (*visit)(BTreeNode<T>*));
	void inOrder(BTreeNode<T>*,void (*visit)(BTreeNode<T>*));
	void postOrder(BTreeNode<T>*,void (*visit)(BTreeNode<T>*));
	BTreeNode<T>* insert(BTreeNode<T>*,int,T);
	void remove(BTreeNode<T>*);
};
template <class T>
void BTree<T>::inOrder(BTreeNode<T>* v, 
                        void (*visit)(BTreeNode<T>* a)){
	 if(v!=NULL){
        inOrder(v->getLeft(),visit);
        visit(v);
        inOrder(v->getRight(),visit);
    }
}     
template <class T>
void BTree<T>::postOrder(BTreeNode<T>* v, 
                       void (*visit)(BTreeNode<T>* a)){
     if(v!=NULL){
         postOrder(v->getLeft(),visit);
         postOrder(v->getRight(),visit);
         visit(v);
     }
}     
template <class T>
void BTree<T>::preOrder(BTreeNode<T>* v,
                       void (*visit)(BTreeNode<T>* a)){
     if(v!=NULL){
         visit(v);
         preOrder(v->getLeft(),visit);
         preOrder(v->getRight(),visit);
     }
}     
template <class T>
BTreeNode<T>* BTree<T>::insert(BTreeNode<T>* parent, 
                                      int LeftRight,T elem){
     BTreeNode<T>* p = new BTreeNode<T> ;
     p->setParent(parent);
     p->setElem(elem);
     if (parent==NULL)
        root = p;
     else
        if(LeftRight==1) 
           parent->setRight(p);
        else 
		   parent->setLeft(p);
     n++;
     return p;
}
template <class T>
void BTree<T>::remove(BTreeNode<T>*v){
	  if(v!=NULL){
		  remove(v->getLeft());
		  remove(v->getRight());
		  delete v;
     }
}
#endif
