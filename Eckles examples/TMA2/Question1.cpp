#include "Question1.h"
#include <iostream>
#include <string>
using namespace std;

//Class definition 
//Constructor
DVD::DVD() {
	userName = "/0";
	movieTitle = "/0";
	movieGenre = "/0";
	movieYear ="/0";
	movieRentStart = "/0";
	movieRentEnd = "/0";
	movieCost = "/0";
}

//Destructor
DVD::~DVD(){};
//Functions to return values 
string DVD::getName(){
	return userName;	
}


string DVD::getTitle(){
	return movieTitle;	
}

string DVD::getGenre(){
	return movieGenre;	
}


string DVD::getYear(){
	return movieYear;	
}


string DVD::getStart(){
	return movieRentStart;	
}

string DVD::getEnd(){
	return movieRentEnd;	
}

string DVD::getCost(){
	return movieCost;	
}


