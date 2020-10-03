/*Create a const array of char, then try to change one of the chars.*/

#include <iostream>
using namespace std;

const int i = 6;
int main() {
	const char array[i]{'D','E','S','O','L','E'};	
	
	for(int j= 0; j < i; j++){
		cout<<"IT WORKS";
		cout<<" "<<array[j]<<endl;	
		/*array[j] ='s';*/ //read-only
	}
	/*array[1] = 'J'; */ //error: assignment of read-only location ‘array[1]’
}


