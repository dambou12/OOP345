/**********************************************************
// Workshop 3 lab3: template
// Version 3.0
// 2019/01/31
// author: tchoutedjoum dambou serges
// Student ID:109240176
// seneca email:stchoutatgoum@myseneca.ca
// section:sdd
///////////////////////////////////////////////////////////
**********************************************************/


#ifndef SICT_LIST_H
#define SICT_LIST_H
#include<iostream>



namespace sict {
	template <typename T, int N>

	class List {

		T array[N];
		size_t  number = 0;

	public:

		List() {
		}

		size_t size() const
		{
			return number;
		}
		const T& operator[](size_t i) const 
		{
			return array[i];
		}

		void operator+=(const T& t) {
			if (number < N ) {

				array[number] = t;
				number++;
			}
		}





	};






}




#endif // !SICT_LIST.H


