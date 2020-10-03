#include "Stack3.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	requireArgs (argc, 1); //Fine name is argument 
	ifstream in (argv[1]);
	assure (in, argv[1]);
	Stack textlines;
	string line;
	//Read file and store lines in the slack:
	while(getline(in, line))
		textlines.push(new string(line));
	//Pop the lines from the slack and print them:
	string* s;
	while((s = (string*)textlines.pop()) !=0){
		cout<<*s<<endl;
		delete s;	
	}	
	
}