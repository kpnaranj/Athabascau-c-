#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){
	
	ifstream input("Test File 1.txt");
	string line,option;
	while(getline(input,line)){
		
		cout<<line<<endl;
	
	}
}