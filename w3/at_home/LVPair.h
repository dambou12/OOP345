
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

#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H
#include<iostream>

namespace sict {

	template <typename L, typename V>
	class LVPair {
		L label;
		V value;

	public:
		//Default 
		LVPair() {};

		//Constructor
		LVPair(const L& new_label, const V& new_value) :label(new_label), value(new_value) {};

		//Query that inserts into os the label and value 
		virtual void display(std::ostream& os) const {
			os << label << " : " << value << std::endl;
		};

		//Query to get label of object
		const L& getLabel() const {
			return label;
		}

		//Query to get label of object
		const V& getValue() const {
			return value;
		}
	};

	//Derived class template
	template <typename L, typename V>
	class SummableLVPair :public LVPair<L, V> {
		static V newValue;
		static size_t m_width;

	public:

		//Default constructor 
		SummableLVPair() {};

		//Overloaded constructor 
		SummableLVPair(const L& label, const V& v) :LVPair<L, V>(label, v) {
			if (m_width < label.size()) {
				m_width = label.size();
			}
		}

		//Returns initial value 
		static const V& getInitialValue() {
			return newValue;
		}

		//Returns sum of value and partially accumulated sum of V object
		V sum(const L& label, const V& sum) const {
			return (label == LVPair<L, V>::getLabel()) ? LVPair<L, V>::getValue() + sum : sum;

		}

		//Query that inserts into os the label and value 
		void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(m_width);
			LVPair<L, V>::display(os);
			os.unsetf(std::ios::left);
		}
	};

	//Declaration for field width
	template<typename L, typename V>
	size_t SummableLVPair<L, V>::m_width = 0u;

	//A template specialization for value
	template<>
	int SummableLVPair<std::string, int>::newValue = 0;

	//Specialization for value
	template<>
	std::string SummableLVPair<std::string, std::string>::newValue = "";

	//Specialization for sum value
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& s1, const std::string& s2) const {
		return (s1 == LVPair<std::string, std::string>::getLabel()) ? (s2 + " " + LVPair<std::string, std::string>::getValue()) : s2;

	};

	//Helper function that inserts into os object, LVPair
	template <typename L, typename V>
	std::ostream&  operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;

	};
}
#endif 
