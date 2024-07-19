#include<bits/stdc++.h>
using namespace std;

//Ham ve mot vach tren thuoc
void drawonetick(int ticklength, int ticklabel=-1){
	cout<<"    ";  
	for(int i=0;i<ticklength; i++)
		cout<<"-";
	if(ticklabel>=0) 
		  cout<<" "<<ticklabel;
	cout<<"\n";
}

//Ham ve mot don vi cua thuoc
void drawticks(int ticklength){
	if(ticklength>0){
		drawticks(ticklength-1);
		drawonetick(ticklength);
		drawticks(ticklength-1);
	}
}
//Ham ve ca thuoc
void drawruler(int ninches, int majorlength){
	drawonetick(majorlength,0);
	for(int i=1; i<= ninches; i++){
		drawticks(majorlength-1);
	    drawonetick(majorlength,i);
	}
}

int main(){
     drawruler(6,3);
     
     return 0;
}


