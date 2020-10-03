//: C06:Stack3.cpp
//Construcotrs/destructors

#include "Stack3.h"
using namespace std;

Stack::Link::Link(void * dat, Link * nxt){
	data = dat;
	next = nxt;	
}

Stack::Link::~Link(){}

Stack::Stack() { head = 0;}

void Stack::push(void* dat) {
	head = new Link(dat, head); // create a new box of values and assign to the 
								// first value 	
}

void* Stack::peek() {
	require(head !=nullptr; "Stack empty");
	return head->data; 
}

void* Stack::pop() {
	if(head ==0) return 0;
	void* result = head->data; // point to the data I want to eliminate 
	Link* oldHead = head; //use another box to point the data I save
	head = head->next; // Move my box to next entrance 
	delete oldHead;// delete the box I save the value 
	return result;	// Show result deleted 
}

Stack::~Stack() {
	require(head ==0; "Stack not empty");	
} ///:~