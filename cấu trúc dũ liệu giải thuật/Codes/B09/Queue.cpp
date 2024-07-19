#ifndef QUEUE_CPP
#define QUEUE_CPP 1
#include"iostream"
using namespace std;
template<class T>
class Queue
{
	private: 
    	int N;	//So phan tu cua hang doi
    	T *Q;	//Mang luu cac phan tu cua hang doi
    	int f,r; //Hai con tro front va rear
	public:
        Queue();
        Queue(int n);
        ~Queue();
        int isEmpty();
        int size();
        T front();
        int enqueue(T x);
        int dequeue(T &x);       
};

//Phan dinh nghia cac phuong thuc ngoai lop
template<class T>
Queue<T>::Queue() //Cau tu khong co doi
{
    N=0;
    Q=NULL;
    f=0;
    r=0;
}

//Cau tu co doi, n la so phan tu cua hang doi
template<class T>
Queue<T>::Queue(int n) 
{
	N=n;
	Q= new T[N+1];
	f=0;
    r=0;
}

//Phuong thuc lay so phan tu hien co cua hang doi
template<class T>
int Queue<T>::size()
{
	return (N-f+r)%N;
}

//Kiem tra xem hang doi co rong khong
template<class T>
int Queue<T>:: isEmpty()
{
	return r==f;
}

//Lay gia tri o dau hang doi
template<class T>
T Queue<T>::front()
{
	return Q[f];
}

//Them mot phan tu vao hang doi
template<class T>
int Queue<T> :: enqueue(T x)
{
    if(size()==N-1)
        return 0;
        //Hoac phat trien mang (gia tang theo hang hoac gap doi)
    else
    {
    	Q[r]=x;
    	r=(r+1)%N;
    	return 1;
    }
}

//Xoa mot phan tu o dau hang doi
template<class T>
int Queue<T>::dequeue(T &x)
{
    if(isEmpty())
        return 0;
    else
      {
        x = Q[f];
        f=(f+1)%N;
        return 1;
      }
}
#endif


