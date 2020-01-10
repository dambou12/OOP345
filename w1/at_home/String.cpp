/**********************************************************
// 2019/01/18
// author: tchoutedjoum dambou serges
// Student ID:109240176
// seneca email:stchoutatgoum@myseneca.ca
// section:sddl
**********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "String.h"

extern int INITIAL;
namespace sict
{
	

	String::String(const char *name) 
	{
		if (name == nullptr && name[0] != '\0') 
		{
			c_name[0] = '\0'; 
		}
		else 
		{
			//c_name = new char[3]; //allocating dynamic memory
			strncpy(c_name, name, max); //copying first 3 characters from name to c_name
			c_name[max] = '\0'; //setting the last block of memory of str as nullbyte
		}
	}

	void String::display(std::ostream & obj) const //display member function
	{
		
		obj << this->c_name;

	}

	std::ostream & operator<<(std::ostream & os, const String & refObj) //ostream helper
	{
		
		static int ItemNum = INITIAL;
		os << ItemNum << ": ";
		refObj.display(os);
		
		ItemNum++;
		
		return os;
	}
}
