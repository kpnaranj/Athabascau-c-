//Taken from Eckel's book Volume 1 Unit 6 Stack3.cpp

#include "Stack.h"
using namespace std;

Stack::Link::Link(void* dat, Link* nxt){
	next = nxt;
	data = dat;	
}

Stack::Link::~Link() {}

Stack::Stack(){
	head = 0;
}

void Stack::push(void* dat){
	head = new Link(dat, head);	
}

void* Stack::peek() {
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

Stack::~Stack() {
		
}

