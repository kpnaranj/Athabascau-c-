#include <iostream>

using namespace std;

void printArray(const char *arrayPtr);
char* createCharArray(char*arrayPtr);


void printArray(const char* arrayPtr){
	
	int size = 0;
	while( *(arrayPtr + size++) != '\0');
	
	for (int i=0; i<size; i++)
		cout<<*(arrayPtr + i);
	
	cout<<endl;

}

char* createCharArray(char *arrayPtr){
	int size = 0;
	while(*(arrayPtr + size++)!= '\0')	
	
	char*result = new char[size];
	
	for (int i = 0; i<size; i++)
		*(result + i) = *(arrayPtr + i);
	
	return result; // Always return the address of the array
}

int main(){
	char* str1 = "This is an example array.";
	char* str2 = createCharArray(str1);
	char* str3 = createCharArray(str2);
	
	cout<<"Array 1: "<<(void*)str2<<endl;
	printArray(str1); // this is the same as giving the pointer address 
	
	cout<<"Array 2: "<<(void*)str3<<endl;
	printArray(str2);
	
	delete str2;
	delete str3;
	
	return 0;
}