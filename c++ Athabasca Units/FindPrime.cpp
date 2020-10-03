//============================================================================
// Name        : Assignment.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int nPrimos = 0;
    bool isPrimo;


    for(int i = 2;i < 10000; i++) {
        isPrimo = true;
        for(int j = 2; isPrimo && j <= sqrt((double)i); j++) {
            if(i % j == 0) {
                isPrimo = false;
            }
        }
        if(isPrimo) {

            nPrimos++;
        }
    }

    cout << nPrimos << " encontrados." << std::endl;
    return 0;
}

/*int main(){

	for (int i=2; i<10000; i++){
		int primeCounter=0;
		for (int j=2; j<=i; i++){
			if(i%j==0){
				primeCounter++;
			}
			if(primeCounter==2){
				break;
			}
		}
		if(primeCounter==1){
			cout<<i<<"";
		}
		primeCounter=0;
	}
}*/
