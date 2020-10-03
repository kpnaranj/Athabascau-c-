//: TMA1Question2.cpp

/* 
   Title: TMA1Question2.cpp
   Description: 
   
    Write a program that opens a (text) file, and displays the contents of that 
    file one line at a time. After a line has been displayed, the program should
    wait for the user to press the key before displaying the next line in the file.

   Date: February 22, 2019
   Author: Kevin P. Naranjo Paredes
   Copyright: 2019 Kevin P. Naranjo Paredes
 */
 
 /*
   DOCUMENTATION
   
   Program Purpose: 
 		Measure understanding of commands getline() and cin.get() in c++ language learned
 		in Unit 2 of the course
 		Understand basic applications of iostream when reading a text document and applied 
 		learned concepts 
 		
 	Compile: g++ TMA1Question2.cpp -o TMA1Question2.exe
 	Execution: ./TMA1Question2.exe
 	
 	Notes: This exercise was useful to have a better undestanding of getline and the use of 
 	while loop when reading a document 
 	
 	I also created an alternative option (in comments) that could work in this questionm, however; I decided to add
 	it as a second example in order to practice the library vectors material and the use of arrays
 	
 	Classes: none
 	
 	Variables: 
 		inputFile - fstream - Used to store and open a text example to track a line in a text document 
 		nLine - string - Used to go through the document line by line after getline is executed (next line)
 		
 		
 	External files:
 		Text1 - txt - Text file that contains Lorem Ipsum text to test the program is running 
 		properly for .txt documents 
 */
 
 /*
   TEST PLAN
    Notes: Text in the document is described as 'line # displayed' for explanatory purposes 
   		   Text between parentesis is used to explain the condition of the compiler 
    Normal case: 
   	>'line 1 displayed'
   	>(compiler waiting for user to type the key)
   	>User type enter key 
   	>'line 2 displayed '
   	>(repeat process until document ends, 35 times for txt example)
   	>End of document 
   	
   	Bad case (nonsense or any number):
   	>'line 1 displayed'
   	>(compiler waiting for user to type the key)
   	>User type dcsaerd + enter key 
   	>'line 2,3,4,5,6,7 displayed'
   	>(repeat process until document ends)
   	>End of document 
   	
   
    Discussion: 
    
   The program executes one line at a time if the user press enter to continue, it gives additional
   lines as the content inside is bigger
   
   Notes: This issue could be solved using the function cin.ignore(); however, it has not been discussed
   in the content of Unit 2
   
   All inputs are permitted to execute the function, but is recommended to use only the key buttom for 
   a concise output 
   
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
	//Based on program Intvector.cpp by Bruce Eckel, Chapter 02 and adapted to string
	//Option 1
	ifstream inputFile("Test.txt");
	string nLine;
	vector <string> printing;
	
	// To store data into a vector array 
	while (getline(inputFile, nLine)){
		printing.push_back(nLine);	
	}
	// To display strings after being saved, one line at a time 
	for (unsigned int i=0; i<printing.size(); i++){
		cout<<printing[i]<<"\t"<<endl;
		cin.get();
	}	
	
	cout<<"End of document"<<endl;
	
	
	//Option 2 
	
	
	/*ifstream inputFile("Test.txt");
	string nLine;
	
	while (getline(inputFile,nLine)){
		cout<<nLine+"\n";
		cin.get();	
	}
	cout<<"End of document"<<endl;
	
	*/
	
	return 0;
} ///:~