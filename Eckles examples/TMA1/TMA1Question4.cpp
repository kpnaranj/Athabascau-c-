//: TMA1Question4.cpp

/* 
   Title: TMA1Question4.cpp
   Description: 
   
  Write a program that creates an array of 100 string objects. Fill the array by 
  having your program open a (text) file and read one line of the file into each 
  string until you have filled the array. Display the array using the format 
  “line #: <string>,” where # is the actual line number (you can use the array 
  counter for this value) and <string> is the stored string.

   Date: February 22, 2019
   Author: Kevin P. Naranjo Paredes
   Copyright: 2019 Kevin P. Naranjo Paredes
 */
 
 /*
   DOCUMENTATION
   
   Program Purpose: 
   
 		Measure understanding and proper use of arrays and for loops in external 
 		documents
 		Also, determine the limits of arrays and store arrays in variables 
 		
 	Compile: g++ TMA1Question4.cpp -o TMA1Question4.exe
 	Execution: ./TMA1Question4.exe
 	
 	Classes: none
 	
 	functions:
 	
 		printLine - void - function that prints out an array of 100 strings after being stored in 
 		the variable
 		
 	Variables: 
 		printLine() Local variables - void  parameters: string arrayLine [100]
 			
 			arrayLine[100] - string - used to print out the information provided in the main() after
 			collecting information of text 
 			
 			i - unsigned int - used to run a for loop that will print out the number and the line of the 
 			document 
 			
 		int main()	
 		
 			inputFile - iftream - used to store and open text file to text program
 			nLine - string - used to go throught the end of the document and count
 			the number of lines in the text file (next line)
 			arrayLine[100] - string - array used to store each line of the text 
 			
 	External files: 
 	
 		Text1 - txt - Text example used to test and compile program 
 		 
	 		
	 	Notes: We could add a header file, however; since the code is short, it was decided to maintain normal 
	 	convention 
	 			 
 */
 
 /*
   TEST PLAN
  
    Normal case: 
    
   	>(program is executed)
   	>"Line #1  Lorem Ipsum text"
   	>"Line #2 (Blank)"
   	>"Line #3 3 Lorem ipsum dolor sit amet, consectetur adipiscing elit."
   	>(after line finishes)
   	>"line #35 Duis sollicitudin gravida nisl, at condimentum risus malesuada cursus"
	>"line #36 In mollis nec nisi sit amet interdum."
	>"line #37 In mollis nec nisi sit amet interdum."
	>(Fill out the array until you complete 100 strings)
	>"line #100 In mollis nec nisi sit amet interdum. "
	>"The array has been filled"
	>"End of compilation"
   
   	Notes: There is not bad case since there is not input for the user to store negative values or random text 
   	
   
    Discussion: 
   	
    The program can compile and fill out 100 strings using a for loop to print out stored values of the document
    The program could have had an additional option to stop once the program has reached the last line of the
    document using a break statement, however; it might not complete the task of fill out the array as requested 
    in the exercise
    
    The program can also work with .cpp documents
   
 */


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Declaration

void printValue (string arrayLine[100]);

//Definition
// Function that displays a number after lines are stored in the document 
void printLine(string arrayLine[100]){
	for(unsigned int i=0; i<100; i++){
		cout<<"line #"<<i+1<<" "<<arrayLine[i]<<endl;
	}
}


int main(){
	ifstream inputFile("Test.txt");
	string nLine;
	
// Based on program Arrays.cpp by Bruce Eckel, Chapter 03 and adapted to string inputs.
	string arrayLine[100];
// For loop that stores a line at a time and fills the array
	for(unsigned int i=0; i<100; i++){
		getline(inputFile,nLine);
		arrayLine[i]=nLine;
	}
	
	printLine (arrayLine);
	
	cout<<"The array has been filled"<<endl;
	cout<<"End of compilation"<<endl;
	
	return 0;
}///:~