//:C06: Stash2.cpp {O}
// Constructor & destructors
#include "Stash2.h"
#include <iostream>
#include <cassert>

const int increment = 100;

Stash::Stash(int sz){
	size = sz;
	quantity = 0;
	next = 0;
	storage = nullptr;	
}

int Stash::add(void* element){
	if(next >= quantity)
		inflate(increment);
	int startBytes = size * next;
	unsigned char* e = (unsigned char*)element; // Change characteristics 
	for(int i = 0; i < size; i++)
		storage[startBytes + i] = e[i];
	next++;
	return (next - 1);
}

void Stash::inflate(int increase){
	require(increase > 0,
	"The value is less than 0");
	
	int newQuantity = quantity + increase;
	int newBytes = size * newQuantity;
	int oldBytes = size * quantity;
	unsigned char* e = new unsigned char [newBytes];
	
	for(int i = 0; i < oldBytes; i++)
		e[i] = storage[i];
		
	delete[](storage);
	storage = e;
	quantity = newQuantity;
}

void* fetch (int index){ //when it comes to function references, return always an address 
	assure(index > 0) 
	if (index >= next)
		return 0; // To prevent the system to go in a undefined number
	return &(storage[size * index]);	
}

int Stash::count(){
	return next;	
}

~Stash::Stash(){
	if(storage != nullptr){
		cout<<"freeig storage"<<endl;
		delete []storage;
	}
}