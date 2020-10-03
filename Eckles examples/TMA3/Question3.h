#ifndef QUESTION3_H
#define QUESTION3_H

#include <fstream>
#include <iostream>
#include <cmath>

double const PI = atan(1)*4;

/*QUESTION A*/
//Start with a Point class to hold x and y values of a point.
class Point {
	//(hint: keep x and y separate In the calculation).
	double x, y;
public:
	Point () {};
	Point(double coordinateX,
	double coordinateY) : 
		x(coordinateX),
		y(coordinateY)
	{};
	~Point(){}
	//Overload the >> operator to print point values and the + and – 
	//operators to add and subtract point coordinates
	
	//Based and adapted on program integer.h & operatorInheritance.cpp
	//by Bruce Eckel, Chapter 12, Chapter 14.
	friend std::ostream &operator<<( std::ostream &out, const Point &coordinate);
	Point operator+ (const Point &point);
	Point operator- (const Point &point);

	double coordinateX() const {return x;}
	double coordinateY() const {return y;}
}; /*End of Question A*/


/*QUESTION B*/
//Create a base class Shape which will form the basis of your shapes.
//Based and adapted on program protected.cpp by Bruce Eckel, Chapter 14.
class Shape{
protected:
//provide the coordinates (Points) of a rectangle that encloses the shape
	Point maxMax, maxMin, minMax, minMin;
public:
	Shape(){}
	~Shape(){}
	//Name of the class
	virtual std::string name(){}
	//The Shape class will contain functions to calculate area and circumference of the shape
	virtual double area() {}
	virtual double circunference(){}
	//and a bounding box. 
	virtual void bounding(){}
	//Create a display()function that will display the name of the class
	//plus all stored information about the class (including area, circumference, and bounding box).
	virtual void display() {}	
	double distance(Point D);
}; /*End of Question B*/


#endif //QUESTION3_H