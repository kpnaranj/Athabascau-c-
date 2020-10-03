//: TMA3Question1.cpp
/* 
   Title: TMA3Question1.cpp
   Description: 
   
   Write a program in which you create a const whose value is determined at runtime by reading 
   the time when the program starts (hint: use the <ctime> standard header). 
   
   In a separate function, have the program create two arrays of 10,000 doubles. 
   
   Initialize the first array with sequential integral values starting with 100, and initialize 
   the second array with the same numbers, but in reverse order (i.e., the first array would 
   contain 100, 101, 102… while the second array contains 10,099, 10,098, 10,097…). 
   
   Loop through both arrays using a single loop, and multiply the corresponding array elements 
   from each array together and display the result. Read the time when the program completes the 
   multiplication, and compute and display the elapsed time. Do not use inline functions in this
   program.

   Date: Abril 12, 2019
   Author: Kevin P. Naranjo Paredes
   Copyright: 2019 Kevin P. Naranjo Paredes
 */
 
 /*
   DOCUMENTATION
   
   Program Purpose: 
 		Measure proper use of const variables and functions in running time to store local variables
 		and display values
 		Measure proper understanding of directive <ctime> in a function
 		Enforce concept learned in previous units with element operations and concepts from 
 		Unit 8,9,10,11 and 12
  
 
 	Compile: g++ TMA3Question1.cpp -o TMA3Question1.exe
 	Execution: ./TMA3Question1.exe
 		
 	Classes: 
 		TimeMachine1 - class - used to facilitate call of multiple functions and variables of the 
 		assignment in main
 		
 		Notes: TimeMachine1 is the version without inline, TimeMachine2 is a version with inline function
 	
 	Variables: 
 	uint - unsigned int - typedef assignment given to functions to use only positive values
 		
 		In class TimeMachine1:
 		private:
	 		test1 - double - variable to store lowest value '100' that will be multiplied to a const local variable
			test2 - double - variable to store highest value '10,099' that will be multiplied to a const local variable
		public:
			TimeMachine1() - constructor - to store private variables:
			~TimeMachine1() - destructor - to delete private variables after finishing program
			application() - void - Separate function that creates two arrays of 10,000
			getTest1() - double const - member function that returns a constant variable from Test1 private member
			getTest2() - double const - member function that returns a constant variable from Test2 private member
			setTest1() - void - member function that increases the value of test1 as it is looped in application function
			setTest2() - void - member function that decreases the valiue of test2 as it is looped in application function 
		
		In application():
			array1[] - double - array function that stores double values starting from 100 to 10,099
			array2[] - double -  array function that stores double values starting from 10,099 to 100
			multiply - double const - const value for multiplication whose value is determined at running time 
		
		In main():
			execution - TimeMachine1- object class that will run the program and loop statements to measure time 
			start - clock_t - timer that contains the time the function application() is executed in the program
			end - clock_t - timer that contains the time the function application() finishes to evaluate time of execution
			fTime - double - final time measured in the execution of the program to be displayed
 */
 
 /*
   TEST PLAN

   Normal case ():
   	>Program is executed 
   	>Program shows values to be multiply and answer in scientiic expression 
   	>"100 * 10099 = 1.0099e+06"
	>"101 * 10098 = 1.0199e+06"
	>"102 * 10097 = 1.02989e+06"
	>"........"
	>Program finishes execution
	>"10097 * 102 = 1.02989e+06"
	>"10098 * 101 = 1.0199e+06"
	>"10099 * 100 = 1.0099e+06"
	>Program shows compilation time
	>"Compilation time: 0.389"
	>Program finishes "return 0"

   	
   Normal case (multiple answers):
   	>Program is executed 
   	>Program shows values to be multiply and answer in scientiic expression 
   	>"100 * 10099 = 1.0099e+06"
	>"101 * 10098 = 1.0199e+06"
	>"102 * 10097 = 1.02989e+06"
	>"........"
	>Program finishes execution
	>"10097 * 102 = 1.02989e+06"
	>"10098 * 101 = 1.0199e+06"
	>"10099 * 100 = 1.0099e+06"
	>Program shows compilation time (compilation retrieved multiple times)
	>"Compilation time: "0.421, 0.406, 0.39"
	>Program finishes "return 0"
   
	Notes:
	1 .In compilation time, the range of time varies depending on the performance of the computer
	the range of average uncertanty can be determine to identify testing time 1 for evaluation of 
	second example.
	
	Range times:
		 #1: 0.421
		 #2: 0.39
		 #3: 0.391
		 #4: 0.421
		 #5: 0.422
		 #6: 0.374
		 #7: 0.39
		 #8: 0.39
		 #9: 0.359
		 #10: 0.374
		 
	Average value = sum/# -> 0.393
	Uncertainty = (max - min)/2 -> 0.03
	
	Uncertaintly average: 0.393 +- 0.03
	
	Therefore, the expected values considering the performance of computer is 0.393 +- 0.03
	
   2.Example without additional implementation will not have bad cases
   being that the information is given and will only display values provided by the computer
   
    Discussion: 
    The following program can measure the execution time of function in a class object by using the 
    learning concepts learned in the course.
    
 */

#include <iostream>
//Based and adapted on program Cpptime.cpp &Cpptime.h by Bruce Eckel, Chapter 09.
#include <ctime>
using namespace std;

//Typedef to short unsigned int for a more convenient type 
typedef unsigned int uint;
	uint size = 10000;
//Creation of class TimeMachine1
class TimeMachine1 {
//Declaration of private members
	double test1;
	double test2;
public:
//Constructor that initializes predetermined values for measure
	TimeMachine1():
		test1(100),
		test2(10099)
	{};
//Destructor
	~TimeMachine1(){};
//Function of loop execution
	void application();
//Function members that send values of private members test1, test2
	double getTest1() const {return test1;}
	double getTest2() const {return test2;}
//Function members that changes values of private members test1, test2
	void setTest1() {test1++;}
	void setTest2() {test2--;}
};

void TimeMachine1::application(){
//Array functions that contain values that will be multiplied 
	double array1[size];
	double array2[size];
//For loop to add values and const variable 
	for(uint i = 0; i < size; i++) {
		array1[i] = getTest1();
		array2[i] = getTest2();
		const double multiply = array1[i] * array2[i];
		cout<<array1[i]<<" * "<<array2[i]<<" = "<< multiply<<endl;
		setTest1(); 
		setTest2();
	}
}

int main() {
//class object that will be executed
	TimeMachine1 execute;
//variables that will contain time of execution before and after compilation
	clock_t start, end;
	start = clock();
//Program execution
	execute.application();
	end = clock();
//Real time of execution of program 
	double fTime = (end - start)/double (CLOCKS_PER_SEC);
//Printed compilation time
	cout<<"Compilation time: "<<fTime<<endl;
	return 0;	
}