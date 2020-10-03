 //: C08:StringStack.cpp
 //Using static const to create a 
 //compiler-time constant inside a class
 #include <string>
 #include <bits/stdc++.h>
 #include <iostream>
 using namespace std;
 
class StringStack {
	static const int size = 100;
	const string* stack[size];
	int index;
public:
	StringStack();
	void push(const string* s);
	const string* pop();
};

StringStack::StringStack() : index(0) {
	 memset(stack,0,size * sizeof(string*));
}

void StringStack::push(const string* s) {
	if(index < size)
		stack[index++] = s;	
}
const string* StringStack::pop() {
	if(index > 0) {
		const string* rv = stack[--index]; // Toma el elemento anterior
		stack[index] = 0; //pon en zero el elemento actual
		return rv; //	devuelve el address 
	}
	return 0;	
}

string iceCream[] = {
	"pralines & cream",
	"fudge ripple",
	"jamocha almond fudge",
	"wild mountain blackberry",
	"raspberry sorbet",
	"lemon swirl",
	"rocky road",
	"deep chocolate fudge"
};

const int iCsz = 
	sizeof iceCream / sizeof *iceCream;
	
int main() {
	StringStack ss;
	for(int i = 0; i < iCsz; i++)
		ss.push(&iceCream[i]);
	const string* cp;
	while((cp = ss.pop()) != 0)	
		cout<<*cp<<endl;
}///:~