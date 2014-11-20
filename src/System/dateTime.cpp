
#include "dateTime.h"

namespace System {

const string DateTime::DAYS[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
};

const string DateTime::MONTHS[] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

tm *DateTime::getLocalTime(){

	time_t raw;
	tm *ti;

	time(&raw);
	ti = localtime(&raw);

	return ti;

}

string DateTime::getCurrentDayOfWeek() {

	tm *ti = getLocalTime();

	return DAYS[ti->tm_wday];

}

string DateTime::getCurrentDate(string delim){

	tm *ti = getLocalTime();
	stringstream ss;

	ss << Utility::intToString(ti->tm_mday)
		<< delim << Utility::intToString(ti->tm_mon)
		<< delim << Utility::intToString(1900 + ti->tm_year);

	return ss.str();

}

string DateTime::getCurrentTime(string delim){

	tm *ti = getLocalTime();
	stringstream ss;

	ss << Utility::intToString(ti->tm_hour)
		<< delim << Utility::intToString(ti->tm_min)
		<< delim << Utility::intToString(ti->tm_sec);

	return ss.str();

}

vector<string> DateTime::getDaysAsVector(){

	vector<string> result;

	for (int i = 0, i_ = eDaysMax; i < i_; ++i)
		result.push_back(DAYS[i]);

	return result;

}

string DateTime::subtractTime(const string& time1, const string& time2){

	int h = 0, m = 0;
	int hour1, hour2;
	int minute1, minute2;
	stringstream ss;
	string sh, sm;
	const int mMax = 60;

	hour1 = Utility::stringToInt(time1.substr(0, 2));
	hour2 = Utility::stringToInt(time2.substr(0, 2));

	minute1 = Utility::stringToInt(time1.substr(2));
	minute2 = Utility::stringToInt(time2.substr(2));

	h = hour2 - hour1;
	m = minute2 - minute1;

	while (m > mMax){
		m -= mMax;
		h += 1;
	}

	sh = Utility::intToString(h);
	sm = Utility::intToString(m);

	if (sh.length() == 1)
		sh.insert(0, "0");

	if (sm.length() == 1)
		sm.insert(0, "0");

	ss << sh << sm;

	return ss.str();

}

string DateTime::addTime(const string& time1, const string& time2){

	int h = 0, m = 0;
	int hour1, hour2;
	int minute1, minute2;
	stringstream ss;
	string sh, sm;
	const int mMax = 60;

	hour1 = Utility::stringToInt(time1.substr(0, 2));
	hour2 = Utility::stringToInt(time2.substr(0, 2));

	minute1 = Utility::stringToInt(time1.substr(2));
	minute2 = Utility::stringToInt(time2.substr(2));

	h = hour1 + hour2;
	m = minute1 + minute2;

	while (m > mMax){
		m -= mMax;
		h += 1;
	}

	sh = Utility::intToString(h);
	sm = Utility::intToString(m);

	if (sh.length() == 1)
		sh.insert(0, "0");

	if (sm.length() == 1)
		sm.insert(0, "0");

	ss << sh << sm;

	return ss.str();

}

}
