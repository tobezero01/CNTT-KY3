#include<bits/stdc++.h>
using namespace std;

void hauto(string a)
{
	stack<char> c; //Chua cac toan tu
	string output = ""; //output la chuoi kq
	int n = a.size();
	
	for(int i=0; i<n; i++)
	{	 	
	  	if('0'<=a[i] && a[i]<='9') { //neu la toan hang cho vao output
	   		output += a[i];
		} else if(a[i]=='(') { //neu la '(' cho vao c
	   		c.push(a[i]);
	  	} else if(a[i]==')') {
	   		do {
	    		//neu la ')' thi lan luot cho nhung toan tu trong c vao output cho den khi gap '('
	    		output += c.top();
				c.pop();
	   		} while (c.top() != '('); 
	   		c.pop(); //bo dau '('
	  	} else if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/') { // Neu la toan tu
	  		char h = '!';
	  		if (!c.empty()) h = c.top();
	   		if(((a[i]=='+'||a[i]=='-')&&(h=='*'||h=='/'))||(a[i]=='*')&&(h=='/')||(a[i]=='/')&&(h=='*'))
	   		{//if (toan tu cuoi cung trong c co do uu tien lon hon hoac bang toan tu dang duyet
	    		output += c.top(); //thi cho toan tu do vao output-->kq
				c.pop();
	   		}
	   		c.push(a[i]); //cho toan tu dang duyet vao c
	  	}
	}

	while(!c.empty()) { //sau khi duyet het ma trong c van con phan tu thi lan luot cho vao output
		output += c.top();
		c.pop();
	}

 	for(int i=0; i<output.size(); i++) printf("%c",output[i]); //xuat kq
}

int main()
{
	string a = "(((2+3)*8+5)+3)*6";
	hauto(a);
	return 0;
}


