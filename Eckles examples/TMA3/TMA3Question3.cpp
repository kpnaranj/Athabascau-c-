//: TMA3Question3.cpp
	
/* 
   Title: TMA3Question3.cpp
   Description: 
   	Write a program that creates a class hierarchy for simple geometry.
   	
	a) Start with a Point class to hold x and y values of a point. Overload the >> 
	operator to print point values and the + and – operators to add and subtract point 
	coordinates (hint: keep x and y separate In the calculation).
	
	b) Create a base class Shape which will form the basis of your shapes. The Shape class
	 will contain functions to calculate area and circumference of the shape, plus provide
	 the coordinates (Points) of a rectangle that encloses the shape (a bounding box). 
	 These will be overloaded by the derived classes as necessary. Create a display() 
	 function that will display the name of the class plus all stored information about 
	 the class (including area, circumference, and bounding box).
	 
	c) Build the hierarchy by creating the Shape classes Circle, Square, and Triangle. For 
	these derived classes, create default constructors and constructors whose arguments can
	 initialize the shapes appropriately using the correct number of Point objects 
	 i.e., Circle requires a Point center and a radius; Square requires four Point vertices,
	  while Triangle requires three Point vertices).
	  
	d) In main(), create one instance each of the following: 
		a Circle with a radius of 23, 
		a Square with sides 25, 
		and a Triangle with sides 10, 20, 30. 
	
	Define all of them so that the origin (0,0) is somewhere within each object. 
	Display the information from each object.

   Date: Abril 12, 2019
   Author: Kevin P. Naranjo Paredes
   Copyright: 2019 Kevin P. Naranjo Paredes
 */
 
 /*
   DOCUMENTATION
   
   Program Purpose: 
 		Measure proper level of understanding about inheritance, virtual functions, subclasses 
 		and overloading functions for more complex programs in C++
 		Measure adecuate use of declarations and definition with complemetary unit 
 		Effectively use <cmath> libraries for aritmetic operations and conversion 
 		Identify classes and overloading operations to simplify work and efficiency in program 
 		Complement all learned Unit activities in a complex project to measure proper use of concepts
 		learned
 
 	Compile: g++ Question3.cpp TMA3Question3.cpp  -o TMA3Question3.exe
 	Execution: ./TMA3Question3.exe
 	
 	Classes:
 		Main classes: 
 			Point - class - object variable that contains points (x,y) to find arithmetic operations and
 			geometric shapes
 			Shape - class - public class that will contain virtual functions that will be declared after 
 			values have been declared 
 		
 		Subclasses:
 			Circle - class - object that will contain characteristics of a circle for shape
 			Square - class - object that will contain characteristics of a square for shape 
 			Triangle - class - object that will contain characteristics of a triangle for shape 
 	
 	Variables: 
 		In Question3.h
 		PI - double const - global expression used to store PI value using atan() = 3.14159
 		
 		in Point:
 			private:
 			x - double - variable that will contain information of coordinate x of a point
 			y - double - variable that will contain information of coordinate y of a point 
 			public:
 			Point() - default constructor - expression that contains default information to initialize x and y
 			Point(double .., double ..) - constructor - expression that contains predetermined information to 
 			initialize x and y
 			operator << -  friend ostream - overload function that displays point information for main 
 			operator +  - Point - overload operator that enables addition arithetic of Point functions
 			operator -  - Point - overload operator that enables subtraction arithmetic of Point functions
 			coordinateX() - double const - member function that returns a constant value of x
 			coordinateY() - double const - member function that returns a constant value of y
 			~Point() - destructor - destructor function to freeing memory after execution of program 
 		In Shape:
 			protected:
 			maxMax  - Point - Object variable that contains the maximum value of x and y of a shape for the
 			creation of a bounding box
 			maxMin - Point - Object variable that contains the max of x and min of y of a shape for the creation 
 			of a  bounding box
 			minMax - Point - Object variable that contains the min of x and max of y of a shhape for the creation
 			of a bounding box
 			minMin - Point - Object variable that contains the minimum values of x and y of a shape for the 
 			creation if a bounding box
 			public:
 			Shape() - default constructor - default constructor that initialize protected members with zero value
 			~Shape() - destructor - destructor function to freeing memory after execution of program 
 			bounding() - virtual void - default void that contains information that will be saved in protected members 
 		 	for each subclasses
			name() - virtual string - abstract name of a shape that will allocate multiple definitions of string in
			subclasses for definition of shape and bounding box
			area() - virtual double - abstract function that will contain multiple definitions of areas in 
			subclasses for definition of shape and bounding box
			circunference() - abstract function that will contain the shape of different circunference and perimeters 
			in subclasses for definition of shape and bounding box
			display() - abstract object that will display information of subclasses for definition of shape and bounding
			distance(Point D) - double - member function that determines the size of a point from x to y using arithmetic
			concepts 
			
		In Question3.cpp:
		In operation <<():
			out - ostream & -  used to overload class for display point values in cout format 
			coordinates - Point & - reference value that contains coordinate information that will be displayed in main
		In operation +():
			point - const Point - constant point that contains information of x and y that wants to be added
			result - Point - object local member that stores the resulted addition of values 
			
			Notes: The use of *this is to reference x and y to be added in result without the need of expressing their 
			expressions
		In operation -():
			point - const Point - constant point that contains information of x and y that wants to be reduced 
			result - Point - object local member that stores the resulted subtraction of values 
			
			Notes: The use of *this is to reference x and y to be subtracted in result without the need of expressing their 
			expressions
		In Shape::distance(Point D):
			result - double - local expression that contains mathematical expression to find distance between two points
		
		In TMA3Question3.cpp:
		in Circle:
		private:
		center - Point - private object member used as a reference of radius when creating of circle shape
		radius - double - private member used to store the radius of a circle to find area, circunference and bounding limits
		public:
		Circle() - default constructor- used to initialize default values of center and radius to zero
		Circle(Point coordinate, double r) - constructor - used to initialize center and radius values 
		with predetermined values in main 
		coordinate - Point - value given in main to be stored by center
		r - double - value given in main to be store in radius 
		name()- string - use of public class Shape to give the name of the class and returning "Circle"
		area() - double - use of public class Shape to give the area of a class and returning area formula
		of a circle
		circunference() - use of public class Shape to give the definition of circunference, it returns the 
		formula to find the circunference of a circle
		bounding - void - use of public class Shape to define limits of bounding box
		display - void - use of public class Shape to define information of circle (name, area, circunference and bounding)
		
		Notes:
		The bounding box is calculated by determining the maximum and minimum values that radius can have at point zero,
		it means that the bounding box will be a square-diamond with center (0,0) with a rotation of 45 degrees 
		Bounding box achieves expectations of limits since point (0,0) is within bounding and a square can be considered as a 
		rectangle for this purposes
		
		in Square:
		Private:
		side1, side2, side3, side4 - Point - used to determine the four points to build a square shape and calculations
		Public:
		Square() - constructor - default constructor
		Square(Point s1,Point s2, Point s3, Point s4)- constructor - used to determine predetermined values from main
		name() - string - similar to circle, it defines class shape, it returns "Square"
		calculation(Point& .., Point& .., Point& .., Point& ..) - void - used to determine distance between each point
		for area and circunference calculation
		area() - double - definition of virtual function, it returns formula to calculate area of a square
		circunference()- double - definition of virtual function, it returns formula to calculate perimeter of a square 
		small() - void - used to find minimum point value of four coordinates, either x or y
		large() - void - used to find maximum point value of four coordinates, either x or y
		bounding() - void - limit box of square function that will receive maximum of minimum values for virtual function 
		display() - void - use of public class Shape to define information of a square 
		
		in Triangle:
		Private:
		side1, side2, side3 - Point - used to determine the three points to build a triangle shape and calculations
		Public:
		Triangle() - constructor - default constructor
		Triangle (Point s1,Point s2, Point s3)- constructor - used to determine predetermined values of object class Triangle from main
		name() - string - similar to Circle and Square, it defines class shape, it returns "Triangle"
		calculation(Point& .., Point& .., Point& ..) - void - used to determine distance between each point for area and circunference 
		calculation
		area() - double - definition of virtual function, it returns formula to calculate area of a triangle
		circunference()- double - definition of virtual function, it returns formula to calculate perimeter of a triangle
		small() - void - used to find minimum point value of four coordinates, either x or y
		large() - void - used to find maximum point value of four coordinates, either x or y
		bounding() - void - limit box of square function that will receive maximum of minimum values for virtual function Shape 
		display() - void - use of public class Shape to define information of a triangle 
		
		in main():
		
		center - Point - object variable used to define all shapes coordinates to origin (0,0) so that is somewhere within each object
		squareUp - Point - object variable used to define coordinate y to 25, (0,25), with respect to the origin (0,0) to measure 25 length 
		squareRight - Point - object variable used to define coordinate x 25 wih respect last coordinate, (25,25), to measure 25 length 
		squareDown - Point - object variable used to define coordinate x 25 with respect the origin and last coordinate to measure square
		tringleUp - Point - object variables used to define coordinate y 30 with respect the origin (0,0) to make first side of a triangle (0,30)
		triangleDown - Point - object variable used to define coordinate y 10 with respect the origin(0,0) to make second and third side of a 
		triangle with respect first side (0,10),(10,30)
		
		Notes: For triangle question, the given points are collinear, meaning that the three points lie on the same line, for the purpose of the exercise,
		we will use colliner points and define them as a triangle to test the program based on the conditions requested 10,20,30

		Circle c(center, 23) - object subclass that contains a center pointer and a radius of lenght 23
		Square s(center, squareUp, squareRight, squareDown) - object subclass that contains four points to draw a square figure in right order from: 
		(0,0)-> (0,25) -> (25,25) -> (25,0)-> (0,0)
		
		Triangle t(center, triangleUp, triangleDown) - object subclass that contains three points to draw a square figure in right order from:
		(0,0)-> (0,30) -> (0,10) ->(0,0)
		
 */
 
 /*
   TEST PLAN
 
   Normal case ()
   	>Program is executed 
   	>Program shows circle subclass information
	>	This is a Circle
	>	Area of Circle: 1661.9
	>	Perimeter of Circle: 144.513
	>	Bounding box: (0, -23) (0, 23) (23, 0) (-23, 0)"
	>Program shows square subclass information
	>	This is a Square
	>	Area of Square: 625
	>	Perimeter of Square: 100
	>	Bounding box: (0, 0) (0, 25) (25, 25) (25, 0)
	>Program shows trinagle subclass information
	>	This is a Triangle
	>	Area of Triangle: 0
	>	Perimeter of Triangle: 60
	>	Bounding box: (0, 0) (0, 30) (0, 30) (0, 0)
	>Program finishes 
 
   Notes: 
   1. Example without user input request will not have bad cases
   being that the information is provided already

    Discussion: 
    
   The program is a simple geometry calculator that displays the area, circunference and 
   limits of different shapes (circle, square and triangle) by using inheritance and virtual
   functions
   
   The program could be more complex by adding more overloading functions for display values and 
   other arithmetic functions.
   
   The program can find measures of different areas according to the questions specifications and 
   concepts learned throughout the course 
 */

#include "Question3.h"
#include <iostream>
#include <string>
using namespace std;
	  
/*QUESTION C*/
//Based and adapted on program Instrument4.cpp by Bruce Eckel, Chapter 15.
//Build the hierarchy by creating the Shape classes:
//1. Circle
class Circle: public Shape{
	Point center;
	double radius;
public:
	//create default constructors and constructors whose arguments can 
	//initialize the shapes appropriately using the correct number of Point objects
	Circle(){}
	//Circle requires a Point center and a radius
	Circle (Point coordinate, double r): 
		center(coordinate), 
		radius(r)
	{}
	//Definition of virtual functions Question B
	string name(){return "Circle";}
	double area (){return PI * (radius * radius);}
	double circunference() {return 2 * PI * radius;}
	
	void bounding(){
		Point rX(radius, 0), rY(0, radius);
				
		minMin = center - rY;
		minMax = center + rY;
		maxMax = center + rX;
		maxMin = center - rX;
	}
	void display(){
		cout<<"This is a "<<name()<<endl;
		cout<<"Area of "<<name()<<": "<<area()<<endl;
		cout<<"Perimeter of "<<name()<<": "<<circunference()<<endl;
		cout<<"Bounding box: "<<minMin<<minMax<<maxMax<<maxMin<<endl;
	}
};

//2.Square
class Square: public Shape {
	Point side1, side2, side3, side4; 
public:
	//create default constructors and constructors whose arguments can 
	//initialize the shapes appropriately using the correct number of Point objects
	Square(){}
	//Square requires four Point vertices,
	Square(Point s1,Point s2, Point s3, Point s4):
		side1(s1),
		side2(s2),
		side3(s3),
		side4(s4) 
	{}
	//Supportive functions:
	void calculation(Point& AB,Point &BC, Point& CD, Point& DA){
		AB = (side2 - side1);
		BC = (side3 - side2);
		CD = (side4 - side3);
		DA = (side1 - side4);
	}
	//retrieved and adapted from:
	//https://stackoverflow.com/questions/9424173/find-the-smallest-amongst-3-numbers-in-c
	
	double small(double x, double y, double z, double w){
		return min(min(x,y),min(z,w));
	}
	
	double large(double x, double y, double z, double w){
		return max(max(x,y),max(z,w));	
	}
	//Definition of virtual functions Question B:
	string name(){return "Square";}
	
	double area(){
		Point AB, BC, CD, DA;
		double result{};
		
		calculation(AB,BC,CD,DA);
		
		if(distance(AB) == distance (BC) && distance(CD) == distance(DA))
			result = distance(AB) * distance (CD);
					
		else 
			cout<<"The object is assymetric, it is not a square"<<endl;
		
		/*Alternatively result = maxX.getCoordinateX() * maxY.getCoordinateY();*/
		
		return result;
	} 
	
	double circunference() {
		Point AB,BC,CD,DA;
		double result{};
		
		calculation(AB,BC,CD,DA);
		
		if(distance(AB) == distance(BC) && distance(CD) == distance(DA))
			result = distance(AB) + distance (BC) + distance (CD) + distance (DA);	
			
		else
			cout<<"The object is not a square"<<endl;

		return result;
	}	
	//Bounding box
	void bounding() {
		
		Point minXY(
			small(side1.coordinateX(),side2.coordinateX(),side3.coordinateX(),side4.coordinateX()),
			small(side1.coordinateY(),side2.coordinateY(),side3.coordinateY(),side4.coordinateY())
		);
		
		Point minXmaxY(
			small(side1.coordinateX(),side2.coordinateX(),side3.coordinateX(),side4.coordinateX()),
			large(side1.coordinateY(),side2.coordinateY(),side3.coordinateY(),side4.coordinateY())
		);
		
		Point maxXminY(
			large(side1.coordinateX(),side2.coordinateX(),side3.coordinateX(),side4.coordinateX()),
			small(side1.coordinateY(),side2.coordinateY(),side3.coordinateY(),side4.coordinateY())
		);
		
		Point maxXY(
			large(side1.coordinateX(),side2.coordinateX(),side3.coordinateX(),side4.coordinateX()),
			large(side1.coordinateY(),side2.coordinateY(),side3.coordinateY(),side4.coordinateY())
		);
		
		minMin = minXY;
		minMax = minXmaxY;
		maxMax = maxXY; 
		maxMin = maxXminY;
	}
	void display(){
		cout<<"This is a "<<name()<<endl;
		cout<<"Area of "<<name()<<": "<<area()<<endl;
		cout<<"Perimeter of "<<name()<<": "<<circunference()<<endl;	
		cout<<"Bounding box: "<<minMin<<minMax<<maxMax<<maxMin<<endl;
	};
};

//3. and Triangle

class Triangle: public Shape {
	Point side1, side2, side3;
public:
	//create default constructors and constructors whose arguments can 
	//initialize the shapes appropriately using the correct number of Point objects
	Triangle (){}
	//while Triangle requires three Point vertices
	Triangle (Point s1, Point s2, Point s3): 
		side1(s1),
		side2(s2),
		side3(s3)
	{}
	//Supportive functions 
	void calculation(Point& AB,Point &BC, Point& CA){
		AB = (side2 - side1);
		BC = (side3 - side2);
		CA = (side3 - side1);
	}
	
	double small(double x, double y, double z){
		return min(min(x,y),z);
	}
	
	double large(double x, double y, double z){
		return max(max(x,y),z);	
	}	
	//Virtual function definitions Question B:
	string name(){return "Triangle";}
	
	double area(){
		double s1,s2,s3;
		
		s1 = side1.coordinateX()* (side2.coordinateY() - side3.coordinateY());
		s2 = side2.coordinateX() * (side3.coordinateY() - side1.coordinateY());
		s3 = side3.coordinateX() * (side1.coordinateY() - side2.coordinateY());
		
		return abs((s1 + s2 + s3)/2);	
	}
	
	double circunference(){
		Point AB, BC, CA;
		double result;
		calculation(AB, BC, CA);
		result = distance(AB) + distance(BC) + distance(CA);
		return result;	
	}
	
	void bounding() {
	Point minXY(
		small(side1.coordinateX(),side2.coordinateX(),side3.coordinateX()),
		small(side1.coordinateY(),side2.coordinateY(),side3.coordinateY())
	);
		
	Point minXmaxY(
		small(side1.coordinateX(),side2.coordinateX(),side3.coordinateX()),
		large(side1.coordinateY(),side2.coordinateY(),side3.coordinateY())
	);
	
	Point maxXminY(
		large(side1.coordinateX(),side2.coordinateX(),side3.coordinateX()),
		small(side1.coordinateY(),side2.coordinateY(),side3.coordinateY())
	);
	
	Point maxXY(
		large(side1.coordinateX(),side2.coordinateX(),side3.coordinateX()),
		large(side1.coordinateY(),side2.coordinateY(),side3.coordinateY())
	);
					
		minMin = minXY;
		minMax = minXmaxY;
		maxMax = maxXY;
		maxMin = maxXminY;
	}

	void display(){
		cout<<"This is a "<<name()<<endl;
		cout<<"Area of "<<name()<<": "<<area()<<endl;
		cout<<"Perimeter of "<<name()<<": "<<circunference()<<endl;
		cout<<"Bounding box: "<<minMin<<minMax<<maxMax<<maxMin<<endl;	
	};
};
/*End of Question C*/

/*QUESTION D*/

//In main(), create one instance each of the following: 

int main(){
	//Define all of them (circle, square, triangle )so that the origin (0,0) is somewhere
	//within each other
	Point center (0,0);
	Point squareUp(0,25), squareRight(25,25), squareDown(25,0);
	Point triangleUp(0,30),triangleDown(0,10);
		
	//Circle, square and triangle defined at point (0,0):
	//a Circle with a radius of 23	
	Circle c(center, 23);
	//a Square with sides 25, 
	Square s(center, squareUp, squareRight, squareDown);	
	//and a Triangle with sides 10, 20, 30. 
	Triangle t(center, triangleUp, triangleDown);
	
	c.bounding();
	s.bounding();
	t.bounding();
	
	//Display the information from each object.
	c.display();
	cout<<endl;
	
	s.display();
	cout<<endl;
	
	t.display();
	//End of Question D 
	return 0;
	//End of program
}///:~