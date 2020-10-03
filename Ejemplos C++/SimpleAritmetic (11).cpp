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