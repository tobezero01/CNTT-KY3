#include<bits/stdc++.h>
#include <conio.h>
using namespace std;

class CMatrix{
	private:
		int rows, cols;
		float *element;
	public:
		CMatrix();
		CMatrix(int, int);
		~CMatrix();
		void setColRow(int,int);
		void printMatrix();
		void inputMatrix();
};

CMatrix::CMatrix()
{
    rows = 0;   
	cols = 0;
    element = NULL;
}

CMatrix::CMatrix(int row, int col)
{
	rows = row;   
	cols = col;
	element = new float [rows*cols];
}

CMatrix::~CMatrix(){
	delete  [ ] element;
}

void CMatrix:: inputMatrix(){
	int i,j;
	if(element != NULL) delete element;
	element = new float[rows*cols];
	for(i=0; i<rows; i++) {
	    for(j=0; j<cols; j++){
	        cout<<"element["<<i<<"]["<<j<<"]=";
	        cin>>element[i*cols+j];
	    }
	}
}

void CMatrix:: printMatrix() {
	int i, j;
	for(i=0; i<rows; i++)
	{
		cout<<"\n";
	    for(j=0; j<cols; j++){
	        cout<<element[i*cols+j]<<" ";
		}
	}
}

void CMatrix:: setColRow(int r,int c)
{
	rows = r;
	cols  = c;
}

int main(){
	CMatrix  m(3, 3);
	m.inputMatrix();
	m.printMatrix();
	getch();
}

