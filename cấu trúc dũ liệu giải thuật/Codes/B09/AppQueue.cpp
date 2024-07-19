#include"conio.h"
#include"Queue.cpp"
class AppQueue
{
	private:
	    Queue<float> *Q;
	public:
        AppQueue(){ Q=  new Queue<float>(100);}   
		int menu();
		void run();
		void size();
		void isEmpty();
		void enqueue();
		void dequeue();	
		void front();
};
int AppQueue::menu()
{
	cout<<"+++++++Menu++++++++";
	cout<<"\n1.Them phan tu vao Queue";
	cout<<"\n2.Lay phan tu ra khoi Queue:";
	cout<<"\n3.So phan tu hien co cua Queue:";
	cout<<"\n4.Queue rong hay day:";	
	cout<<"\n5.Phan tu dau la:";
	cout<<"\n6.Thoat chuong trinh:";
	int n;
	cin>>n;
	return n;
}
void AppQueue::run()
{
	int ch;
	do
	{
		system("cls");
		ch=menu();
		system("cls");
		switch(ch)
		{
			case 1:
				enqueue();
				break;
				
			case 2:
				dequeue();
				break;
			case 3:
				size();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				front();
				break;			
		}
	}while(ch!=6);
}
void AppQueue::size()
{
	cout<<"\nKich thuoc cua queue la:"<<Q->size();
	getch();
}
void AppQueue::enqueue()
{
	float x;
	cout<<"\nnhap vao phan tu can them vao :";
	cin>>x;
	if(Q->enqueue(x)==1)
	cout<<"ok";
	else
	cout<<"error";
	getch();
}
void AppQueue::dequeue()
{
     float x=0;     
     if(Q->dequeue(x))
       cout<<"Phan tu duoc lay ra:"<<x;      
	else
  	    cout<<"error";
	getch();
	
}
void AppQueue::isEmpty()
{
	if(Q->isEmpty()==1)
	cout<<"rong";
	getch();
}

void AppQueue::front()
{
cout<<	Q->front();
getch();
}
