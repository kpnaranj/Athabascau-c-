/*Write a program that uses assert( ) with an argument that is always false (zero) 
to see what happens when you run it. Now compile it with # define NDEBUG and run it 
again to see the difference.
*/

#include <iostream>
#include <cassert>

using namespace std;

int main(){
	const int false_value=1;
	
	if(false_value==1){
		
		assert(false_value==0);
		cout<<"Hello everyone";
	}
	return 0;	
}

 

/*assertion "false_value==0" failed: file "Ex12.cpp", line 15, function: int main()
Aborted (core dumped)*/


