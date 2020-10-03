
#ifndef TAM2QUESTION2_H
#define TAM2QUESTION2_H

class Hen{
public:
	Hen();
	~Hen();
	void display();
	
	class Nest{
	public:	
		Nest();
		~Nest();
		void display();
				
		class Egg{
		public:
			Egg();
			~Egg();
			void display();
		};
	};
};

#endif //TAM2QUESTION2_H///:~