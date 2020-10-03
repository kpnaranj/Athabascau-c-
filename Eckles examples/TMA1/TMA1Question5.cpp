//: TMA1Question5.cpp

/* 
   Title: TMA1Question5.cpp
   Description: 
   
   Create a makefile for one of the exercises in this assignment (your choice) that 
   allows the user to type make for a production build of the program and make debug 
   for a build of the program that includes debugging information.

   Date: February 22, 2019
   Author: Kevin P. Naranjo Paredes
   Copyright: 2019 Kevin P. Naranjo Paredes
 */
 
 /*
   DOCUMENTATION
   
   Program Purpose: 
   
 		Apply last concepts given in Unit 3 to have a faster and effective way to compile and 
 		execute cpp files in the terminal 
 		
 
 	Compile: make 
 				g++ TMA1Question5.cpp -o TMA1Question5.exe
 			 make debug
 			 	g++ TMA1Question5.cpp -DDEBUG_TEST -o TMA1Question5.exe
 	
 	Classes: none
 	Variables: none
	 		
	 	Notes: The use of the make file is to give a faster compilation and execution of programs, so 
	 	it does not need any additional variables 
	 	
	 CPP - Macros to invoke c++ compiler 
	  
 */
 
 /*
   TEST PLAN
  
    Normal case: 
   >(user is in terminal)
   >make
   >g++ TMA1Question5.cpp -o TMA1Question5.exe
   >document has been updated and the execution file has been created 
   
   	Normal case(debug ):
   	>(user is in terminal)
   	>make debug 
   	>g++ TMA1Question5.cpp -DDEBUG_TEST -o TMA1Question5.exe
   
    Discussion: 
    
   The makefile creates the executable and the implementation of the cpp for compilation 
  
 */
 
#include <iostream>
#include "Question3.h"
using namespace std;

int main(){
	//Debug file 
	
	// Based on program Thinking in C++ solution 35 by Bruce Eckel, Chapter 03.
	
	#ifdef DEBUG_TEST
	
	for (int i=0; i<10; i++){
		cout<<"Debug testing #"<<i+1<<endl;	
	}
	
	#endif
	
	// Print function to display all numbers
	printPrime();

	return 0;
}///:~