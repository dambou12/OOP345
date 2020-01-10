// Workshop 2 - Copy and Move Semantics
// Text.h
// tchoutedjoum dambou serges
// id:109240176
//email:stchoutatgoum@myseneca.ca
// 2019/01/24

#ifndef SICT_TEXT_H
#define SICT_TEXT_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace sict {

	class Text {

		//string* ref;
		string* c_name;
		size_t count;
	public:
		Text();
		Text(string);
		Text(Text&);
		Text& operator=(Text&);
		~Text();

		size_t size() const;

	};



}
#endif // !SICT_TEXT_H
