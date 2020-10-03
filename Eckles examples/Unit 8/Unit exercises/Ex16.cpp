/*Modify ConstPointer.cpp removing comments on the error-causing 
lines one at a time, to see what error messages your compiler 
generates.*/

void t(int *){}

void u(const int* cip) {
	 //*cip = 2; //Illegal -- modifies value
	  /*error: assignment of read-only location ‘* cip’*/

	int i = *cip; // OK --copies value
	//int* ip2 = cip; // Illegal: non-const 	
	/*invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]*/
}

const char* v() {
	// return address of stati charater array:
	return "result of function v()";	
}

const int* const w() {
	static int i;
	return &i;	
}

int main() {
	int x = 0;
	int* ip = &x;
	const int * cip = &x;
	t(ip); //OK
	//t(cip); // Not OK
	/*error: invalid conversion from ‘const int*’ to ‘int*’ 
	[-fpermissive]
  	 t(cip); // Not OK
     Ex16.cpp:5:6: note:   initializing argument 1 of ‘void t(int*)’
 	void t(int *){}
	*/
	u(ip); //OK
	u(cip); //Also OK
	//char* cp = v(); //Not OK
	//error: invalid conversion from ‘const char*’ to ‘char*’ [-fpermissive]
	const char* ccp = v(); //OK
	//int* ip2 = w(); //Not OK
	//error: invalid conversion from ‘const int*’ to ‘int*’ [-fpermissive]
	const int* const ccip = w(); //OK
	const int* cip2 = w(); //OK
	//*w() = 1; //Not OK
	//error: assignment of read-only location ‘* w()’

} ///:~