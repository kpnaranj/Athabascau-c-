#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  ifstream inputFile1("Text1.txt"); // To open the file document 
  ifstream inputFile2 ("TestQ1.cpp");
  unsigned int cWords=0;// To count the number of words in the document 
  char options;
  string nLine;
  
  cout<<"choose a file exercise to read, 1 for txt or 2 for cpp" <<endl; // Additional feature to learn 
  cin.get(options);
  
  if(options=='1'){
	   while (inputFile1>> nLine){ // To go word by word in the document
   		 ++cWords; // increment number until the document finishes
		}
		  cout << "The following file has " << cWords
		  	<<" white-space separated words" << endl;
	}
 if(options=='2'){
	   while (inputFile2>> nLine){ // To go word by word in the document
   		 ++cWords; // increment number until the document finishes
		}
		  cout << "The following file has " << cWords
		  	<<" white-space separated words" << endl;
	 }
  return 0;
}