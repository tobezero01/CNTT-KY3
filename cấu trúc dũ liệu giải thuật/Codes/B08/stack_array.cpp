#ifndef STACK_CPP
#define STACK_CPP 1
template<class T>
class Stack
{
 private:
	T *S; //Mang chua cac phan tu cua ngan xep
	int N;//Kich thuoc hien tai cua mang S
	int t;//Luu dia chi so cua phan tu duoc dua vao cuoi cung cua Stack
 public:
	 Stack();
	 ~Stack();
	 int size();
	 int isEmpty();
	 int pop(T &o);
	 void push(T o);
	 int top();
};

//Cac phuong thuc duoc dinh nghia ben ngoai lop
 template<class T>
 Stack<T>::Stack() //Phuong thuc khoi tao (cau tu)
 {
	 S = new T[1];
	 N = 1;
	 t = -1;
 }
//-------------------------
 template<class T>
 Stack<T>::~Stack() //Ham huy (huy tu)
 {
	delete S;
 }
//-------------------------
//Ham lay so phan tu cua ngan xep
 template<class T>
 int Stack<T>::size() 
 {
	return t+1;
 }
///--------------------------
//Phuong thuc kiem tra ngan xep co rong hay khong
 template<class T>
 int Stack<T>::isEmpty()
 {
	return t==-1;
 }
 //-------------------------
 //Phuong thuc lay gia tri cua phan tu o dinh ngan xep
 template<class T>
 T Stack<T>::top()
 {
	return S[t];
 }
//------------------------
//Phuong thuc loai bo phan tu o dinh ngan xep
template<class T>
int Stack<T>::pop(T &o)
{
  if(isEmpty())
		return 0;
  else
	{
		o = S[t];
		t--;
		return 1;
	}
}
//-------------------------
//Phuong thuc them mot phan tu vao ngan xep
template<class T>
void Stack<T>::push(T o)
{
  T *a;
  if(t==N-1) //Neu ngan xep da day thi mo rong ngan xep len gap doi
  {
	 N = 2*N; //Mo rong ngan xep len gap doi
	 a = new T[N]; //Cap bo nho cho mang moi co kich thuoc gap doi
	 for(int i=0;i<=t;i++) //Sao chep cac phan tu cua ngan xep sang bo mang moi
		a[i] = S[i];
	 delete S; 	//Huy bo nho cu
	 S = a;		//Tro S den bo nho moi
  }
  t++;
  S[t] = o;
}
#endif
