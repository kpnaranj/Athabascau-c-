//: C04: Stack.cpp {O}
// Linked list with nesting 
#include "Slack.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Stack::Link::initialize(void* dat, Link* nxt){
	data = dat;
	next = nxt;
}

void Stack::initialize() {head=0;}

void Stack::push(void* dat){
	Link* newLink = new Link;
	newLink->initialize(dat,head);
	head = newLink;
}

void* Stack::peek(){
	if(head != 0)
		cout<<"Stack empty";
	return head->data;
}

void* Stack::pop() {
	if(head == 0) return 0;
	void* result = head->data;
	Link* oldHead=head;
	head = head->next;
	delete oldHead;
	return result;
}

void Stack::cleanup(){
	if(head == 0)
	cout<< "Stack not empty";
} ///:~

int main(int argc, char*argv[]){
	 //File name is argument
	ifstream in(lists.txt);
	Stack textlines;
	textlines.initialize();
	string line;
	// Read file and store lines in the Slack:
	while(getline(in, line))
		textlines.push(new string(line));
	// Pop the lines from the Slack and print them:
	string* s;
	while((s=(string*)textlines.pop())!=0){
		cout<<*s<<endl;
		delete s;	
	}
	textlines.cleanup();	
} ///:~
