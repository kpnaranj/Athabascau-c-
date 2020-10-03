//: TMA1Question1.cpp

/* 
   Title: TMA1Question1.cpp
   Description: 
   
    Write a program that opens a file and counts the whitespace-separated words
    in that file.

   Date: February 22, 2019
   Author: Kevin P. Naranjo Paredes
   Copyright: 2019 Kevin P. Naranjo Paredes
 */
 
 /*
   DOCUMENTATION
   
   Program Purpose: 
 		Measure proper level of understanding of Unit 2 material related to introduction
 		of compilation process, libraries, data types and proper use of strings and iostream
 		in txt and cpp
 		Also, create our first program to apply concepts and reforce learning material 
 
 	Compile: g++ TMA1Question1.cpp -o TMA1Question1.exe
 	Execution: ./TMA1Question1.exe
 	
 	Notes: In this code I add an additional feature that can choose between two examples of 
 	types .txt or .cpp, since in the description it does not specify any type requirement and the 
 	question could have additional tasks to do. This implementation is a good additional practice 
 	for other questions in the assignment 
 	
 	Classes: none
 	
 	Variables: 
 		inputFile1 - ifstream - used to store and open first text example to count file in .txt format 
 		inputFile2 - ifstream - used to store and open second text example to count file in .cpp format 
 		cWords - unsigned int - used to store the number of white-spaced words after opening
 		the document (counter of words)
 		options - char - used to store user inputs to choose between two file for testing program (given 
 		in two numbers only)
 		nLine - string - used to go word by word in the document and allow cWords to increment until the 
 		last line (next line)
 		
 	External files:
 		Text1 - txt - Text file that contains Lorem Ipsum text to test the program is running 
 		properly for .txt documents 
 		TestQ1 - cpp - cpp file that contains a simple c++ program example to test the program is running 
 		properly for .cpp documents
 */
 
 /*
   TEST PLAN
   	Notes: 	Test plan based on options condition and without options condition 
   			Text in first part reduced to 'Choose an option' for explanatory purposes 
   Normal case (option txt):
   	>Choose an option: 1
   	>The following file has 291 white-space separated words
   	
   Normal case (option cpp):
   	>Choose an option: 2
   	>The following file has 25 white-space separated words 
   
   Bad case (nonsense):
   	>Choose an option: sdeasdc
   	>The given option is not correct, program finished...
   
   Bad case (negative number):
   	>Choose an option: -2
   	>The given option is not correct, program finished...
   
   Bad case (floating point options):
   >Choose an option: 1.4 (from 1.0 to 1.4)
   >The following file has 291 white-space separated words 
   
   (Assume the program finishes and its executed again)
   
   >Choose an option: 1.5 (from 1.5 to 2.0)
   >The following file has 25 white-space separated words 
   
   Notes: Example without additional implementation will not have bad cases
   being that the text is given and will only show the whitespaces of example
   
   Normal case (using only cpp without options) 
    >The following file has 25 white-space separated words 
   
    Discussion: 
    
   The program is a basic counter of words and will finish after it prints out the 
   text in Normal case examples
   
   Negative numbers are not permitted and floating points are permitted for char convenience
    
   Test plan is based on both additional options condition and without options condition
    
   Text in first part is reduced to 'Choose an option' for explanatory purposes
    
   Example without additional implementation will not have bad cases being that 
   the text is given and will only show the number of whitespaces as example
 */
 
#include <iostream> // Stream declaration 
#include <fstream> //file stream declaration
#include <string> // String declaration
using namespace std;

int main() {
  ifstream inputFile1("Test.txt"); 
  ifstream inputFile2 ("TestQ1.cpp");
  unsigned int cWords=0;
  char options;
  string nLine;
  
  // Additional feature
  cout<<"choose a file exercise to counts the whitespace-separated "
 	 <<"words in that file, 1 for txt or 2 for cpp" <<endl; 
  cin.get(options); // Request and obtain option 
  
  //Find number of white-space separated words and display output
  if(options=='1'){
		while (inputFile1>> nLine){ 
	   		++cWords;
		}
	 cout << "The following file has " << cWords
		<<" white-space separated words" << endl;
	}
	
	//Based on program GetWords.cpp Unit 2 and adapted for int measures
  else if(options=='2'){
	   while (inputFile2>> nLine){ 
   		 ++cWords; 
		}
	 cout << "The following file has " << cWords
		<<" white-space separated words" << endl;
		}
  //Display in case of other inputs 
 else {
	 cout<<"The given option is not correct, program finished..."<<endl;
 	} 
	
  return 0;
} ///:~