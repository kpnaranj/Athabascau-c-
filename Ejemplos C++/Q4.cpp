#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Declaration

void printValue (string arrayLine[100]);

//Definition

void printValue(string arrayLine[100]){
	for(unsigned int i=0; i<100; i++){
		cout<<"line #"<<i+1<<" "<<arrayLine[i]<<endl;
	}
}

// Execution 
int main(){
	ifstream inputFile("Text1.txt");
	string nLine;
	string arrayLine[100];
	
	for(unsigned int i=0; i<100; i++){
		getline(inputFile,nLine);
		arrayLine[i]=nLine;
	}
	
	printValue (arrayLine);
	
	cout<<"The array has been filled"<<endl;
	cout<<"End of compilation"<<endl;
	
}