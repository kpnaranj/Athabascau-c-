//C04:CppLib.cpp {O}
//C library converted to C++
// Declare structure and functions:
#include "Clib2.h"// "CppLib.h" in the book
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
using namespace std;
// Quantity of elements to add
// when increasing storage:
const int increment=100;

void Stash::initialize(int sz) {
	size=sz;
	quantity=0;
	storage=0;
	next=0;
}

int Stash::add(const void*element){
	if(next>=quantity)// enough space left?
		inflate(increment);
	//Copy element into storage,
	//Starting at next emply space:
	int startBytes=next*size;
	unsigned char*e=(unsigned char*)element;
	for(int i=0; i<size; i++)
		storage[startBytes + i] = e[i];
	next++;
	return (next - 1); //Index number;
}

void* Stash::fetch(int index){
	//Check index boundaries:
	assert(0<=index);
	if(index>=next)
		return 0;//To indicate the end
	//Prodeuce pointer to desired element:
	return &(storage[index * size]);
}

int Stash::count() {
	return next; //Number of elements in CStash 	
}

void Stash::inflate(int increase){
	assert(increase > 0);
	int newQuantity = quantity + increase;
	int newBytes = newQuantity * size;
	int oldBytes = quantity * size;
	unsigned char* b= new unsigned char[newBytes];
	for(int i= 0; i < oldBytes; i++)
		b[i] = storage [i]; // Copy old to new
	delete []storage; //Old storage
	storage = b; //Point to new memory
	quantity = newQuantity;		
}

void Stash::cleanup(){
	if (storage !=0) {
		cout<< "freeing storage" << endl;
		delete []storage;
	}
} ///:~

int main(){
	Stash intStash;
	intStash.initialize(sizeof(int));
	for(int i = 0; i < 100; i++)
		intStash.add(&i);
	for(int j = 0; j < intStash.count(); j++)
		cout<<"intStash.fetch ("<<j<<") = "
			<<*(int*)intStash.fetch(j)
			<<endl;
	//Holds 80-character strings:
	Stash stringStash;
	const int bufsize=80;
	stringStash.initialize(sizeof(char) * bufsize);
	ifstream in("CLib2.cpp");
	string line;
	while(getline(in, line))
		stringStash.add(line.c_str());
	int k=0;
	char*cp;
	while((cp =(char*)stringStash.fetch(k++)) !=0)
		cout<< "stringStash.fetch("<<k<<")="
			<<cp<<endl;
	intStash.cleanup();
	stringStash.cleanup();
} ///:~