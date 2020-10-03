 //: C05: Stash.h
 //Converted to use access control
 #ifndef STASH_H
 #define STASH_H
 
 class Stash{
		int size;
		int quantity;
		int next;
		//Dinamically allocate array of bytes 
		unsigned char* storage;
		void inflate(int increase);
	
	public:
		void initialize(int size);
		void cleanup();
		int add(void*element);
		void* fetch(int index);
		int count(); 
 };
 
 #endif //STASH_H ///:~