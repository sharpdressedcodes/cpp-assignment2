/*
 * dateTime.h
 *
 *  Created on: 18/11/2014
 *      Author: greg
 */

#ifndef DATETIME_H_
#define DATETIME_H_

#include "utility.h"
#include <string>
#include <sstream>

using std::string;

namespace System {

enum eDays {
	Sunday,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	eDaysMax
};

class DateTime {
private:

	static tm *getLocalTime();

public:

	static const string DAYS[];
	static const string MONTHS[];

	static string getCurrentDayOfWeek();
	static string getCurrentDate(string delim = string());
	static string getCurrentTime(string delim = string());
	static vector<string> getDaysAsVector();
	static string subtractTime(const string& time1, const string& time2);
	static string addTime(const string& time1, const string& time2);

};

}


#endif /* DATETIME_H_ */
