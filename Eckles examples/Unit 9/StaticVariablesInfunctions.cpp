// : C09: StaticVAriablesInfunctions.cpp
#include <iostream>
using namespace std;

char oneChar(const char* charArray = 0) {
	static const char* s;
	if (charArray) {
		s = charArray;
		return *s;	
	}	
	else {
		cout<<"Un-initialized";
		return 0;
	}
	
	if(*s == '\0')
		return 0;
	return *s++;
}

/*char* a = "abcdefghijklmnopqrstuvwxyz";*/
char* a = "s";

int main() {
	// oneChar(); // require() fails
	oneChar(a); //initilaizes s to a
	char c;
	while ((c = oneChar()) !=0)
		cout<<c<<endl;
} ///:~