/*Write a program that opens a (text) file, and displays the contents of that file
 one line at a time. After a line has been displayed, the program should wait for
  the user to press the key before displaying the next line in the file.*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream inputFile("Text1.txt"); // Open the file.
	string nLine; // To go to next line .
	
	while (getline(inputFile,nLine)){ //To get all the lines of the file.
		
		cout<<nLine+"\n"; // Prints out the lines.
		cin.get(); //It stops when the line finishes.
	}
	
	cout<<"End of document"<<endl;
	
	return 0;
	
} ///:~