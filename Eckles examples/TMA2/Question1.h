#ifndef DVD_USER_H
#define DVD_USER_H

#include <string>

typedef unsigned int uint; 

class DVD{
	std::string userName;
	std::string movieTitle;
	std::string movieGenre;
	std::string movieYear;
	std::string movieRentStart;
	std::string movieRentEnd;
	std::string movieCost;
	
public:
	//Constructors 
	DVD();
	~DVD();	
	
	//Get
	std::string getName();
	std::string getTitle();
	std::string getGenre();
	std::string getYear();
	std::string getStart();
	std::string getEnd();
	std::string getCost();
	void getDates();
	void print(uint user);
	
	//Set (this could be another constructor)
	void setFunctions(std::string info, uint change);
};

#endif //DVD_USER_H//:~
