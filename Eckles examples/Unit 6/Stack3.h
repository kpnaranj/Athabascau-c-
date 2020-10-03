//: C06:Stash3.h
// With constructors/destructors
#ifndef STACK3_H
#define STASH3_H

class Stack {
		struct Link {
			void* data;
			Link* next;
			Link(void*dat, Link* nxt);
			~Link();	
		}*head;
		
	public:
		Stack();
		~Stack();
		void push(void* dat); //Add new Link into the system 
		void* peek(); //To show the data in the last collumn 
		void* pop();//destroy last data and show data detroyed
};
