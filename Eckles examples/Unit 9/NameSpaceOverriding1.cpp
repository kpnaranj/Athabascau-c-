#include "NamespaceMath.h"

int main(){
	using namespace Math;
	Integer a; // Hides Math::a;
	a.setSign (negative);
	//Now scope resolution is necessary
	//To select Math::a :
	Math::a.setSign(positive);
} ///:~