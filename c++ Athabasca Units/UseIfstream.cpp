//============================================================================
// Name        : Exercise.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	int number=0;
	ifstream in("List.txt");
	string out;
	while (in>>out)
		++number;
	cout<<"Number spaces per word: "<<number<<endl;

}
