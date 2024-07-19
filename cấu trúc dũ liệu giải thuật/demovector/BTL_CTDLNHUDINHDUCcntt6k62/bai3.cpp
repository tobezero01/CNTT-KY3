#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include <ctime>

using namespace std;


typedef struct {
	string deBai;
	string dung;
	string sai1,sai2,sai3;
} tracNghiem;

class DETHI{
	private:
		string dapAn;
		vector<tracNghiem> cauHoi;
	public:
		void docFile(ifstream& FileCauHoi,string Filename);
		void inDeThi();
		void kiemtra();
};
void DETHI::docFile(ifstream& FileCauHoi, string Filename){
	tracNghiem arrCauHoi;
	FileCauHoi.open(Filename);
	if (!FileCauHoi) {
		cout <<"Error : can't not open !!";
		exit(0);
	}
	while(!FileCauHoi.eof()) {
		getline(FileCauHoi, arrCauHoi.deBai, '\n');
		getline(FileCauHoi, arrCauHoi.dung, '\n');
		getline(FileCauHoi, arrCauHoi.sai1, '\n');
		getline(FileCauHoi, arrCauHoi.sai2, '\n');
		getline(FileCauHoi, arrCauHoi.sai3, '\n');
		cauHoi.push_back(arrCauHoi);
	}
	FileCauHoi.close();
}

void DETHI::inDeThi() {
	int kt[cauHoi.size()];
	//srand(int( time(NULL)));
	cout<< "de thi cua ban la : \n\n";
	for(int i=0;i<cauHoi.size();i++){
		srand(int( time(NULL)));
		kt[i]=rand()%24;
		if(kt[i]==0){
			cout<< cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].dung<<endl;
			cout<<"B."<<cauHoi[i].sai1<<endl;
			cout<<"C."<<cauHoi[i].sai2<<endl;
			cout<<"D."<<cauHoi[i].sai3<<endl;
			dapAn='A';
        }
	    if(kt[i]==1){  
	    	cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].dung<<endl;
			cout<<"B."<<cauHoi[i].sai1<<endl;
			cout<<"C."<<cauHoi[i].sai3<<endl;
			cout<<"D."<<cauHoi[i].sai2<<endl;
			dapAn='A';
	    }
	    if(kt[i]==2){
	    	
			cout <<cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].dung<<endl;
			cout<<"B."<<cauHoi[i].sai2<<endl;
			cout<<"C."<<cauHoi[i].sai1<<endl;
			cout<<"D."<<cauHoi[i].sai3<<endl;
			dapAn='A';	
	    }
	    if(kt[i]==3){
	    	cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].dung<<endl;
			cout<<"B."<<cauHoi[i].sai2<<endl;
			cout<<"C."<<cauHoi[i].sai3<<endl;
			cout<<"D."<<cauHoi[i].sai1<<endl;
			dapAn='A';
	    }
	    if(kt[i]==4){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].dung<<endl;
			cout<<"B."<<cauHoi[i].sai3<<endl;
			cout<<"C."<<cauHoi[i].sai2<<endl;
			cout<<"D."<<cauHoi[i].sai1<<endl;
			dapAn='A';
	    }
	    if(kt[i]==5){
	    	cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].dung<<endl;
			cout<<"B."<<cauHoi[i].sai3<<endl;
			cout<<"C."<<cauHoi[i].sai1<<endl;
			cout<<"D."<<cauHoi[i].sai2<<endl;
			dapAn='A';
	    }
	    if(kt[i]==6){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai1<<endl;
			cout<<"B."<<cauHoi[i].dung<<endl;
			cout<<"C."<<cauHoi[i].sai2<<endl;
			cout<<"D."<<cauHoi[i].sai3<<endl;
			dapAn='B';
	    }
	    if(kt[i]==7){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai1<<endl;
			cout<<"B."<<cauHoi[i].dung<<endl;
			cout<<"C."<<cauHoi[i].sai3<<endl;
			cout<<"D."<<cauHoi[i].sai2<<endl;
			dapAn='B';
	    }
	    if(kt[i]==8){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai2<<endl;
			cout<<"B."<<cauHoi[i].dung<<endl;
			cout<<"C."<<cauHoi[i].sai1<<endl;
			cout<<"D."<<cauHoi[i].sai3<<endl;
			dapAn='B';
	    }
	    if(kt[i]==9){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai2<<endl;
			cout<<"B."<<cauHoi[i].dung<<endl;
			cout<<"C."<<cauHoi[i].sai3<<endl;
			cout<<"D."<<cauHoi[i].sai1<<endl;
			dapAn='B';
		}
	    if(kt[i]==10){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai3<<endl;
			cout<<"B."<<cauHoi[i].dung<<endl;
			cout<<"C."<<cauHoi[i].sai1<<endl;
			cout<<"D."<<cauHoi[i].sai2<<endl;
			dapAn='B';
	    }
	    if(kt[i]==11){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai3<<endl;
			cout<<"B."<<cauHoi[i].dung<<endl;
			cout<<"C."<<cauHoi[i].sai2<<endl;
			cout<<"D."<<cauHoi[i].sai1<<endl;
			dapAn='B';
	    }
	    if(kt[i]==12){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai1<<endl;
			cout<<"B."<<cauHoi[i].sai2<<endl;
			cout<<"C."<<cauHoi[i].dung<<endl;
			cout<<"D."<<cauHoi[i].sai3<<endl;
			dapAn='C';
	    }
	    if(kt[i]==13){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai1<<endl;
			cout<<"B."<<cauHoi[i].sai3<<endl;
			cout<<"C."<<cauHoi[i].dung<<endl;
			cout<<"D."<<cauHoi[i].sai2<<endl;
			dapAn='C';
	    }
	    if(kt[i]==14){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai2<<endl;
			cout<<"B."<<cauHoi[i].sai1<<endl;
			cout<<"C."<<cauHoi[i].dung<<endl;
			cout<<"D."<<cauHoi[i].sai3<<endl;
			dapAn='C';
	    }
	    if(kt[i]==15){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai2<<endl;
			cout<<"B."<<cauHoi[i].sai3<<endl;
			cout<<"C."<<cauHoi[i].dung<<endl;
			cout<<"D."<<cauHoi[i].sai1<<endl;
			dapAn='C';
	    }
	    if(kt[i]==16){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai3<<endl;
			cout<<"B."<<cauHoi[i].sai1<<endl;
			cout<<"C."<<cauHoi[i].dung<<endl;
			cout<<"D."<<cauHoi[i].sai2<<endl;
			dapAn='C';
	    }
	    if(kt[i]==17){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai3<<endl;
			cout<<"B."<<cauHoi[i].sai2<<endl;
			cout<<"C."<<cauHoi[i].dung<<endl;
			cout<<"D."<<cauHoi[i].sai1<<endl;
			dapAn='C';
	    }
	    if(kt[i]==18){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai1<<endl;
			cout<<"B."<<cauHoi[i].sai2<<endl;
			cout<<"C."<<cauHoi[i].sai3<<endl;
			cout<<"D."<<cauHoi[i].dung<<endl;
			dapAn='D';
	    }
	    if(kt[i]==19){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai1<<endl;
			cout<<"B."<<cauHoi[i].sai3<<endl;
			cout<<"C."<<cauHoi[i].sai2<<endl;
			cout<<"D."<<cauHoi[i].dung<<endl;
			dapAn='D';
	    }
	    if(kt[i]==20){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai2<<endl;
			cout<<"B."<<cauHoi[i].sai1<<endl;
			cout<<"C."<<cauHoi[i].sai3<<endl;
			cout<<"D."<<cauHoi[i].dung<<endl;
			dapAn='D';
	    }
	    if(kt[i]==21){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai2<<endl;
			cout<<"B."<<cauHoi[i].sai3<<endl;
			cout<<"C."<<cauHoi[i].sai1<<endl;
			cout<<"D."<<cauHoi[i].dung<<endl;
			dapAn='D';
	    }
	    if(kt[i]==22){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai3<<endl;
			cout<<"B."<<cauHoi[i].sai1<<endl;
			cout<<"C."<<cauHoi[i].sai2<<endl;
			cout<<"D."<<cauHoi[i].dung<<endl;
			dapAn='D';
	    }
	    if(kt[i]==23){
			cout << cauHoi[i].deBai<<endl;
			cout<<"A."<<cauHoi[i].sai3<<endl;
			cout<<"B."<<cauHoi[i].sai2<<endl;
			cout<<"C."<<cauHoi[i].sai1<<endl;
			cout<<"D."<<cauHoi[i].dung<<endl;
			dapAn='D';
	    }
}
}
void DETHI::kiemtra() {
	int diem=0;
	string cauTrl;
	cout << "\nNhap cau tra loi cua ban (A/B/C or D): \n";
	for(int i=0;i< cauHoi.size();i++) {
		cout<<"cau "<< i+1<<" : "; 
		cin>>cauTrl;
		if (dapAn == cauTrl) diem++;
	}
	cout << "\nDiem cua ban la : "<< diem<<"/"<<cauHoi.size();
}

int main() {
    DETHI deThi;
	ifstream readDeThi; 
	deThi.docFile(readDeThi , "dethi.txt");
	
	//deThi.inDeThi();
	//deThi.kiemtra();
	string k;
	do { 
	   cout <<"\nban co muon kiem tra (1/0) : ";
	   cin >>k;
	   	deThi.inDeThi();
	deThi.kiemtra();
	} while (k=="1");
	
	
	return 0;
}