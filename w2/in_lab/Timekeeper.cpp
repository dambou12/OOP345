
// Workshop 2 - Copy and Move Semantics
// Text.cpp
// tchoutedjoum dambou serges
// id:109240176
//email:stchoutatgoum@myseneca.ca
// 2019/01/24
#include <iostream>
#include <iomanip>
#include <chrono>
#include "Timekeeper.h"
using namespace std;

namespace sict {



	Timekeeper::Timekeeper()
	{
		//noOfrecord = 0;
	}

	void Timekeeper::start()
	{
		start_Time = std::chrono::steady_clock::now();
	}

	void Timekeeper::stop()
	{
		end_Time = std::chrono::steady_clock::now();
	}

	void Timekeeper::recordEvent(const char * description)
	{
		auto C_seconds = std::chrono::duration_cast<std::chrono::milliseconds> (end_Time - start_Time);

		if (norecord < MAX) {

			record[norecord].message = description;
			record[norecord].unitTime = "seconds";
			record[norecord].durationObj = C_seconds;

			norecord++;
		}
	}

	void Timekeeper::report(std::ostream & os) const
	{
		os << "\nExecution Times:\n";
		for (int i = 0; i < norecord; i++)
		{
			os << record[i].message << ' ' << setw(5)
				<< record[i].durationObj.count() / 100000
				<< record[i].unitTime
				<< endl;
		}

	}


}