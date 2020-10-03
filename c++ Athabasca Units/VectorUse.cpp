//============================================================================
// Name        : Exercise.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*Create a vector<float> and put 25 floating-point numbers
into it using a for loop. Display the vector.*/

#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<float>v;

	for(int i=0;i<25; i++){
		v.push_back(i+0.5);
	}

	for (int index=0; index<v.size(); index++){
		cout<<v[index]<<" ";
	}
	cout<<endl;
	for (int mult=0; mult<v.size(); mult++){
		v[mult]*=v[mult];
		cout<<v[mult]<<" ";
	}
	cout<<endl;
}
