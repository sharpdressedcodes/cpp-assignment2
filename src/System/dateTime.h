/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

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
	Saturday,
	eDaysMax
};

enum eMonths {
	eJanuary,
	eFebruary,
	eMarch,
	eApril,
	eMay,
	eJune,
	eJuly,
	eAugust,
	eSeptember,
	eOctober,
	eNovember,
	eDecember,
	eMonthsMax
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
	static string subtractDateTime(const string& date1, const string& date2,
			const string& time1, const string& time2);
	static string addTime(const string& time1, const string& time2);
	static string getStartOfWeek(const string& endDate);
	static string getEndOfWeek(const string& startDate);
	static int compareDates(const string& date1, const string& date2);
	static int getMaxDaysInMonth(int month);
	static string fixTime(const string& time);
	static string fixDate(const string& date);

};

}

#endif /* DATETIME_H_ */
