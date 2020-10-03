#include <iostream>
using namespace std;
int main(){
	
	#ifdef DEBUG
		cout<<"Compile for debug. "<<endl;
		
	#endif 
	
	cout<<"Hola";
	
	unsigned int p_number=0; // since we only use positive prime numbers  
	unsigned int p_counter=0; //  positive prime counter 
	unsigned int p_line=0;// to give order to each number in lines of 10
	
	for(unsigned int i=1; i<10000; i++){ 
		for(unsigned int j=1; j<i+1; j++){ 
			if(i%j==0){// if the remainder is 0 then is a multiple of p_number
				p_counter++;
			}		
		}// Second loop
		
		if(p_counter==2){ // A prime number only has two divisible numbers
			cout<<i<<" ";
			p_line++;
			p_number++;
			p_counter=0;// to reset counter after prime number is found
		}
		else{
			p_counter=0; // to reset counter for other numbers
		}
		
		if(p_line==10){ //if p_line is 10, then it has ten numbers in each line 
			cout<<endl;
			p_line=0;// to reset p_line
		}
	}// First for loop
	cout<<endl;
	cout<<"There are "<<p_number<<" prime numbers between 1 and 10,000"<<endl;
	return 0;
}