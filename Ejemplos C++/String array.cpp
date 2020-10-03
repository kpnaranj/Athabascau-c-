#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  ifstream input(".cpp");
  int words_counter=0;
  string word;

  while (input>> word){
    ++nwords;
	}
  cout << "The following file has " << nwords << "words" << endl;
}