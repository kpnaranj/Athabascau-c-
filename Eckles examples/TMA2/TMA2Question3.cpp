//: TMA2Question3.cpp

/* 
   Title: TMA2Question3.cpp
   Description: 
   
   Write a program in which you create a Text class that contains a string object to
   hold the text of a file. Give it two constructors: a default constructor and a 
   constructor that takes a string argument that is the name of the file to open. 
   When the second constructor is used, open the file and read the contents of the 
   file into the string member object. Add a member function contents() to return 
   the string so that you can display it. In main(), open a file using Text and display 
   the contents.

   Date: March 28, 2019
   Author: Kevin P. Naranjo Paredes
   Copyright: 2019 Kevin P. Naranjo Paredes
 */
 
 /*
   DOCUMENTATION
   
   Program Purpose: 
 		Measure level of understanding of classes constructors and their behavior to properly 
 		allocate memory and read document text 
 		Also, create a program with member functions and private parameters to 
 		properly use them to store and free memory
 
 	Compile: g++ Question3.cpp TMA2Question3.cpp -o TMA2Question3.exe
 	Execution: ./TMA2Question3.exe
 	
 	Notes: In the following code I also added a pointer text data to reference memory 
 	from a class with parameters for learning purposes and use of first constructor in 
 	the exercise, there is also comment text for debugging purposes
 	
 	Classes: Text
 	
 	Variables: 
 	In Question3.h:
 	private:
 		addText - string - used to hold the text of a given file and display content with a member function 
 	public:
	 	Text() - default constructor - used to initialize values without arguments in main 
	 	Text(string ...) - constructor - used to store text of private member to addText
	 	text - string - parameter of member function Text(string ...) passed by value from main with text content
	 	to store
	 	~Text() - default constructor - used to automatically free memory after end of the program
	 	contents() - string - member function from Text to return the value of the private argument addText after 
	 	being store in memory
	 	
 	In Question3.cpp:
 		input - ifstream - local variable used to read content from parameter 'text' and allocate memory to a 
 		string in a loop
 		nLine - string - local variable used to read through the text and temporally store parts of text to pass
 		values to private member 'addText';
 		
 	In TMA2Question3.cpp:
 		data - Text - class variable with parameter to store memory and print content in main
 		**(Alternatebly) - used for learning purposes and application of default construtor
 		**data1 - Text* - class variable used dinamically allocate address of 'data' after contents() displays content 
 	
 	External files:
 		Question3 - txt - Text file that contains ramdom text to test the program is running 
 		properly for .txt documents 
 */
 
 /*
   TEST PLAN
   	
   Normal case (option txt):
   	>A class variable 'data' with an argument is created 
   	>Constructor with a parameter is called and 'Question3.txt' is passed by value
   	>Text go to if statement to determine if it is open 
   	>Text confirmed in if statement with sentence "Loading ..."
   	>Text go to while loop 
   	>nLine stores temporally the message and each line is stored in 'addText'
   	>While loop ends and constructor is finished 
   	>Contents() member function is called
   	>Message is displayed->"Ignorant saw her her drawings marriage laughter. ..."
   	>Contents() finishes return string 
   	>Destructor is called
   	>Program finishes 'return 0'
   	
   	Normal case (option data1):
   	>A class variable 'data' with an argument is created 	
   	>A class variable 'data1' without arguments is created 	
   	>Constructor is called 
   	>Constructor with a parameter is called and 'Question3.txt' is passed by value
   	>'text' parameter go to if statement to determine if it is open 
   	>'text' parameter confirmed in if statement with sentence "Loading ..."
   	>'text' parameter go to while loop 
   	>nLine stores temporally the message and each line is stored in 'addText'
   	>While loop ends and constructor is finished 
   	>Contents() member function from data is called
   	>Message is displayed->"Ignorant saw her her drawings marriage laughter. ..."
   	>Contents() finishes return string 
   	>'data1' takes the address of 'data'
   	>Message is displayed "Now data 1"
   	>'data1' reference memory of data and shows contents()
   	>Message is displayed->"Ignorant saw her her drawings marriage laughter. ..."
   	>Default Destructor called
   	>Destructor with parameter is called 
   	>Program finishes 'return 0'
   	
   Bad case (Question3.txt missing):
   	>A class variable 'data' with an argument is created 	
   	>A class variable 'data1' without arguments is created 	
   	>Constructor is called 
   	>Constructor with a parameter is called and 'Question3.txt' is passed by value
   	>'text' parameter go to if statement to determine if it is open 
   	>if statement goes to else for missing files or if it is not open
   	>else prints "File missing, terminating program"
   	>return 0;
   
   
   Notes: Example without additional implementation will not have bad cases
   being that the text is given and user interactions are not required for
   this exercise 
   
    Discussion: 
    
   The program is able to store a tet file in a private member using the technics learned in 
   Unit 5,6&7. The program stores a txt. file and then prints the information after being displayed 
   
   The program could be more complex as we can dinamically allocate memory using another variable or even
   ask the user to use different text files and storage each text as the user convenience 
 */

#include "Question3.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
	/*Text* data1;*/
	Text data("Question3.txt");
	cout<<data.contents();
	
	/*Optional (To see if the data is storage in 'data' as well)
	cout<<"Now data 1 "<<endl;
	data1 = &data2;
	cout<<data1->contents();
	*/
	return 0;
}///:~