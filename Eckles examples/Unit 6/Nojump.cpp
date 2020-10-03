//:C06:Nojump.cpp
// Can't jump past constructor 

class X {
public:
	X();	
};

X::X {}

void f(int i) {
	if(i < 10) {
	 //! goto jump1; //Error: goto bypasses init	
	}	
	X x1;
	jump1:
		switch(i) {
			case 1:
			X 	X2; // Constructor called here 
			break; 
		//!	case 2: // Error: case bypasses init
			X X3;  // Constructor called here 
			break;	
		}
}
