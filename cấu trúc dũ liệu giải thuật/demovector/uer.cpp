#include<iostream>
#include <ctime>

int main (){
	int kt[100];
	srand(int( time(NULL)));
	for (int i=0;i<10;i++){
		kt[i] =rand()%24;
		//std::cout<<" "<<kt;
	}
	for (int i=0;i<10;i++){
		std::cout<<" "<<kt[i];
	}
}