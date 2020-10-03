 //: C05:Friends.cpp
 // Friends allows special access 
 //Declaration (incomplete type specification):
struct X;
 
struct Y {
	void f(X*);	 	 
};

struct X { //Definition 
	private:
		int i;
	public:
		void initialize();
		friend void g(X*, int); // Global friend // Hace que los datos de usuario sean pasados a privado
		friend void Y::f(X*); // Struct member friend // Hace que una parte de la estructura ese lincada para cambios
		friend struct Z; // Entire struct is a friend  // hace que toda la estructura este lincada para cambios 
		friend void h(); // manipula directamente los datos que se quieren anadir en privado
};

void X::initialize() {
	i = 0;
}

void g(X* x, int i) {
	x->i = i;
}

void Y::f(X* x) {
	x->i =47;	
}

struct Z {
	private:
		int j;
	public:
		void initialize();
		void g(X* x);
};

void Z:: initialize() {
	j = 99;		
}

void Z::g(X* x) {
	x->i += j;
}

void h(){
	X x;		// Control sobre los datos que se van a emplear en la funcion 
	x.i = 100; // Direct data manipulation		
}

int main() {
	X x;
	Z z;
	z.g (&x);
} ///:~