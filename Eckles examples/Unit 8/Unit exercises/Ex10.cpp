/*Write a const pointer to a const object. Show that you can only 
read the value that the pointer points to, but you can’t change 
the pointer or what it points to.*/

#include <iostream>
using namespace std;



int main() {
	int d = 1, e = 2;
	const int* const x = &d;
	cout<<*x<<endl;
	//!x = &e; //error: assignment of read-only variable ‘x’
	//!x = 3; //error: assignment of read-only location ‘*(const int*)x’
}