#include<bits/stdc++.h>
#include<string.h>
#include<vector>
using namespace std;

class sinhvien {
	private :
		string id, ten,que,ns;
		double diem;
	public :
		//sinhvien();
		friend istream& operator >> (istream &in,sinhvien &a);
		friend ostream& operator << (ostream &out,sinhvien a);
		//void operator == (sinhvien &a);
};
//void operator == (sinhvien &a) {
	//return this->a;
//}
istream& operator >> (istream &in ,sinhvien &a) {
	cout << " nhap id : ";
	in >> a.id;
	cout << " nhap ten : "; cin.ignore();
	getline( in , a.ten );
	cout << " nhap que quan : ";
	getline(in, a.que);
	cout << " nhap ngay sinh : ";
	in >> a.ns ;
	cout << " nhap diem : " ;
	in >> a.diem;
	return in;
}
ostream& operator << (ostream &out,sinhvien a){
	cout << a.id <<" "<< a.ten << " " << a.que << " " << a.ns << " " << fixed << setprecision(2) << a.diem<<endl;
	return out;
}

int main() {
	sinhvien sv1;
	int n,k,j,m;
	cin>>n;
	vector<sinhvien> a(n);
	for (int i=0 ; i<n ; i++) {
		cin >> a[i];
	}
	cin>>sv1;
	a.push_back(sv1);
	
	for (int i=0 ; i<=n; i++) {
		cout << a[i];
	}
    do {
    	cin >> j;
	} while (j>n);
	
	a.insert(a.begin()+j, sv1);n=n+1;
	for (int i=0 ; i<=n; i++) {
		cout << a[i];
	}
	
	do {
    	cin >> k;
	} while (k>n);
	
		a.erase(a.begin() + k);
	
	
	//replace
}
