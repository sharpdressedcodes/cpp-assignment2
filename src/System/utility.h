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
#include <fstream>
#include <map>
#include <vector>

using namespace std;
using std::map;

namespace System {

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

	static const unsigned int STRING_CASE_CONVERSION;

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
			const string& errorMessage, bool allowEmpty = false);
	static string getStringFromConsole(const unsigned int min,
			const unsigned int max, const string& message,
			const string& errorMessage, bool allowEmpty = false);
	static string getStringChoiceFromConsole(const vector<string>& choices,
			const string& message, const string& errorMessage,
			bool allowEmpty = false);
	static string getSubstringChoiceFromConsole(const unsigned int min,
			const vector<string>& choices, const string& message,
			const string& errorMessage, bool allowEmpty = false);
	static int stringToInt(const string& str);
	static float stringToFloat(const string& str);
	static string intToString(const int number);
	static string floatToString(const float number, const int precision = -1);
	static bool isNumeric(const string& str, bool allowDot = false);
	static bool isDigit(const char c);

	static bool fileExists(const string& filename);
	static string loadFile(const string& filename);
	static bool saveFile(const string& filename, const string& data, bool append);
	static vector<string> explode(const string& str, const string& delim);
	static string implode(const vector<string> arr, const string& delim);
	static bool startsWith(const string& str, const string& lookup);
	static bool endsWith(const string& str, const string& lookup);
	static string ltrim(const string& str, const string& lookup);
	static string rtrim(const string& str, const string& lookup);
	static string trim(const string& str, const string& lookup);
	static string replace(const string& str, const string& lookup, string replacement = std::string(), bool all = true);
	static string toLower(const string& str);
	static string toUpper(const string& str);
	static string reverse(const string& str);
	//static float round(const float num, const int precision);

	template <class T>
	static void deleteObjectMap(map<string, T> objectMap){

		vector<string> keys;

		if (objectMap.size() == 0)
			return;

		for (typename map<string, T>::const_iterator it = objectMap.begin(); it != objectMap.end(); ++it)
			keys.push_back((string)it->first);

		for (size_t i = 0; i < keys.size(); i++)
			delete objectMap[keys[i]];

	}

	template <class T>
	static void deleteObjectVector(vector<T> objectVector){

		for (size_t i = 0; i < objectVector.size(); i++){
			delete objectVector[i];
		}

	}

};

}

#endif /* UTILITY_ */
