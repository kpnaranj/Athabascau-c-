 //: C07:Stash3.cpp
 // Function overloading

#include "Stash3.h"
#include <iostream>
#include <cassert>
using namespace std;
const int increment = 100;

Stash::Stash(int sz) {
	size = sz;
	quantity = 0;
	next = 0;
	storage = 0;
}

Stash::Stash(int sz, int initQuantity) {
	size = sz;
	quantity = 0;
	next = 0;
	storage = 0;
	
	inflate(initQuantity);	
}

Stash::~Stash() {
	if(storage != 0) {
		cout<< "freeing storage" <<endl;
		delete []storage;
	}	
}

int Stash::add(void *element) {
	if(next >= quantity) 
		inflate(increment);	

	int startBytes = next * size;
	unsigned char* e = (unsigned char*)element;
	for(int i = 0; i < size; i++) //This only adds one element
		storage[startBytes + i] = e[i];
	next++;
	return(next - 1); 
}

void* Stash::fetch(int index) {
	if(index >=next)
		return 0;//To indicate the end
	//Produce pointer to desired element:
	return &(storage[index * size]);
}

int Stash::count(){
	return next;	
}

void Stash::inflate(int increase){
	assert(increase>0);
	
	int newQuantity = quantity + increase;
	int newBytes = size * newQuantity;
	int oldBytes = size * quantity;
	unsigned char* e = new unsigned char [newBytes];
	
	for(int i = 0; i < oldBytes; i++) 
		e[i] = storage [i];
	
	delete [](storage);
	storage = e;
	quantity = newQuantity;
} 