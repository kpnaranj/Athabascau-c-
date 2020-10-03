//: TMA2Question2.cpp

/* 
   Title: TMA2Question2.cpp
   Description: 
   
   Write a program in which you create a Hen class. Inside this class, nest a Nest class.
   Inside Nest, place an Egg class. Each class should have a display() member function. 
   For each class, create a constructor and a destructor that prints an appropriate message
   when it is called. In main(), create an instance of each class using new and call the 
   display() function for each one. After calling display(), free the storage using delete.
   
   Date: March 28, 2019
   Author: Kevin P. Naranjo Paredes
   Copyright: 2019 Kevin P. Naranjo Paredes
 */
 
 /*
   DOCUMENTATION
   
   Program Purpose: 
 		Measure level of understanding of nested classes and proper call and initialization of
 		variables in main, using the content learning from Unit 5 
 		Also, create a practical example to effectively understand the use of classes,
 		pointers and constructors initialization in a program
 
 	Compile: g++ Question2.cpp TMA2Question2.cpp -o TMA2Question2.exe
 	Execution: ./TMA2Question2.exe
 	
 	Classes: Hen, Nest, Egg
 	Variables: 
 	In Question2.h:
 		Hen:
 		public:
 		Hen() - constructor - Used to intialize Hen 
 		~Hen() - destructor - Used to dinamically feeing memory after program finishes 
 		display() - void - member function used to display instance of Hen 
 		Nest - class - child class of Hen 
 		
 		Nest:
 		public:
 		Nest() - constructor - Used to intialize Nest
 		~Nest() - destructor - Used to dinamically freeing memory after program finishes 
 		display() - void - member function used to display instance of Nest
 		Egg - class - child class of Nest, second chld class of Hen
 		
 		Egg:
 		public:
 		Nest() - constructor - Used to intialize the instance of Nest
 		~Nest() - destructor - Used to dinamically freeing memory after program finishes 
 		display() - void - member function used to display instance of Egg
 	
 		
 	In Question2.cpp:
 		instances - text comment in constructors and display - Text message in void display 
 		arguments to indicate a constructor has been called	
 		
 	in TMA2Question3.cpp:
 		chicken - Hen* - pointer of Hen using new to dinamically allocate memory for class Hen 
 		nests - Hen::Nest* - pointer of Nest using new to dinammically allocate memory for class Nest 
 		chick - Hen::Nest::Egg - pointer of Egg using new to dinammically allocate memory for class Egg
 */
 
 /*
   TEST PLAN
   	
   Normal case (option txt):
   >Class variable pointer 'chicken' is created as a new class Hen 
   >Constructor 'Hen' is called
   >Message displayed "Constructor Hen called"
   >Class variable pointer 'nests' is created as a new class Nest
   >Constructor 'Nest' is called 
   >Message displayed "Constructor Nest called"
   >Class variable pointer 'chick' is created as a new class Egg
   >Constructor 'Egg' is called 
   >Message displayed "Constructor Egg called"
   >chicken pointing to member function display to read message 
   >Instance displayed "Instance of Hen, chicken is in the parent class"
   >nests pointing to meber function display to read message
   >Instance displayed "Instance of Nest, nests in first child class"
   >chick pointing to member function display to read message 
   >Instance displayed "Instance of Egg, chick is in the second child class"
   >freeing memory of chicken 
   >freeing memory of nests 
   >freeing memory of chick
   >Message of destructor Hen displayed "Destructor Hen called, bye chicken"
   >Message of destructor Nest displayed "Destructor Nest called, bye nest"
   >Message of destructor Nest displayed "Destructor Egg called, poor chick"
   >Program terminated "return 0"
  
   Notes: Example without will not have bad cases being that the classes, isntances and text
   are given and user interactions are not required for this exercise 
   
    Discussion: 
    The following is a simple program able to dinamycally allocate memory of nested classes and display 
    their instances using reference of pointers learned in Unit 5.
    
    The program could be more complex by using private members and void functions to store values in constructors
    similar to exercise 1, or adding a class with parameters similar to exercise 2 
 */
#include "Question2.h"
#include <iostream>

int main(){
	//parameters dinamically allocated
	Hen *chicken = new Hen(); 
	Hen::Nest *nests = new Hen::Nest();
	Hen::Nest::Egg *chick = new Hen::Nest::Egg();
	//Instances displayed
	chicken -> display();
	nests -> display();
	chick -> display();
	//Deallocate memory
	delete chicken;
	delete nests;
	delete chick;
	
	return 0;	
} ///:~