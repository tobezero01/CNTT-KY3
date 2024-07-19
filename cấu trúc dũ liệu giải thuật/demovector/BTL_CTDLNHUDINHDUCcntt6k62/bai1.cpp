//#ifndef VECTOR_H_
#define VECTOR_H_
#include<algorithm>
#include<cassert>
#include<iostream>

template <class T>
class reverse_iterator
{
	T *curr;	
	public:
		reverse_iterator(T *c=0) {curr=c;}
		reverse_iterator<T> &operator=(reverse_iterator<T> it) 
		{
			this->curr=it.curr; 
	 		return *this;
		}
		reverse_iterator<T> operator++()//++curr
		{
			curr--;
			return curr;
		}
		reverse_iterator<T> operator++(int)//++curr
		{
			reverse_iterator<T> tmp=curr;
			curr--;
			return tmp;
		}
		T &operator*() {return *curr;}
		bool operator!=(reverse_iterator<T> t) {return curr!=t.curr;}
};

template<class T>
class Vector {
	private:
	    unsigned int mySize;              //so phan tu vector
	    unsigned int myCapacity;          // kich thuoc bo nho
	
	    T * buffer;                     //mang chua cac phan tu vector
	public:
	    typedef T * iterator;
	    iterator begin() { return buffer; }    //vi tri bat dau bo lap xuoi
	    iterator end() { return buffer + mySize; } // vtri ket thuc bo lap xuoi
	    
	    typedef reverse_iterator<T> reverse_it;
		reverse_it rbegin() {return reverse_it(buffer+mySize-1);}   // vi tri bat dau bo lap nguoc
		reverse_it rend() {return reverse_it(buffer-1);}   // vi tri ket thuc bo lap nguoc
	    
	    Vector() : buffer(0), mySize(0), myCapacity(0) {}
	
	    ~Vector() {                  //ham huy
	        delete [ ] buffer;      //xoa bo nho dem
	    }
	
	    T& back() const {           // tra ve gia tri cuoi 
	        return buffer[mySize-1];
	    }
	
	    T& front() const {       // tra ve gia tri dau 
	        return buffer[0];
	    }
	
	    int capacity() {          //Ham lay dung luong bo nho dem
	        return myCapacity;
	    }
	
	    unsigned int size() {    //Ham lay so phan tu cua vector
	        return mySize;
	    }
	
	    bool empty() {           //Ham kiem tra vector co rong hay khong
	        return mySize == 0;
	    }
	
	    void pop_back() {       //Xoa phan tu o cuoi vector
	        mySize--;
	    }
	    void reserve(unsigned int); // mo rong vector
	    void push_back(T);    // them vao cuoi
	
	    T &operator [](unsigned int index) {  // nap chong toan tu []
	        return buffer[index];
	    }
	    
	    Vector &operator=(Vector<T> V)	//Nap chong toan tu = (gan hai vector)
		{
			this->mySize=V.mySize;
			this->myCapacity=V.myCapacity;
			if(myCapacity)	{			//Neu dung luong cua vector > 0
				this->buff=new T[myCapacity];	//Khoi tao bo nho chua cac phan tu
				for(int i=0;i<mySize;i++) 	//Sao chep cac phan tu
					this->buffer[i]=V.buffer[i];
			}
			else this->buffer=0;
			return *this;
		}
	    void insert(unsigned int , T); // ham chen vao vi tri
	
	    /*^^virtual*/ void insert(iterator, T); 
	
	    void erase(unsigned int,T);
	
	    void erase(iterator); // ham xoa qua vi tri bo lap
	

};

// MEMBER FUNCTIONS
template<class T>

void Vector<T>::reserve(unsigned int newCap) {   // mo rong vector
    if(buffer == 0) {
        mySize = 0;
        myCapacity = 0;
    }
    if(newCap <= myCapacity) {     //dung luong moi < dung luong hien tai
        return;
    }
    myCapacity = newCap;               // mo rong dung luong
    T * newBuffer = new T[myCapacity]; //Khoi tao bo nho moi lon hon
    
    for(int i=0;i<mySize;i++) 	    //Luu lai cac phan tu da co trong vector
		newBuffer[i]=buffer[i];
    delete [ ] buffer;          ///Xoa bo nho dem cu
    buffer = newBuffer;       //Tro lai bo nho dem 
}

template<class T>

void Vector<T>::push_back(T value) {   //them phan tu vao cuoi vector
    if(mySize >= myCapacity) {
        reserve(myCapacity*2);   // het dung luowng thi mo rong
    }
    buffer[mySize++] = value; // them phan tu
}

template<class T>

void Vector<T> ::insert(unsigned int k, T x) {    // chen x vao vi tri k
    if (myCapacity ==mySize) reserve(myCapacity*2);  // het dung luowng thi mo rong
    for (int i=mySize-1;i>=k;i--){   // dich cac phan tu ve cuoi vector
    	buffer[i+1] = buffer[i];
	}
	buffer[k]=x;          //gan vi tri x vao k
	mySize++;          //tang so phan tu vector
}

template<class T>
void Vector<T> :: erase(unsigned int k,T o) {   // xoa phan tu vi tri k
	if(k>mySize-1) return ;
	o = buffer[k];
	int r=k;
	while (r < mySize -1){
		buffer[r]=buffer[r+1];
		k++;
	}
	mySize--;
}
int main () {
}
