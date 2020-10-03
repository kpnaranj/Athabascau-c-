//============================================================================
// Name        : Project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	vector<string> v;
	ifstream in("");
	string line;
	while (getline(in, line));
		v.push_back(line);
	for (int i=0; i<v.size(); i++){
		cout<<i<<":"<<v[i]<<endl;

	}
}
