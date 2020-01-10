/**********************************************************j
// author: tchoutedjoum dambou serges
// Student ID:109240176
// seneca email:stchoutatgoum@myseneca.ca
// section:sdd
///////////////////////////////////////////////////////////
**********************************************************/
#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H

#include <string>

namespace sict
{
	class Message
	{
	private:
		std::string c_tweety;
		std::string c_send;
		std::string c_msgTweet;
		std::string c_recept;
		bool c_directedToRep;
		size_t pos;
	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
		~Message();
	};
} // sict


#endif // !SICT_MESSAGE_H