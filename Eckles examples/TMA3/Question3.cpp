#include "Question3.h"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
//Declaration of overload operators, Question B:
//Based and adapted on program OperatorInheritance.cpp by Bruce Eckel, Chapter 14.
ostream &operator<<(ostream &out, const Point &coordinate) { 
	out <<"(" << coordinate.x
		<<", "<<coordinate.y<<") ";
	return out;            
}
//De
Point Point::operator+(const Point &point) {
	Point result = *this;
	result.x += point.x;
	result.y += point.y;
	return result;
}

Point Point::operator-(const Point &point) {
	Point result = *this;
	result.x -= point.x;
	result.y -= point.y;
	return result;	
}

double Shape::distance(Point D){
	double result = sqrt( pow(D.coordinateX(), 2) + 
						  pow(D.coordinateY(), 2));
	return result;
}