/*Use aggregate initialization to create an array of string objects. Create a Stack 
to hold these strings and step through your array, pushing each string on your Stack.
 Finally, pop the strings off your Stack and print each one.*/
 
//Taken and adapted from Eckel's book Volume 1 Unit 6 Stack3Test.cpp

#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;
 
 
int main(){
	string lines[]={"test ","a ","is ","This "}; //Slack shows last element first 
	int size = sizeof(lines)/sizeof(*lines); //The way to know the size of my string
	
	Stack linespace;
	
	for(int i = 0; i<size; i++)
		linespace.push(new string(lines[i]));

	string* s;
	
	while ((s = (string*)linespace.pop()) !=0) {
		cout<<*s<<endl;
		delete s;	
	}
}///:~
 