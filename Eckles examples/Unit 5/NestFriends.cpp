//: C05: NestFriends.cpp
// Nested friends 
#include <iostream>
#include <cstring> //memset()
using namespace std;

const int sz = 20;

struct Holder{ 
	private:
		int a[sz];
	public:
		void initialize();
		
		struct Pointer;
		friend Pointer;
		
		struct Pointer {
			private:
				Holder* h;
				int* p;
			public:
				void initialize(Holder* h);
					// Move around the array;
				void next();
				void previous();
				void top();
				void end();
				// Acess values:
				int read();
				void set(int i);		
		};	
	};
	
// Como es un miembro tiene acceso a la informacion y cambio de su clase 

void Holder::initialize() {
	memset(a,0,sz * sizeof(int)); // para identificar cuanta memoria usar 4 * 20 
	// apunta a la funcion a, anade 0 en cada casilla, y anade 80 bytes de memoria en total
}

void Holder::Pointer::initialize(Holder* rv) {
	h= rv; // this h contains the information from all the pointers
	p= rv->a; // this p contains the information from the next a 
}

void Holder::Pointer::next() {
	if(p<&(h->a[sz - 1])) p++;	// if the address of p is less than the last pointer increase the address 
}

void Holder::Pointer::previous() {
	if(p > &(h->a[0])) p--;	//  if p is greater than the first one 
}

void Holder::Pointer::top (){
	p= &(h->a[0]); // this is the first pointer 
}

void Holder::Pointer::end() {
	p= &(h->a[sz - 1]); // This is the last pointer 
}

int Holder::Pointer::read() {
	return *p; // this returns the value 
}


void Holder::Pointer::set(int i) {
	*p=i;	// this pointer collects the data from i	
}

int main() {
	Holder h;
	Holder::Pointer hp, hp2;
	int i;
	
	h.initialize(); // h has the information of the docuemtn
	hp.initialize(&h); // hp uses the information from h
	hp2.initialize(&h); // hp2 uses the information from h, so you don't need to call
	for (i = 0; i < sz; i++){
		hp.set(i); // give a number
		hp.next();	// move to the next pointer 
	}
	hp.top(); // First one is at the top
	hp2.end(); // Second one is at the end 
	for(i = 0; i<sz; i++) {
		cout<<"hp ="<<hp.read()
			<<", hp2="<<hp2.read()<<endl;
		hp.next();
		hp2.previous();
	} 		
} ///:~

/*
	1) Use Holder h and initialize it
	2) Use nested loop of hp and hp2
	3) Since hp1 and hp2 are in holder you just need to give them the access key 
	

*/