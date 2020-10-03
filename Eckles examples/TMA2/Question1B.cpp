#include "Question1.h"
#include <iostream>
#include <string>
using namespace std;

//Function to get dates of rent 
void DVD::getDates(){
	cout<<"Start of Rent: "<<getStart()<<endl;
	cout<<"End of the Rent: "<<getEnd()<<endl;
}
//Function to display class dvd 
void DVD::print(uint user){
	cout<<endl;
	
	for(unsigned int j=0; j<20; j++){
		if(j ==10){
			cout<<"User #"<<user+1<<endl;
		}
		else{
			cout<<" ";
			}
	}	
		
	cout<<endl;
		
	cout<<"User: "<<getName()<<endl;
	cout<<"Title of movie: "<<getTitle()<<endl;
	cout<<"Year of movie: "<<getGenre()<<endl;
	cout<<"Genre of the movie: "<<getYear()<<endl;
	cout<<"Cost of the movie/month: "<<getCost()<<endl;
	getDates();
	
}
//Function to add values to the class
void DVD::setFunctions(string info, uint change){
	bool isWorking = true; 

	while (isWorking == true){
		switch (change){
			case 1: userName = info;isWorking = false; break;
			//This two together
			case 2: movieTitle = info; isWorking = false;break;
			case 3: movieGenre = info;isWorking = false; break;
			//Then this ones 
			case 4: movieYear = info;isWorking = false; break;
			case 5: movieCost= info; isWorking = false;break;
			case 6: movieRentStart = info; isWorking = false;break;
			case 7: movieRentEnd = info; isWorking = false;break;
			
			default:cout<<"Incorrect value, please enter again"<<endl;isWorking = false;break;
		}
	}	
}