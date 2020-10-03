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
	string word;

	cout<<"Please, enter a word:";cin>>word;

	ifstream input("words.txt");
	string line;

	while (input>>line){
		if (word==line){
			++counter;
		}
	}
	cout<<"Number of times that \"hello\" appear:"<<counter;

}
