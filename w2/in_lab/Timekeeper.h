// Workshop 2 - Copy and Move Semantics
// Timekeeper.cpp
// tchoutedjoum dambou serges
// id:109240176
//email:stchoutatgoum@myseneca.ca
// 2019/01/24

#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H
#include <iostream>
#include <chrono>

namespace sict {
	const int MAX = 10;
	class Timekeeper {

		int norecord{ 0 };
		std::chrono::steady_clock::time_point start_Time;
		std::chrono::steady_clock::time_point end_Time;
		struct
		{
			std::chrono::steady_clock::duration durationObj;
			const char* message;
			const char* unitTime;
		} record[MAX];

	public:
		Timekeeper();
		void start();
		void stop();
		void recordEvent(const char* description);
		void report(std::ostream& os) const;

	};

}
#endif // !SICT_TIMEKEEPER_H
