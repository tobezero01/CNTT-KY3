#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

using namespace std;


class CAUHOI{
	string cauhoi;
	string dung;
	string sai1, sai2, sai3;
	public:
		void nhap();
        void xuat();
};

void CAUHOI::nhap() {
    cin.ignore();
	getline(cin,cauhoi);
	cout<<"nhap tra loi dung: ";cin.ignore();
	getline(cin,dung);
	cout<<"nhap tra loi sai: ";cin.ignore();
	getline(cin,sai1);
	cout<<"nhap tra loi sai: ";cin.ignore();
	getline(cin,sai2);
	cout<<"nhap tra loi sai: ";cin.ignore();
	getline(cin,sai3);
}
void CAUHOI::xuat() {
	cout<< " "<<cauhoi<<endl;
	cout<<"A."<<dung<<endl;
	cout<<"B."<<sai1<<endl;
	cout<<"C."<<sai2<<endl;
	cout<<"D."<<sai3<<endl;
}
int main() {
	int n; cout << "nhap so cau hoi : ";cin>>n;
	vector<CAUHOI> a(n);
	for(int i=0; i<n; i++){
		cout<< "\nnhap cau hoi "<<i<<" : ";
		a[i].nhap();
	}
	for(int i=0; i<n; i++){
		a[i].xuat();
	}
	return 0;
}
