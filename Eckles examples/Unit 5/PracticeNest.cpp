#include <iostream>
#include <cstring> //memset()
using namespace std;

// Set framework 

const int size = 50; // This member should be always constant 

struct Holder{
	private:
	int array[size];
	
	public:
	void initialize();
	
	struct Pointer; //Structure Pointer
	friend Pointer; // This structure is a friend of Holder
	
	struct Pointer{
	private:
	Holder* h_memory;
	int* n_pointer;
	
	public:
	void initialize(Holder *h_memory); // The same structure as declared
	// All void members
	void next();
	void previous();
	void top();
	void end();
	// 
	int read ();
	void set(int number); 
		
	};
};
 //The initialize function is to set all values to zero or a pointer 
void Holder::initialize(){
	memset(array,0, size*sizeof(int));
}

void Holder::Pointer::initialize(Holder* rv){ // set values of private 
	h_memory = rv; // you will control the memory motion 
	n_pointer = rv->array; // you will control the number motion  
}

void Holder::Pointer::next(){
	if(n_pointer<&(h_memory->array[size - 1])) n_pointer++;
}

void Holder::Pointer::previous() {
	if(n_pointer> &(h_memory->array[0])) n_pointer--;	
}

void Holder::Pointer::top(){
	n_pointer =& (h_memory->array[0]); //Both are integers 
}

void Holder::Pointer::end(){
	n_pointer = &(h_memory->array[size -1]);	// both are integers 
}

int Holder::Pointer::read(){
	return *n_pointer;	
}

void Holder::Pointer::set(int i) {
	*n_pointer = i;	
}

int main(){
	// All the initial values can be set like integers, pointers can work in functions
	
	Holder h;	
	Holder::Pointer hp, hp2;
	
	h.initialize();
	hp.initialize(&h); //Now I have to boxes with pointers in each direction 
	hp2.initialize(&h); //if both have the same address, then I don't really need 
						//to create another set function, same information
	
	for(int i=0; i<size; i++){
	hp.set(i);
	hp.next();	
	}
	hp.top();
	hp2.end();
	for(int j=0; j<size; j++){
	cout<<"The beginning is "<<hp.read()<<endl;
	cout<<"The end is "<<hp2.read() <<endl;
	hp.next();
	hp2.previous();
	}	
} ///:~