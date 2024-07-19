#include"iostream"
#include"cstring"
//#include"cstdlib"

using namespace std;
//--------------------------khai bao danh sach lien ket don cac so nguyen---------------
//khai bao cau truc mot node
struct node{
	int data; //du lieu chua trong mot node
	struct node *pNext;//con tro dung de lien ket giua cac node
};
typedef struct node NODE;//thay the struct node thanh NODE

// khai bao cau truc cua danh sach lien ket don
struct list{
	NODE *pHear;//node quan li dau danh sach
	NODE *pTail;//node quan li cuoi danh sach
};

typedef struct list LIST;//thay the struct list thanh LIST

//-------------khoi tao danh sach lien ket don cac so nguyen------------

void khoi_tao(LIST &l){
	//cho hai node tro den null - vi danh sach lien ket chua co ptu
	l.pHear=NULL;
	l.pTail=NULL;
}

//ham tao khoi tao mot node
NODE *khoitao_NODE(int x){
	NODE *p=new NODE;//cap phat vung nho cho NODE p
	if (p==NULL){
		cout<<"\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data =x;//truyen gia tri x vao cho data
	p->pNext=NULL;//dau tien khai bao node thi node do chua co lien ket den node nao het ==>con tro cua no sex tro den null 
	return p;//tra ve NODE p vua khoi tao
}

//ep kieu 
int chuyen(string s){
	int so=0, n=s.length(), kt=0;
	for(int i=0; i<1; i++){
		if(s[0]=='-') kt=1;
	}
	if(kt==0){
	for(int i=0; i<n; i++){
		int x= s[i]-48;
		so=so*10+x;
	}
	return so;
	}
	else {
	for(int i=1; i<n; i++){
		int x= s[i]-48;
		so=so*10+x;
	}
	return -1*so;	
	}
}

// ham them node vao dau danh sach lien ket
void themvaodau(LIST &l, NODE *p){
	//danh sach dang rong
	if(l.pHear==NULL){
		l.pHear=l.pTail=p;//node dau cung chinh la node cuoi
	}
	else{
		p->pNext = l.pHear;//cho con tro cua node can them lien ket dem node dau pHead
		l.pHear = p;//cap nhat pHead chinh la node p
	}
}

//ham them node vao cuoi danh sach lien ket don
void themvaocuoi(LIST &l, NODE *p){
	//danh sach dang rong
	if(l.pHear==NULL){
		l.pHear=l.pTail=p;//node dau cung chinh la node cuoi
	}
	else{
		l.pTail->pNext = p;//cho con tro cua pTail lien ket voi node p
		l.pTail = p;//cap nhat lai p la node pTail
	}
}

//kiem tra so nguyen to tra ve 0 neu la SNT, tra ve 1 neu ko la SNT
int kiemtraSNT(int n){
	if(n<2) return 1;
	for(int i=2;i*i<=n;i++)
	if(n%i==0) return 1;
	return 0;
}

//xoa phan tu dau danh sach
void xoadau(LIST &l){
	//kiem tra danh sach
	if(l.pHear == NULL){
		return;
	}
	else{
		NODE *p=l.pHear; //la node de xoa
		l.pHear=l.pHear->pNext;
		delete p;
	}
}
//xoa cuoi
void xoacuoi(LIST &l){
	//kiem tra danh sach
	if(l.pHear == NULL){
		return;
	}
	for(NODE *k=l.pHear; k !=NULL; k=k->pNext){
		if(k->pNext==l.pTail){
			delete l.pTail;//xoa phan tu cuoi
			k->pNext=NULL;//cho con tro cua node ke cuoi tro den null
			l.pTail=k;//cap nhat lai node cuoi
		}
	}
}
//xoa node bat ki
void xoanode(LIST &l, NODE *p){
	if(l.pHear==p){
		xoadau(l);
		return;
	}
	if(l.pTail==p){
		xoacuoi(l);
		return;
	}
	NODE *g= new NODE;
	for(NODE *k=l.pHear; k!=NULL; k=k->pNext){
		if(k==p){
			g->pNext=k->pNext;
			delete k;
		}
		g=k;
	}
}

void menu(){
	cout<<"\n1.  Nhap day so";
	cout<<"\n2.  In day so";
	cout<<"\n3.  Them phan tu vao danh sach , vi tri them do ban chon";
	cout<<"\n4.  Dem xem mot phan tu khac 0 xuat hien bao nhieu lan";
	cout<<"\n5.  Kiem tra ba so chan duong lien tiep";
	cout<<"\n6.  Sap xep danh sach tang dan";
	cout<<"\n7.  Sap xep danh sach giam dan";
	cout<<"\n8.  Xoa so nguyen to trong danh sach";
	cout<<"\n9.  Xoa cac so trung nhau trong danh sach , chi giu lai mot so";
	cout<<"\n10. Hien lai menu";
	cout<<"\n0.  Thoat";
}
class dayso{
	list l;
	public:
		void nhap_dayso();
		void dem_so();
		void them_phantu();
		void sochan_canhnhau();
		void sapxep_danhsach_tangdan();
		void sapxep_danhsach_giamdan();
		void xoa_songuyento();
		void xuat_dayso();
		void xoa_cacphantutrungnhau();
};
void dayso::nhap_dayso(){
	khoi_tao(l);
	string x , x2="#";
	cout<<"\nNhap dau # de ket thuc day so";
	while(1){
		int a;
		cout<<"\nNhap gia tri so nguyen: ";
		cin>>x;
		if(x==x2) break;
		a=chuyen(x);
		NODE *p=khoitao_NODE(a);// khoi tao mot node so nguyen
		themvaocuoi(l,p);//them node p vao dau danh sach lien ket don
}
}
void dayso::xuat_dayso(){
	for(NODE *k=l.pHear; k !=NULL; k= k->pNext){
		cout<<k->data<<"  ";
	}
}

void dayso::dem_so(){
	int m;
	int dem=0;
	nhap:
	cout<<"\nMoi ban nhap so cam dem va so ban nhap phai khac so 0: ";
	cin>>m;
	if(m==0) goto nhap;
	for(NODE *k=l.pHear;k !=NULL; k= k->pNext)
		if(k->data == m ) dem++;
	cout<<"\nSo "<<m<<" xuat hien so lan la: "<<dem;
} 
void dayso::sochan_canhnhau(){
	cout<<"\nVi tri ba so chan duong lien tiep la: ";
	int dem=0, kt=0;
	for(NODE *k=l.pHear; k !=NULL; k=k->pNext){
		dem=dem+1;
		if(k->data>0&&k->pNext->data>0&&k->pNext->pNext->data>0){
			if(k->data%2==0 && k->pNext->data%2==0 && k->pNext->pNext->data%2==0){
				cout<<"\t("<<dem<<","<<dem+1<<","<<dem+2<<")\t";
				kt=1;
		}
		}
		if(k->pNext->pNext->pNext==NULL)
		break;
	}
	if(kt==0) cout<<"Khong co ba so chan duong nao dung canh nhau";
}
void dayso::them_phantu(){
		int a, vt;
		cout<<"\nNhap gia tri so nguyen can them: ";
		cin>>a;
		NODE *p=khoitao_NODE(a);
		int n=0, dem=0;
		for(NODE *k= l.pHear; k != NULL; k= k->pNext) n++;
	nhaplai:
		cout<<"\nNhap vi tri can them: ";
		cin>>vt;
		if(vt<=0||vt>n+1) {
			cout<<"\nDanh sach khong co vi tri nay , moi ban nhap lai vi tri !!!";
			goto nhaplai;
		}
		
		if(l.pHear ==NULL || vt==1) themvaodau(l,p);
		else if (vt == n+1)	themvaocuoi(l,p);
		else {
		NODE *g = new NODE;
		for(NODE *k= l.pHear; k != NULL; k= k->pNext){
			dem++;
			if(dem==vt){
				p->pNext=k;
				g->pNext=p;				
			}
			g=k;
		}
	}
}

void dayso::sapxep_danhsach_tangdan(){
for(NODE *i= l.pHear; i!=NULL;i=i->pNext)
 {
  for(NODE *j=i->pNext; j!=NULL; j=j->pNext)
  {
    if(i->data>j->data) 
	{
       int tam=i->data;
       i->data=j->data;
       j->data=tam;
     }
  }
 }
}

void dayso::sapxep_danhsach_giamdan(){
		for(NODE *i= l.pHear; i!=NULL;i=i->pNext)
 {
  for(NODE *j=i->pNext; j!=NULL; j=j->pNext)
  {
    if(i->data<j->data) 
	{
       int tam=i->data;
       i->data=j->data;
       j->data=tam;
     }
  }
 }	
}
void dayso::xoa_songuyento(){
	for(NODE *k=l.pHear; k!=NULL; k=k->pNext){
     	int c=kiemtraSNT(k->data);
     	if(c==0){
     		xoanode(l,k);
		 }
	 }
}
void dayso::xoa_cacphantutrungnhau(){
	for(NODE *i= l.pHear; i!=NULL;i=i->pNext)
 {
  for(NODE *j=i->pNext; j!=NULL; j=j->pNext){
  		if(i->data==j->data)
  			xoanode(l, j);
  }
  }
}
int main(){
	dayso a;
	menu();
	while(1){
		int luachon;
		cout<<"\nMoi ban nhap lua chon: ";
		cin>>luachon;
		switch(luachon){
			case 0:
				break;
			case 1:
				cout<<"\nMoi ban nhap day so:";
				a.nhap_dayso();
				break;
			case 2:
				cout<<"\nDay so la: ";
				a.xuat_dayso();
				break;
			case 3:
				a.them_phantu();
				cout<<"\nDay so sau khi them phan tu la: ";
				a.xuat_dayso();
				break;
			case 4:
				a.dem_so();
				break;
			case 5:
				a.sochan_canhnhau();
				break;
			case 6:
				a.sapxep_danhsach_tangdan();
				cout<<"\nDay so sau khi sap xep tang dan la: ";
				a.xuat_dayso();
				break;
			case 7:
				a.sapxep_danhsach_giamdan();
				cout<<"\nDay so sau khi sap xep giam dan la: ";
				a.xuat_dayso();
				break;
			case 8:
				a.xoa_songuyento();
				cout<<"\nDay so sau khi xoa so nguyen to la: \n";
				a.xuat_dayso();
				break;
			case 9:
				a.xoa_cacphantutrungnhau();
				cout<<"\nDay so sau khi xoa cac phan tu trung nhau la: \n";
				a.xuat_dayso();
				break;
			case 10:
				menu();
				break;
			default: 
			cout<<"\n\t\t\t\t\t\t\t!NHAP LAI";
			break;	
		}
		cout<<"\n\t\t\t\t\t-------------------------------------";
			if(luachon==0) break;
		}
	return 0;
}
