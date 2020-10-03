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
int Stash::add(void*element) {
	if(next >=quantity)
		inflate(increment);
		
	/*Inflate do three things:
	* 1) it increases the values quantity to 100 and size to 400
	* 2) it copies the old values out of scope
	* 3) Changes the values if the quantity is assigned  
	*/
	
	int starBytes = next * size;
	unsigned char* e=(unsigned char*) element; //change of values 
	for(int i=0; i < size; i++)
		storage[startBytes + i] = e[i];
	next++; // You increase the value of next
	return (next - 1); // You assigned the given value to add 
	
}

void Stash::inflate(int increase) { // Eventually used in add to incrase values 
	if(increase >0, 
		"Stash::inflate zero or negative increase");
	int newQuantity = quantity + increase;
	int newBytes = size * newQuantity;
	int oldBytes = quantity * size;
	unsigned char* b = new unsigned char [newBytes];
	
	for (int i = 0; i<oldBytes; i++)
		b[i] = storage[i];
	delete [](storage);
	storage = b;
	quantity = newQuantity;
	
	/*After thsi point all the pointers desappear because they are out of scope
	however their values still are in the range to create 
	*/
}

/*Conclusion: If I want to create a add value, I need two things
A place to increase the value if the other values goes out of scope
A place that use the value for additional elements in the array

Note: There is no need to delete elements created in the functions
using new since they are temporary in the heap 
*/
// You might need somethng to add from extern 
int Stash::add(void*element){
	if(next >= quantity)  //Quantity checks the number we have
		inflate(increment);
	
	int startBytes = size*next;
	unsigned char* e=(unsigned char*)element; //copy new value
	
	for(int i = 0; i < size; i++)
		storage[startBytes + i] = e[i];	
	next++;
	return (next - 1); //Index number 
}

void Stash::inflate(int increase) {
	require(increase > 0, 
	"Incorreect Stash increment")	
	
	int newQuantity=quantity + increase;
	int newBytes = size * newQuantity;
	int oldBytes = size * quantity;
	unsigned char* b = new unsigned char [newBytes];
	
	for(int i=0; i<oldBytes; i++)
		b[i]=storage[i];
	delete[](storage);
	storage = b;
	quantity = newQuantity;
}

void* Stash::fetch(int index) {
	require (0 <= index, "Stash::fetch (-)index");
	if(index >= next)
		return 0;
		
	return & (storage[index * size]);	
}