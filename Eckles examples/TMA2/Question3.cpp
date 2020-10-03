#include "Question3.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Text::Text(){/*cout<<"Constructor 1 called\n"*/}

Text::Text(string text){
	/*cout<<"Constructor 2 called\n";*/

	ifstream input(text.c_str());
	if (input.is_open()){
		cout<<"Loading..."<<endl;	
		
		string nLine;
		
		while(getline(input, nLine))
		addText += nLine + "\n";
	
		/*Alternatively
		while (input>>nLine){
			addText += nLine + " ";	
		}
	*/
	}
	else{
		cout<<"File missing, terminating program"<<endl;
	}
	
	
}

string Text::contents(){
	/*cout<<"content called\n";*/
	return addText;	
}

Text::~Text(){/*cout<<"Destructor";*/}





