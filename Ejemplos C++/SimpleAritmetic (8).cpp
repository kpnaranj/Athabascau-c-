#include <iostream>
using namespace std;

void primeNumber(int xPrime){
	unsigned int countPrime=0;
	for (unsigned int i=1; i<xPrime+1; i++){
		for(unsigned int j=1; j<i+1; j++){
			if(i%j==0){
				countPrime++;
			}
		}
		if(countPrime==2){
		cout<<"The number "<<xPrime<<" is prime ";
		}	
		else{
		cout<<"The number "<<xPrime<<" is not prime ";
		}		
	}
	
}

int main(){
	unsigned int number=0;
	cout<<"Please type a number to verify prime"<<endl;
	cin>>number;
	primeNumber(number);
	
}