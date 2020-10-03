
#include <iostream>
using namespace std;

// Function that prints out all prime numbers 
void printPrime(){
	
	unsigned int pNumber=0; 
	unsigned int pCounter=0;
	unsigned int pLine=0;
	
	// For loops to verify and print the number of prime numbers 
	for(unsigned int i=1; i<10000; i++){ 
		for(unsigned int j=1; j<i+1; j++){ 
			if(i%j==0){
				pCounter++;
			}		
		}
		
	// if statement to verify a number is prime or not after second loop 
		if(pCounter==2){ 
			cout<<i<<" ";
			pLine++;
			pNumber++;
			pCounter=0;
		}
		else{
			pCounter=0; // to reset counter for other numbers
		}
	// if statement to verify the maximum number of prime numbers in each line 
		if(pLine==10){ 
			cout<<endl;
			pLine=0;
		}
	}
	
	// To verify all prime numbers have been found in the given range
	cout<<endl;
	cout<<"There are "<<pNumber<<" prime numbers between 1 and 10,000"<<endl;	
}