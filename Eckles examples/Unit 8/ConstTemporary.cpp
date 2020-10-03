//: C0 8:ConstTemporary.cpp
// Temporaries are const
class X {};
X f () { return X(); } // Return by value
void gl(X&) {} // Pass by non-const reference
void g2(const X&) {} // Pass by const reference
int main() {
     // Error: const temporary created by f():
///! gl(f());
     // OK: g2 takes a const reference:
     g2(f ());
} ///:~