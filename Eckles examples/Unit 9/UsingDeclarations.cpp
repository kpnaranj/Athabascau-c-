//: C09: UsingDeclaration.h
#ifndef USINGDECLARATION_H
#define USINGDECLARATION_H
namespace U {
	inline void f() {}
	inline void g() {}	
}
namespace V {
	inline void f() {}
	inline void g() {}	
}
#endif // USINGDECLARATION_H ///:~

//: C10:UsingDeclaration1.cpp
#include "UsingDeclaration.h"
void h() {
	using namespace U; //Using directives 
	using V::f; //Using declaration
	f(); //calls V::f;
	U::f(); // Must fully qualify to call
}
int main() {} ///:~