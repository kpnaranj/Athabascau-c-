//: C08rConstag.cpp
// Constants and aggregates
const int i[] = { 1, 2, 3, 4 };
//! float f[i[3]]; // Illegal
struct S { int i, j; };
const S S []={{1, 2}, {3,4}};
//! double d[s[l].j]; // Illegal
int main() { } ///:~