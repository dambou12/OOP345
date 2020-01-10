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
#include"LVPair.h"

namespace sict {

	//Class template List for managing an array of any datatype
	template <typename T, size_t N>

	class List {
		T a[N];
		size_t number = 0;

	public:

		//Query that returns number of elements stored in array
		size_t size() const {
			return number;
		};

		//Overloaded operator that receives an index 
		const T& operator[](size_t i) const {
			return a[i];
		};

		//Overloaded operator that appends a copy
		void operator+=(const T& t) {
			if (number < N) {
				a[number++] = t;
			}
		};
	};

	//Derived template class
	template<typename T, typename L, typename V, size_t N>
	class LVList :public List<T, N> {

	public:
		//Query that receivves a reference, returns the sum of all values
		V accumulate(const L& label)const
		{
			List<T, N>& temp = (List <T, N>&)*this;
			SummableLVPair<L, V> summable;
			V result = summable.getInitialValue();

			for (size_t i = 0; i < temp.size(); i++)
			{
				if (label == temp[i].getLabel())
				{
					result = temp[i].sum(label, result);
				}
			}
			return result;
		}
	};
}
#endif

