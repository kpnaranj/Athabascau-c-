/*Create a character array literal with a pointer that points 
to the beginning of the array. Now use the pointer to modify 
elements in the array. Does your compiler report this as an error? 
Should it? If it doesn’t, why do you think that is?*/

#include <iostream>
using namespace std;

int main() {
	
	char array[5]{'C','D','E','F','G'};
	char* newArray = array[0]; /*invalid conversion from ‘char’ to ‘char*’ [-fpermissive]
  char* newArray = array[0];
	for(int i = 0; i < 5; i++){
		cout<<array[i]<<" ";	
	}	
	
	for(int i = 0; i < 5; i++){
		
		*(newArray + i) = 'A';	
	}
}

/*error: cannot convert ‘char (*)[5]’ to ‘char*’ in initialization
  char* newArray = &array;
*/