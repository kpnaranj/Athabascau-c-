#include <iostream>
using namespace std;

int main(){
	int number[10];
		
	for (int i=0; i<10; i++){
		number[i]=i+1;
	}
	for (int i=0; i<10; i++){
		cout<<"This is number :"<<number[i]<<" "<<endl;
	}
	
	return 0;
}