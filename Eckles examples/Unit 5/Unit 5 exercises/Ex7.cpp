
/*Modify Exercise 6 so that Nest and Egg each contain private data. Grant friendship
 to allow the enclosing classes access to this private data.
*/
 #include <iostream>
 
 //Amigo del principal para acceso a otros componentes 
 
 using namespace std;
 
 class Hen{
	public:
	void display();
	
	class Nest{
		friend Hen;
		public:
			
		private:
		void display();
		
		
		
		class Egg;
		friend Hen;
		
		class Egg{
				private:
				void display();
			}e;
		}h; 
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
		chicken.display();
		
		return 0;