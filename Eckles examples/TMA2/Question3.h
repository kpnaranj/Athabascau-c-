
#ifndef QUESTION3_H
#define QUESTION3_H
#include <string>

typedef unsigned int uint;

class Text{
	std::string addText;
public:
	Text();
	Text(std::string text);
	~Text();
	std::string contents();
};
#endif ///QUESTION3_H//:~