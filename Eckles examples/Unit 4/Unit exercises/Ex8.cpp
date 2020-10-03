#include "Ex8.h"
#include <iostream>

using namespace std;

void 
Stack::Link::initialize(void* dat, Link*nxt) {
	data = dat;
	next = nxt;		
}

void Stack::initialize() { head = 0;}

void Stack::push(void* dat){
	Link* newLink= new Link;
	newLink->initialize(dat, head);
	head = newLink;
}

void* Stack::peek() {
	
	//require(head !=0, "Stack empty");
	return head->data;	
}

void* Stack::pop() {
	if(head == 0) return 0;
	void* result = head->data;
	Link* oldHead = head;
	head = head->next;
	delete oldHead;
	return result;
}

void Stack::cleanup() {
	//require(head == 0, "Stack not empty");
	if (head !=0)
		std::cout<<"Stack not empty"<<std::endl;	
}

int main(){
	
	Stack doubleStack;
	doubleStack.initialize();
	
	double modify = 0.1;
	const int stack_size = 25;
	
	for(int i = 0; i<stack_size; i++)
		doubleStack.push(new double (i * modify + modify));
	double *dPtr;
	
	while ((dPtr = (double*)doubleStack.pop()) !=nullptr ){
		
		cout<<*dPtr<<endl;
		delete dPtr;
	}
	
	return 0;
}