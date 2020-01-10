
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
using namespace std;


namespace sict {

	template < typename L, typename V>

	class LVPair {
		L c_label;
		V c_value;

	public:
		LVPair()
		{
			
		}
		LVPair(const L& label, const V& value) 
		{
			 
				c_label = label;
				c_value = value;		  
		   
		}
		void display(std::ostream& os)const{

			os << c_label << " : " << c_value << endl;
		}

	};

	template< typename L,typename V>

	std::ostream& operator<<(std::ostream& os, const LVPair <L, V>& pair) {

		pair.display(os);
		return os;
	}

}


#endif // !SICT_LVPAIR_H
