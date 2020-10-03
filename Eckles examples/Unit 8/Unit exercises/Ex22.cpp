/*In ConstMember.cpp, remove the const specifier on the member 
function definition, but leave it on the declaration, to see
 what kind of compiler error message you get.*/
 class X {
     int i;
public:
     X(int ii);
     int f() const;
};
X::X (int ii) : i (ii) { }
int X::f() const { return i; } //const deleted
int main () {
     X xl (10);
     const X x2 (20);
     xl.f () ;
     x2.f () ;
} ///:~

/* Result 
error: prototype for ‘int X::f()’ does not match any in class ‘X’
 int X::f() { return i; } //const deleted
     ^
     error: candidate is: int X::f() const
      int f() const;


*/