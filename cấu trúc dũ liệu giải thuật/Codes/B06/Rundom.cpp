#include"cstdlib"
#include"iostream"
#include"ctime"
#include"string"
#include"vector"
using namespace std;

int random(){
	srand(time(NULL));
	int res = rand();
	return res%4;
}
class CAUHOI{
	string cauhoi;
	string dung;
	string sai1, sai2, sai3;
	public:
		void nhap();
		void in(string &dapan);
		int kiemtracaudung();
};

void CAUHOI::nhap(){
	fflush(stdin);
	getline(cin,cauhoi);
	cout<<"nhap tra loi dung: ";
	fflush(stdin);
	getline(cin,dung);
	cout<<"nhap tra loi sai: ";
	fflush(stdin);
	getline(cin,sai1);
	cout<<"nhap tra loi sai: ";
	fflush(stdin);
	getline(cin,sai2);
	cout<<"nhap tra loi sai: ";
	fflush(stdin);
	getline(cin,sai3);
}
void CAUHOI::in(string &dapan){
	int kt=random();
//	cout<<"\n chao cac ban"<<kt;
	cout<<cauhoi<<endl;
	if(kt==0){
		cout<<"A."<<dung<<endl;
		cout<<"B."<<sai1<<endl;
		cout<<"C."<<sai2<<endl;
		cout<<"D."<<sai3<<endl;
		dapan='A';
	}
	if(kt==1){
		cout<<"A."<<sai1<<endl;
		cout<<"B."<<dung<<endl;
		cout<<"C."<<sai2<<endl;
		cout<<"D."<<sai3<<endl;
		dapan='B';
	}
	if(kt==2){
		cout<<"A."<<sai1<<endl;
		cout<<"B."<<sai2<<endl;
		cout<<"C."<<dung<<endl;
		cout<<"D."<<sai3<<endl;
		dapan='C';	}
	if(kt==3){
		cout<<"A."<<sai1<<endl;
		cout<<"B."<<sai2<<endl;
		cout<<"C."<<sai3<<endl;
		cout<<"D."<<dung<<endl;
		dapan='D';
	}
}
int main(){
	
	int n; cout << "nhap so cau hoi : ";cin>>n;
	std::vector<CAUHOI> a(n);
	string dapan, cautl;
	for(int i=1; i<=n; i++){
		cout<< "\nnhap cau hoi "<<i<<" : ";
		a[i].nhap();
	}
	cout<<"\n------------------------------------------------\n";
	for(int i=1; i<=n; i++){
		cout<<endl<<i<<".";
		a[i].in(dapan);
		cout<<"\nDap an cua ban :";
		cin>>cautl;
		if(cautl==dapan){
			cout<<"True\n";
		}
		else cout<<"False\n";
	}
	
	return 0;
}
