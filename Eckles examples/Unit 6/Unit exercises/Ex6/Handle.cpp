//Taken and adapted from Eckel's book Volume 1 Unit 5 Handle.cpp

#include "Handle.h"
#include <iostream>
using namespace std;

struct Handle::Cheshire {
	int i;	
};

Handle::Handle(){
	smile = new Cheshire; //Create a smile structure
	smile->i = 0; //Then declare all the things in that structure 
	cout<<"Initialized"<<endl; //Only for verification
}

Handle::~Handle(){
	delete smile;
	cout<<"Destroyed"<<endl; //Only for verification
}

int Handle::read() {
	return smile->i;	
}

void Handle::change(int x) {
	smile->i = x;	//Because it is nested loop is define with scope resolution
} ///:~

