//============================================================================
// Name        : Exercises.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {

	vector<string>v;
	ifstream in("Hello.cpp");
	string line;
	string overall;

	while (getline(in,line))
		v.push_back(line);
	for (int i=0; i<v.size(); i++)
		overall=overall+v[i]+"\n";
	cout<<overall<<endl;
	return 0;
}
