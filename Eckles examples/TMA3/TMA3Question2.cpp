//: TMA3Question2.cpp

/* 
   Title: TMA3Question2.cpp
   Description: 
   
   Rewrite program 1 using an inline function to perform the calculation. 
   In the test plan for this program (actual results section), compare the 
   time required by this program to execute against the time required by the
   first (non-inline) program.
 
   Date: Abril 12, 2019
   Author: Kevin P. Naranjo Paredes
   Copyright: 2019 Kevin P. Naranjo Paredes
 */
 
 /*
   DOCUMENTATION
   
   Program Purpose: 
 		Measure proper understanding of inline function as enhancement feature to increase 
 		execution time of a program 
 		Measure accurate use of inline and the cases when it should be used
 		Measure proper understanding of directive <ctime> in a function
 		Enforce concept learned in previous units with element operations and concepts from 
 		Unit 8,9,10,11 and 12
  
 
 	Compile: g++ TMA3Question2.cpp -o TMA3Question2.exe
 	Execution: ./TMA3Question2.exe
 		
 	Classes: 
 		TimeMachine2 - class - used to facilitate call of multiple functions and variables of the 
 		assignment in main
 		
 		Notes: TimeMachine2 is the version wit inline, TimeMachine1 is a version without inline function
 	
 	Variables: 
 	uint - unsigned int - typedef assignment given to functions to use only positive values
 		
 		In class TimeMachine1:
 		private:
	 		test1 - double - variable to store lowest value '100' that will be multiplied to a const local variable
			test2 - double - variable to store highest value '10,099' that will be multiplied to a const local variable
		public:
			TimeMachine2() - constructor - to store private variables:
			~TimeMachine2() - destructor - to delete private variables after finishing program
			application() - void - Separate function that creates two arrays of 10,000
			getTest1() - double const - member function that returns a constant variable from Test1 private member
			getTest2() - double const - member function that returns a constant variable from Test2 private member
			multiply() - inline - member function used in multipication of const values to save overheat on the stack
			and speed up the program
			setTest1() - void - member function that increases the value of test1 as it is looped in application function
			setTest2() - void - member function that decreases the valiue of test2 as it is looped in application function 
		
		In multiply():
			
			mult - double const - const value for multiplication whose value is determined at running time 
		
		In application():
			array1[] - double - array function that stores double values starting from 100 to 10,099
			array2[] - double -  array function that stores double values starting from 10,099 to 100
		
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
   	>"100 * 10099 = 1009900"
	>"101 * 10098 = 1019898"
	>"102 * 10097 = 1029894"
	>"........"
	>Program finishes execution
	>"10097 * 102 = 1029894"
	>"10098 * 101 = 1019898"
	>"10099 * 100 = 1009900"
	>Program shows compilation time
	>"Compilation time: 0.296"
	>Program finishes "return 0"

   	
   Normal case (multiple answers):
   	>Program is executed 
   	>Program shows values to be multiply and answer in scientiic expression 
   	>"100 * 10099 = 1009900"
	>"101 * 10098 = 1019898"
	>"102 * 10097 = 1029894"
	>"........"
	>Program finishes execution
	>"10097 * 102 = 1029894"
	>"10098 * 101 = 1019898"
	>"10099 * 100 = 1009900"
	>Program shows compilation time
	>"Compilation time: 0.281 0.312 0.234 "
	>Program finishes "return 0"
   
	Notes:
	1 .The time was significantly reduce for this compilation, the program shows the following 
	characteristics:
	
	Range times:
		 #1: 0.266
		 #2: 0.296
		 #3: 0.313
		 #4: 0.281
		 #5: 0.297
		 #6: 0.296
		 #7: 0.281
		 #8: 0.297
		 #9: 0.265
		 #10: 0.266
		 
	Average value = sum/# -> 0.286
	Uncertainty = (max - min)/2 -> 0.02
	
	Uncertaintly average: 0.286 +- 0.02
	
	Therefore, the expected values considering the performance of computer is 0.286 +- 0.02
	
	Comparison of values and performance:
	Clearly there is a higher performance in the inline function, here th values
	
	From TMA3Question1.cpp
		Uncertainty average: 0.393 +- 0.03
	From TMA3Question2.cpp
		Uncertainty average: 0.286 +- 0.02 
		
	Difference in performance: Av#1 - Av#2 -> 0.107 +- 0.01
	
	Therefore the program compiles at a rate of 0.107 +- 0.01 less time using inline than using 
	a void function for execution of programs
	Performance improvement with respect Av#1: (DIFF#1&2 / Av#1) * 100 -> 27.23% 
	
	The performance reduction is considered being almost a quarter more efficient (27.23%) with inline by avoiding 
	calling the overhead
		
	As learned in previous Units, the program shows expected outcomes by using a Inline function in
	the multiplication time and performance
	
   2.Example without additional implementation will not have bad cases
   being that the information is given and will only display values provided by the computer
   
    Discussion: 
    The following program improved the time of compilation of first program by adding Inline function 
    in the multiplication task. The result showed a reduction in time when compiling and different
    outcomes in the display part (instead of scientific notation, we receive normal notation).
    
    Notes:
    	Inlne function for larger projects is avoided by the compiler, therefore, having a short version of 
    	compilation is the best approach to reduce time in the execution of program 
    	
    	Despite Inline reduces time of compiling, we need to understand the drawbacks as well, for large executable
    	programs is prefered not using it for memory constraints, inline is used when performance is needed as shown in 
    	this program 
    
*/
 
#include <iostream>
//Based and adapted on program Cpptime.cpp &Cpptime.h by Bruce Eckel, Chapter 09.
#include <ctime>
using namespace std;

typedef unsigned int uint;
	uint size = 10000;

class TimeMachine2 {
	double test1;
	double test2;
public:
	TimeMachine2():
		test1(100),
		test2(10099)
	{};
	~TimeMachine2(){};
	void application();
	double getTest1() const {return test1;}
	double getTest2() const {return test2;}
	//Based and adapted on program Inline.cpp by Bruce Eckel, Chapter 09.
	void setTest1() {test1++;}
	void setTest2() {test2--;}
};
//Based and adapted on program Inline.cpp by Bruce Eckel, Chapter 09.
inline multiply(double x, double y){
	const double mult = x * y;
	return mult;
}

void TimeMachine2::application(){
	double array1[size];
	double array2[size];
	for(uint i = 0; i < size; i++) {
		array1[i] = getTest1();
		array2[i] = getTest2();
		cout<<array1[i]<<" * "<<array2[i]<<" = "
			<<multiply(array1[i], array2[i])<<endl;
		setTest1(); 
		setTest2();
	}
}

int main() {
	TimeMachine2 execute;
	clock_t start, end;
	start = clock();
	execute.application();
	end = clock();
	
	double fTime = (end - start)/double (CLOCKS_PER_SEC);
	
	cout<<"Compilation time: "<<fTime<<endl;
	return 0;	
}