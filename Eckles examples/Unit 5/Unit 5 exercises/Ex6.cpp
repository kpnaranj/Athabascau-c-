
/*
6.Create a Hen class. Inside this, nest a Nest class. Inside Nest, place an Egg
 class. Each class should have a display( ) member function. In main( ), create 
 an instance of each class and call the display( ) function for each one.
 */
 #include <iostream>
 using namespace std;
 
 class Hen{
	 public:
	 void display();
	class Nest{
		public: 
		void display();
			class Egg{
				public:
				void display();
			};
		}; 
	};
	
	void Hen::display(){
		cout<<"This is a hen"<<endl;
		
	}
	
	void Hen::Nest::display() {
		cout<<"This is a nest"<<endl;
		
	}
	
	void Hen::Nest::Egg::display(){
		cout<<"This is an egg"<<endl;
	}
	
	int main(){
		Hen chicken;
		Hen::Nest house;
		Hen::Nest::Egg chik; 	
		
		chicken.display();
		house.display();
		chik.display();
		
		return 0;
	}
	
	
	
 
 