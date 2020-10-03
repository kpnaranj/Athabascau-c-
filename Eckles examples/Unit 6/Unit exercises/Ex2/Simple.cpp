#include "Simple.h"
#include <iostream>
using namespace std;

Simple::Simple(){
	cout<<"The constructor has been used"<<endl;	
} //Constructors are public 

Simple::~Simple(){
	cout<<"The destructor is called after"<<endl;	
}