//Taken from Eckel's book Volume 1 Unit 6 Stack3.cpp

#ifndef STACK_H
#define STACK_H

class Stack{
		struct Link{
			void* data;
			Link* next;
			Link(void* dat, Link* nxt);
			~Link();	
		}* head;
	public:
		Stack();
		~Stack();
		void push(void*dat);
		void* pop();
		void* peek();
};
#endif //STACK_H///:~