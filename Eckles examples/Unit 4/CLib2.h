//: C04: CppLib.h
// C-like library converted to C++

struct Stash {
	int size; 			//size of each space 
	int quantity; 		//Number of storage space	
	int next;			//Next emply space
		//Dynamically allocated array of bytes:
	unsigned char* storage;
	// Functions!
	void initialize(int size);
	void cleanup();
	int add(const void*element);
	void*fetch(int index);
	int count();
	void inflate(int increase);
}; ///:~