#include<iostream>
#include<string>
#include<math.h>
using namespace std;

struct dapan{
	string	cautraloi;
	string	ds;
};
class BT{
	string cauhoi;
	dapan da[4];
	public:
		void nhap();
};
void BT::nhap(){
	cout<<"\nquestion: ";
	fflush(stdin);
	getline(cin,cauhoi);
	for(int i=0; i<4; i++){
		cout<<"\ndap an "<<i+1<<" : ";
		fflush(stdin);
		getline(cin,da[i].cautraloi);
		cout<<"dung/sai : ";
		fflush(stdin);
		getline(cin,da[i].ds);
	}
}
int main(){
	BT A;
	A.nhap();

   return 0;
}

