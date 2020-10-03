#ifndef N_H
#define N_H
#include "Question1.h"
#include <iostream>
#include <string>
#include <fstream>

//Declarations 
void validation(DVD dvd[],uint user, uint& temp);
void validate(uint &select);
void menu();
void frame();
void clean();
void accept(uint &select);
//Definitions 
void validation(DVD dvd[],uint user, uint& temp){
	std::string info;
	getline(std::cin,info);
	(dvd + user)->setFunctions(info,temp);
}

void validate(uint &select){
	if (!std::cin){
		std::cout<<"you have not enter a value"<<std::endl;
		clean();
	}	
}

void menu(){
	for(uint i=0; i<60; i++){
		if(i == 20){
			std::cout<<"MENU";	
		}
		else{
			std::cout<<"/";	
		}
	}
		
	std::cout<<std::endl;
	std::cout<<"Welcome to S&S videos, please "
		<<"choose one of the following actions"<<std::endl;
	std::cout<<"1. Show list of clients in the store"<<std::endl;
	std::cout<<"2. Change/add client of the list"<<std::endl;
	std::cout<<"3. Exit"<<std::endl;
	frame();
}

void frame(){
	std::cout<<std::endl;
	for(uint i=0; i<60; i++)
		std::cout<<"/";
	std::cout<<std::endl;
}

void clean(){
	std::cin.clear();
	std::cin.ignore(100,'\n');
}

void accept(uint &select){
	while(select>10||select<1){
		validate(select);
		std::cout<<"Incorrect output, please add a value again"<<std::endl;
		std::cin>>select;
	}	
}
#endif