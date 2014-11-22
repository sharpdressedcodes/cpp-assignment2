
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

string DateTime::subtractDateTime(const string& date1, const string& date2, const string& time1, const string& time2){

	// return the time between two dates in ddmmyyyy format

	stringstream ss;
	string timeDiff = subtractTime(time1, time2);
	int hours, d1, d2, m1, m2, y1, y2, d, m, y;//, dayMax1;//, dayMax2;
	string sdate1(date1), sdate2(date2);

	if (sdate1.length() == 7)
		sdate1.insert(0, "0");

	if (sdate2.length() == 7)
		sdate2.insert(0, "0");

	d1 = Utility::stringToInt(sdate1.substr(0, 2));
	d2 = Utility::stringToInt(sdate2.substr(0, 2));
	m1 = Utility::stringToInt(sdate1.substr(2, 2));
	m2 = Utility::stringToInt(sdate2.substr(2, 2));
	y1 = Utility::stringToInt(sdate1.substr(4));
	y2 = Utility::stringToInt(sdate2.substr(4));
	//dayMax1 = getMaxDaysInMonth(m1 - 1);
	//dayMax2 = getMaxDaysInMonth(m2 - 1);

	d = d2 - d1;
	m = m2 - m1;
	y = y2 - y1;

	//if (d < 1){
		//d += dayMax1;
		//--m;
	//}

	//while (m < 1){
		//m += eMonthsMax;
		//--y;
	//}

	hours = (d * 24) + (m * 24 * 12) + ( y * 24 * 12 * 365 );

	//cout << "DateTime::subtractDateTime: " << endl;
	//cout << "d1=" << d1 << " d2=" << d2 << " m1=" << m1 << " m2=" << m2 << " y1=" << y1 << " y2=" << y2 << " d=" << d << " m=" << m << " y=" << y << endl;
	//cout << "HOURS=" << hours << endl;

	//ss << d << m << y;
	ss << hours << "00";
	return addTime(timeDiff, ss.str());

	//return ss.str();

}

string DateTime::subtractTime(const string& time1, const string& time2){

	int h = 0, m = 0;
	int hour1, hour2;
	int minute1, minute2;
	stringstream ss;
	string sh, sm;
	const int mMax = 60;

	hour1 = Utility::stringToInt(time1.substr(0, time1.length() == 3 ? 1 : 2));
	hour2 = Utility::stringToInt(time2.substr(0, time2.length() == 3 ? 1 : 2));

	minute1 = Utility::stringToInt(time1.substr(time1.length() - 2, 2));
	minute2 = Utility::stringToInt(time2.substr(time2.length() - 2, 2));

	h = hour2 - hour1;
	m = minute2 - minute1;

	//cout << "DateTime::subtractTime: " << endl;
	//cout << "h1=" << hour1 << " h2=" << hour2 << " m1=" << minute1 << " m2=" << minute2 << " h=" << h << " m=" << m << "\n" << endl;

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

	hour1 = Utility::stringToInt(time1.substr(0, time1.length() == 3 ? 1 : 2));
	hour2 = Utility::stringToInt(time2.substr(0, time2.length() == 3 ? 1 : 2));

	minute1 = Utility::stringToInt(time1.substr(time1.length() - 2, 2));
	minute2 = Utility::stringToInt(time2.substr(time2.length() - 2, 2));

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

string DateTime::getStartOfWeek(const string& endDate){

	//10122014
	string date(endDate), startDate, day, month, year;

	if (date.length() == 7)
		date.insert('0', 0);

	day = date.substr(0, 2);
	month = date.substr(2, 2);
	year = date.substr(4);

	int iday, imonth, iyear, dayMax;

	iday = Utility::stringToInt(day);
	imonth = Utility::stringToInt(month);
	iyear = Utility::stringToInt(year);
	dayMax = getMaxDaysInMonth(imonth - 1);

	iday -= eDaysMax;

	if (iday < 1){
		iday += dayMax;
		--imonth;
	}

	while (imonth < 1){
		imonth += eMonthsMax;
		--iyear;
	}

	stringstream ss;
	ss << iday << imonth << iyear;

	return ss.str();

}

string DateTime::getEndOfWeek(const string& startDate){

	//10122014
	string date(startDate), endDate, day, month, year;

	if (date.length() == 7)
		date.insert('0', 0);

	day = date.substr(0, 2);
	month = date.substr(2, 2);
	year = date.substr(4);

	int iday, imonth, iyear, dayMax;

	iday = Utility::stringToInt(day);
	imonth = Utility::stringToInt(month);
	iyear = Utility::stringToInt(year);
	dayMax = getMaxDaysInMonth(imonth - 1);

	iday += eDaysMax;

	if (iday > dayMax){
		iday -= dayMax;
		++imonth;
	}

	while (imonth >= eMonthsMax){
		imonth -= eMonthsMax;
		++iyear;
	}

	stringstream ss;
	ss << iday << imonth << iyear;

	return ss.str();

}

int DateTime::compareDates(const string& date1, const string& date2){

	int result = 0;

	string d1(date1), d2(date2), day1, month1, year1, day2, month2, year2;

	if (d1.length() == 7)
		d1.insert(0, "0");

	if (d2.length() == 7)
		d2.insert(0, "0");

	//cout << "d1=" << d1 << " d2=" << d2 << "\n" << endl;

	day1 = d1.substr(0, 2);
	month1 = d1.substr(2, 2);
	year1 = d1.substr(4);
	day2 = d2.substr(0, 2);
	month2 = d2.substr(2, 2);
	year2 = d2.substr(4);

	int iday1, imonth1, iyear1, iday2, imonth2, iyear2;

	iday1 = Utility::stringToInt(day1);
	imonth1 = Utility::stringToInt(month1);
	iyear1 = Utility::stringToInt(year1);
	iday2 = Utility::stringToInt(day2);
	imonth2 = Utility::stringToInt(month2);
	iyear2 = Utility::stringToInt(year2);

	if (iday1 == iday2 && imonth1 == imonth2 && iyear1 == iyear2){
		result = 0;
	} else {

		if (iyear1 < iyear2)
			result = -1;
		else if (iyear1 > iyear2)
			result = 1;
		else if (imonth1 < imonth2)
			result = -1;
		else if (imonth1 > imonth2)
			result = 1;
		else if (iday1 < iday2)
			result = -1;
		else if (iday1 > iday2)
			result = 1;

	}

	return result;

}

int DateTime::getMaxDaysInMonth(int month){

	int dayMax = 0;

	switch (month){
	case eJanuary:
	case eMarch:
	case eMay:
	case eJuly:
	case eAugust:
	case eOctober:
	case eDecember:
		dayMax = 31;
		break;
	case eApril:
	case eJune:
	case eSeptember:
	case eNovember:
		dayMax = 30;
		break;
	case eFebruary:
		dayMax = 28;
		break;
	}

	return dayMax;

}

}
