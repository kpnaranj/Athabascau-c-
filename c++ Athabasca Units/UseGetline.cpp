//============================================================================
// Name        : Project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <fstream>
using namespace std;

int main(){
	ifstream in("Hello.cpp");
	ofstream out("Project2.cpp");
	string s;
	while (getline(in,s))
		out<<s<<"\n";
}
