// Workshop 2 - Copy and Move Semantics
// Text.cpp
// tchoutedjoum dambou serges
// id:109240176
//email:stchoutatgoum@myseneca.ca
// 2019/01/24

#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <iomanip>
#include <cstring>
#include "Text.h"
#include "Timekeeper.h"
using namespace std;

namespace sict {




	Text::Text()
	{
		c_name = nullptr;
		count = 0;
	}

	Text::Text(string filename) : Text()
	{
		ifstream is(filename, std::ios::in);
		if (is.is_open()) {
			std::string line;
			while (getline(is, line)) {
				//getline(is, line);
				count++;
			}
			c_name = new string[count];
			is.clear();  // Reset
			is.seekg(0, std::ios_base::beg); // file position to begining

			for (size_t i = 0; i < count; i++) {
				getline(is, c_name[i]);
			}
			is.close();
		}

	}

	// Copy constructor
	Text::Text(Text& src) : Text()
	{
		//m_name = nullptr;
		//ct = 0;
		*this = src;


	} // l-value

	// copy assignment operator
	Text & Text::operator=(Text& rc)
	{
		if (this != &rc)
		{
			delete[] c_name;
			//m_name = nullptr;
			count = rc.count;

			c_name = new string[count];
			for (size_t i = 0; i < count; i++)
			{
				c_name[i] = rc.c_name[i];
			}

		}
		return *this;

	}

	// Destructor
	Text::~Text()
	{
		delete[] c_name;
		c_name = nullptr;
	}




	size_t Text::size() const
	{
		return count;
	}

}
