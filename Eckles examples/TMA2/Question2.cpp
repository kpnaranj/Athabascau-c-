#include "Question2.h"
#include <iostream>

using namespace std;
//Function definitions
Hen::Hen(){
	cout<<"Constructor Hen called"<<endl; 
}

Hen::~Hen(){
	cout<<"Destructor Hen called, bye chicken"<<endl; 
}

void Hen::display(){
	cout<<"Instance of Hen, chicken is in the parent class"<<endl;	
}

Hen::Nest::Nest(){
	cout<<"Constructor Nest called"<<endl;
}

Hen::Nest::~Nest(){
	cout<<"Destructor Nest called, bye nest"<<endl;	
}

void Hen::Nest::display(){
	cout<<"Instance of Nest, nests in first child class"<<endl;
}

Hen::Nest::Egg::Egg(){
	cout<<"Constructor Egg called"<<endl;
}

Hen::Nest::Egg::~Egg(){
	cout<<"Destructor Egg called, poor chick"<<endl;	
}

void Hen::Nest::Egg::display(){
	cout<<"Instance of Egg, chick is in the second child class"<<endl;	
}


