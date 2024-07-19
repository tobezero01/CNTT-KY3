#include<iostream>
using namespace std;
#ifndef __vector__cpp__
#define __vector__cpp__

template <class T>
class vector_reverse_iterator
{
	T *curr;	
	public:
		vector_reverse_iterator(T *c=0) {curr=c;}
		vector_reverse_iterator<T> &operator=(vector_reverse_iterator<T> it) 
		{
			this->curr=it.curr; 
			return *this;
		}
		vector_reverse_iterator<T> operator++()//++curr
		{
			curr--;
			return curr;
		}
		vector_reverse_iterator<T> operator++(int)//++curr
		{
			vector_reverse_iterator<T> tmp=curr;
			curr--;
			return tmp;
		}
		T &operator*() {return *curr;}
		bool operator!=(vector_reverse_iterator<T> t) {return curr!=t.curr;}
};

template<class T>
class Vector
{
	private:
		int cap,num;	//Hai bien lan luot la kich thuoc bo nho va so phan tu cua vector
		T *buff;		//Mang chua cac phan tu cua vector
	public:
		Vector() {		//Ham khoi tao khong co doi
			cap=num=0; 	//So phan tu va kich thuoc bo nho bang nhau
			buff=0;		//Bo dem chua cac phan tu
		}
		Vector(int k,T x) {	//Ham khoi tao co hai doi la so phan tu k va gia tri mac dinh x
			cap=num=k; 		//So phan tu va kich thuoc bo nho bang k
			buff=new T[k]; 	//Tao bo nho chua cac phan tu kich thuoc k
			for(int i=0;i<k;i++) //Gan k cac phan tu co gia tri la x
				buff[i]=x;
		}
		~Vector() {					//Ham huy
			if(buff) delete[]buff; 	//Xoa bo nho dem
		}
		int capacity() {			//Ham lay dung luong bo nho dem
			return cap;
		}
		int size() {				//Ham lay so phan tu cua vector
			return num;
		}
		bool empty() {
			return num==0;			//Ham kiem tra vector co rong hay khong
		}
		void pop_back() {
			if(num>0) num--;		//Xoa phan tu o cuoi vector
		}
		void extend(int newcap)		//Mo rong vector
		{
			if(newcap<=cap) return;	//Neu dung luong moi nho hon dung luong hien tai
			cap=newcap;				//Mo rong dung luong cua vector
			T *temp=new T[cap];		//Khoi tao bo nho moi lon hon
			for(int i=0;i<num;i++) 	//Luu lai cac phan tu da co trong vector
				temp[i]=buff[i];	
			if(buff) delete []buff;	//Xoa bo nho dem cu
			buff= temp;				//Tro lai bo nho dem toi temp
		}
		T &back() {
			return buff[num-1];		//Ham lay gia tri cuoi cung cua vector
		}
		void push_back(T x)			//Ham them phan tu vao cuoi vector
		{
			if(num==cap) extend(cap*2);	//Neu het dung luong thi mo rong
			buff[num++]=x;					//Them phan tu
		}
		T &operator[](int k) {	//Nap chong toan tu []
			return buff[k];
		}
		void insert(int k,T x)	//Them phan tu co gia tri x vao vi tri k
		{
			if(cap==num) extend(cap*2); //Neu so phan tu bang dung luong thi mo rong
			for(int i=num-1;i>=k;i--) 		//Dich chuyen cac phan tu ve cuoi vector
				buff[i+1]=buff[i];
			buff[k]=x;			//Gan gia tri x vao vi tri k
			num++;				//Tang so phan tu cua vector
		}
		Vector &operator=(Vector<T> V)	//Nap chong toan tu = (gan hai vector)
		{
			this->num=V.num;
			this->cap=V.cap;
			if(cap)				//Neu dung luong cua vector > 0
			{
				this->buff=new T[cap];	//Khoi tao bo nho chua cac phan tu
				for(int i=0;i<num;i++) 	//Sao chep cac phan tu
					this->buff[i]=V.buff[i];
			}
			else this->buff=0;
			return *this;
		}
		typedef T *iterator; 
		iterator begin() {return buff;}
		iterator end() {return buff+num;}
		typedef vector_reverse_iterator<T> reverse_iterator;
		reverse_iterator rbegin() {return reverse_iterator(buff+num-1);} 
		reverse_iterator rend() {return reverse_iterator(buff-1);} 
};
#endif

int main()
{
	Vector<int> V(7,6);
	cout<<"\nVector ban dau: ";
	for(int i=0;i<V.size();i++) 
		cout<<V[i]<<" ";
	//------------------------------------
	for(int i=0;i<V.size();i++) V[i]=i*i;
	cout<<"\nVector binh phuong: ";
	for(int i=0;i<V.size();i++) cout<<V[i]<<" ";
	//------------------------------------
	V.push_back(11);
	V.push_back(13);
	V.insert(2,20);
	cout<<"\nVector: "; for(int i=0;i<V.size();i++) cout<<V[i]<<" ";
	//------------------------------------
	cout<<"\nDuyet: ";  for(Vector<int>::iterator it=V.begin();it!=V.end();it++) cout<<*it<<"\t";	
	cout<<"\nDuyet auto: "; for(auto x:V) cout<<x<<" ";
	cout<<"\nNguoc: "; for(auto it=V.rbegin();it!=V.rend();it++) cout<<*it<<" ";
}
