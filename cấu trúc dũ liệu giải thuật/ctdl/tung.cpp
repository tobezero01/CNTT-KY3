#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace ::std;
class sinhvien{
	string msv,ht,quequan,ngaysinh;
	float tbtl;
	public:
		void nhap();
		void xuat();
		void them(sinhvien& sv);
		void them_1(sinhvien &sv);
		void xoa_1(sinhvien &sv);
		void xoa_i(sinhvien &sv);
		void operator=(sinhvien& sv);
};
void sinhvien::nhap(){
	cout<<"masv\n";
	cin.ignore(0);
	getline(cin,msv);
	cout<<"ht\n";
	cin.ignore(0);
	getline(cin,ht);
	cout<<"que quan\n";
	cin.ignore(0);
	getline(cin,quequan);
	cout<<"ngay sinh";
	cin.ignore(0);
	getline(cin,ngaysinh);
	cout<<"diem tich luy\n";
	cin>>tbtl;
}
void sinhvien::xuat(){
	cout << setw(5) << left <<msv;		
	cout << setw(30) << left << ht;	
	cout << setw(20) << right << quequan; 
	cout << setw(30) << left << ngaysinh;
	cout << setw(20) << left << tbtl<<endl;
}
//void sinhvien::them(sinhvien &sv){
//	mas=sv.msv;
//	ht=sv.ht;
//	quequan=sv.quequan;
//	ngaysinh=sv.ngaysinh;
//	tbtl=sv.tbtl;
//}
int main(){
	sinhvien sv1,sv2,sv3;
	int n,x,y,i;
	cin>>n;
	cout<<"nhap so phan tu cua danh sach sv\n";
	std::vector<sinhvien> sv(n);
	for(int i=0;i<n;i++){
	sv[i].nhap();
	}
	cout << setw(5) << left << "MSV";		
	cout << setw(30) << left << "Ho ten";	
	cout << setw(20) << right << "Que quan"; 
	cout << setw(20) << left << "ngay sinh";
	cout << setw(20) << left << "trung binh"<<endl;
	for(int i=0;i<n;i++)
		sv[i].xuat();
	}
	//cout<<"nhap thong tin sinh vien can them"<<endl;
	//sv1.nhap();
	//sv.push_back(sv1);// them sinh vien vao cuoi danh sach
	//cout<<"nhap thong tin sinh vien can them"<<endl;
	//sv2.nhap();
	//cout<<"nhap vi tri can xoa"<<endl;
	//cin>>x;
	//vector<sinhvien>::iterator it;
	//it = sv.begin();
	//advance(it, x);
	//sv.insert(it, sv2);// them sinh vien vao vi tri thu i
	//cout<<"nhap vi tri can xoa"<<endl;
	//cin>>y;
	//sv.erase(sv.begin()+y);
	//sv.erase(sv.begin()+y,sv.end());
	


