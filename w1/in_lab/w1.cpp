/**********************************************************
// 2019/01/18
// author: tchoutedjoum dambou serges
// Student ID:109240176
// seneca email:stchoutatgoum@myseneca.ca
// section:sddl
**********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "process.h"
#include "String.h"

using namespace std;
using namespace sict;

int INITIAL = 3;
int main(int argc, char* argv[])
{
	if (argc <= 1) 
	{
		std::cout << "***Insufficient number of arguments***" << std::endl; 
		return 1; 
	}
	else 
	{
		 cout << "Command Line : ";
		for (int i = 0; i < argc; i++) 
		{
			std::cout << argv[i] << " "; 
		}
		std::cout << std::endl; 
	}
	for (int i = 1; i < argc; ++i) 
	{
		sict::process(argv[i]); 
	}
	return 0;
}