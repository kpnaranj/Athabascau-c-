//: TMA1Question3.cpp

/* 
   Title: TMA1Question3.cpp
   Description: 
   
    Write a program that uses two nested for loops and the modulus operator (%) to 
    detect and print the prime numbers from 1 to 10,000. (Prime numbers are natural 
    numbers that are not evenly divisible by any other number except for themselves 
    and one). Display all the primes found.

   Date: February 22, 2019
   Author: Kevin P. Naranjo Paredes
   Copyright: 2019 Kevin P. Naranjo Paredes
 */
 
 /*
   DOCUMENTATION
   
   Program Purpose: 
   
 		Meausure the undertanding of loops statements, proper use of aritmetic and logical
 		operations,and thinking behind coding for better approach in future projects and concepts  
 		
 		Apply a program tha can perform certain task using mathematical and logical operations 
 		
 	Compile: g++ TMA1Question3.cpp -o TMA1Question3.exe
 	Execution: ./TMA1Question3.exe
 	
 	Classes: none
 	Header files:
 		Question3 - header - additional file containing the function printPrime
 	functions: 
 		pintPrime - void - function that identifies and displays all found numbers 
 	Variables: 
 		printPrime() Local variables - void 
	 		pNumber - unsigned int - used to store the number of prime numbers to verify the program is 
	 		tracking all known prime numbers (prime number)
	 		pCounter- unsigned int - used to store and verify if a number is prime or not, if the counter 
	 		is two, at the end of the loop then is prime, if not then it returns to zero 
	 		pLine - unsigned int - used to limit the found numbers in each line for better readability of 
	 		the document and debugging
	 		i - unsigned int - used in first loop to confirm the number is prime after second loop verifies 
	 		the number of primes
	 		j - unsigned int - used in second loop to confirm each case number of prime numbers in the first
	 		loop 
	 		
	 	Notes: the use of unsigned in the int type is to save bites of memory, since we know we will work with 
	 	positive numbers only 
	 	
	 	The printPrime function is an optional feature since we can write down all our code in the main(), however;
	 	it is better for debugging and readability purposes 		 
 */
 
 /*
   TEST PLAN
  
    Normal case: 
   	>(Program is executed)
   	>The function printPrime() is called
   	>The local variable pCounter is evaluated in the first and second loop 
   	>pCounter enters into the first if statement condition (if i is a remainder of j increment your value each time)
   	>pCounter goes into the second if case (if you store 2 numbers, then you are prime, else you are not a prime)
   	>if pCounter is prime, then i is displayed in the command and restored to zero, if not, the value is only restored 
   	>Pline counts each prime number, if there are 10 prime numbers, then another line is created 
   	>(repeat process until you find all prime numbers)
   	>"Prime number #1 , Prime number #2, etc"
   	>There are 1229 prime numbers between 1 and 10,000
   
   	Notes: There is not bad case since there is not input for the user to store negative values or random text 
   	
   
    Discussion: 
    
   The program executes 1229 prime numbers between 1 and 10,000, which is confirmed by using research of different 
   online resources on the internet. The program is properly completing the task of findig prime numbers as expected 
   
   The program could have additional improvements to be able to find a prime number in a given range provided by the 
   user. 
   
 */
 
#include <iostream>
#include "Question3.h"
using namespace std;

int main(){
	// Print function to display all numbers
	printPrime();
	
	return 0;
}///:~