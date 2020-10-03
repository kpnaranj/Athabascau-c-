 //: C05: Public.cpp
 // Public is just like C's struct 
	#include <iostream>
	using namespace std;
	struct A{
		int i;
		char j;
		float f;
		void func();
	};
	
	void A::func() {}
	
	struct B {
		public:
			int i;
			char j;
			float f;
			void func();
	};
	
	void B:: func() {}
	
	int main() {
		A a; B b;
		a.i = b.i = 1;
		a.j = b.j = 'c';
		a.f = b.f = 3.14159;
		a.func();
		b.func();
		
		cout<<a.i<<b.i<<a.j<<b.j<<a.f<<b.f;
	} ///:~
	
	
 
 