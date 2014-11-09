/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef UTILITY_
#define UTILITY_

#include <iomanip>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

/*
 * General purpose utility class.
 * This is a mix of a Singleton pattern along with static functions.
 */
class Utility {

private:

	/*
	 * Hide the constructors.
	 */
	Utility(){}
	Utility(Utility const&){}
	Utility& operator=(Utility const&);//{}

public:

	/*
	 * Staff supplied function.
	 */
	static void clearInputBuffer();

	/*
	 * Custom functions.
	 */
	static int getIntFromConsole(const unsigned int min,
			const unsigned int max, const string& message,
			const string& errorMessage, bool allowEmpty);
	static string getStringFromConsole(const unsigned int min,
			const unsigned int max, const string& message,
			const string& errorMessage, bool allowEmpty);
	static int stringToInt(const string& str);
	static string intToString(const int number);
	static string floatToString(const float number, const int precision);
	static bool isNumeric(const string& str);
	static bool isDigit(const char c);

};


#endif /* UTILITY_ */
