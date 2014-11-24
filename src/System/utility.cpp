/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "utility.h"

namespace System {

const unsigned int Utility::STRING_CASE_CONVERSION = 32;

/*
 * Function to clear the input buffer.
 */
void Utility::clearInputBuffer(){

	char symbol;

	do {
		cin.get(symbol);
	} while(symbol != '\n');

}

/*
 * Ask the user for a number. Supports minimum and maximum values.
 */
int Utility::getIntFromConsole(const unsigned int min,
		const unsigned int max, const string& message,
		const string& errorMessage, bool allowEmpty){

	int i = -1;
	bool isValid = false;

	while (!isValid){

		string result;

		cout << message;

		cin.clear();
		getline(cin, result);

		if (cin.fail() || !isNumeric(result)){
			if (!allowEmpty)
				cerr << errorMessage << endl;
			//clearInputBuffer();
		} else {

			i = stringToInt(result);

			if ((unsigned int)i < min || (unsigned int)i > max){
				if (allowEmpty)
					return min - 1;
				cerr << errorMessage << endl;
			} else {
				isValid = true;
			}
		}

	}

	return i;

}

/*
 * Ask the user for a string. Supports minimum and maximum lengths.
 */
string Utility::getStringFromConsole(const unsigned int min,
		const unsigned int max, const string& message,
		const string& errorMessage, bool allowEmpty){

	bool isValid = false;
	string result;

	while (!isValid){

		cout << message;

		cin.clear();
		getline(cin, result);

		if (cin.fail() || result.length() < min || result.length() > max){
			if (allowEmpty)
				return "";
			cerr << errorMessage << endl;
		} else {
			isValid = true;

		}

	}

	return result;

}

string Utility::getStringChoiceFromConsole(const vector<string>& choices,
		const string& message, const string& errorMessage, bool allowEmpty){

	string result;
	bool isValid = false;
	size_t smallestLength = 1000;
	size_t longestLength = 0;

	for (vector<string>::const_iterator it =
			choices.begin(); it != choices.end(); ++it){
		size_t len = (*it).length();
		if (smallestLength > len)
			smallestLength = len;
		if (longestLength < len)
			longestLength = len;
	}

	while (!isValid){

		cout << message;
		cin.clear();
		getline(cin, result);

		if (result.length() == 0 && allowEmpty)
			return result;

		if (result.length() < smallestLength){
			cerr << errorMessage << endl;
			continue;
		} else if (result.length() > longestLength){
			cerr << errorMessage << endl;
			continue;
		}

		for (vector<string>::const_iterator it =
				choices.begin(); it != choices.end(); ++it){
			if (result.compare((*it).c_str()) == 0){
				isValid = true;
				break;
			}
		}

		if (!isValid)
			cerr << errorMessage << endl;

	}

	return result;

}

string Utility::getSubstringChoiceFromConsole(const unsigned int min,
			const vector<string>& choices, const string& message,
			const string& errorMessage, bool allowEmpty){

	string result;
	bool isValid = false;
	size_t smallestLength = min;
	size_t longestLength = 0;

	for (vector<string>::const_iterator it =
			choices.begin(); it != choices.end(); ++it){
		size_t len = (*it).length();
		if (longestLength < len)
			longestLength = len;
	}

	while (!isValid){

		cout << message;
		cin.clear();
		getline(cin, result);

		if (result.length() == 0 && allowEmpty)
			return result;

		if (result.length() < smallestLength){
			cerr << errorMessage << endl;
			continue;
		} else if (result.length() > longestLength){
			cerr << errorMessage << endl;
			continue;
		}

		for (vector<string>::const_iterator it =
				choices.begin(); it != choices.end(); ++it){
			if (toLower(result).compare(toLower((*it).substr(0,
					result.length())).c_str()) == 0){
				result = (*it);
				isValid = true;
				break;
			}
		}

		if (!isValid)
			cerr << errorMessage << endl;

	}

	return result;

}

/*
 * Convert a numeric string to an integer.
 */
int Utility::stringToInt(const string& str){

	long int result;
	istringstream buffer(str);

	buffer >> result;

	return (int)result;

}

float Utility::stringToFloat(const string& str){

	float result;
	istringstream buffer(str);

	buffer >> result;

	return result;

}

/*
 * Convert an integer to a string.
 */
string Utility::intToString(const int number){

	std::ostringstream ss;
	ss << number;

	return ss.str();

}

/*
 * Convert a float to a string.
 */
string Utility::floatToString(const float number, const int precision){

	stringstream ss;

	if (precision > -1){
		ss.setf(ios::fixed | ios::showpoint);
		ss.precision(precision);
	}

	ss << number;

	return ss.str();

}

/*
 * Test if all characters in a string are digits.
 */
bool Utility::isNumeric(const string& str, bool allowDot) {

	bool result = true;
	bool foundDot = false;

	for (string::const_iterator it = str.begin();
			it != str.end() && result; ++it){
		if (allowDot && (*it) == '.'){
			if (!foundDot){
				foundDot = true;
				continue;
			} else {
				return false;
			}
		}
		result = isDigit((*it));
	}

	return !str.empty() && result;

}

/*
 * Test if a character is a digit.
 */
bool Utility::isDigit(const char c){

	bool exists = false;

	for (char letter = '0'; letter != '9' + 1 && !exists; ++letter)
		exists = (letter == c);

	return exists;

}

bool Utility::fileExists(const string& filename){

	bool result = false;
	ifstream fs;

	try {
		fs.open(filename.c_str());
		result = fs.is_open();
		fs.close();
	} catch (...){}

	return result;

}

string Utility::loadFile(const string& filename){

	ifstream fs(filename.c_str());
	stringstream ss;

	while (!fs.eof()){
		string line;
		getline(fs, line);
		ss << line << endl;
	}

	fs.close();

	return ss.str();

}

bool Utility::saveFile(const string& filename, const string& data,
		bool append = false){

	bool result = false;
	ofstream fs;

	try {
		if (append)
			fs.open(filename.c_str(), ios::app);
		else
			fs.open(filename.c_str());
		fs << data;
		fs.close();
		result = true;
	} catch (...){}

	return result;

}

vector<string> Utility::explode(const string& str, const string& delim){

	string s(str);
	vector<string> arr;
	size_t pos = s.find(delim.c_str());

	while (pos != string::npos){
		arr.push_back(s.substr(0, pos));
		if (pos + 1 <= s.size()){
			s = s.substr(pos + 1);
			pos = s.find(delim.c_str());
			if (pos == string::npos)
				arr.push_back(s);
		} else {
			break;
		}
	}

	return arr;


}

string Utility::implode(const vector<string> arr, const string& delim){

	string result;

	for (vector<string>::const_iterator it =
			arr.begin(); it != arr.end(); ++it){
		result.append((*it));
		result.append(delim);
	}

	if (result.length() > 0 && result.compare(result.size() -
			delim.size(), delim.size(), delim) == 0)
		result = result.substr(0, result.size() - delim.size());

	return result;

}

bool Utility::startsWith(const string& str, const string& lookup){

	if (str.length() == 0 ||
			lookup.length() == 0 ||
			lookup.length() > str.length())
		return false;

	return str.compare(0, lookup.length(), lookup.c_str()) == 0;

}

bool Utility::endsWith(const string& str, const string& lookup){

	if (str.length() == 0 ||
			lookup.length() == 0 ||
			lookup.length() > str.length())
		return false;

	return str.compare(str.length() -
			lookup.length(), lookup.length(), lookup.c_str()) == 0;

}

string Utility::ltrim(const string& str, const string& lookup){

	string result(str);

	while (Utility::startsWith(result, lookup) &&
			lookup.length() < result.length())
		result = result.substr(lookup.length());


	return result;

}

string Utility::rtrim(const string& str, const string& lookup){

	string result(str);

	while (Utility::endsWith(result, lookup))
		result = result.substr(0, result.length() - lookup.length());

	return result;

}

string Utility::trim(const string& str, const string& lookup){

	string result(str);

	result = rtrim(ltrim(result, lookup), lookup);

	return result;

}

string Utility::replace(const string& str,
		const string& lookup, string replacement, bool all){

	string result(str);
	size_t pos = result.find(lookup.c_str());

	while (pos != string::npos){
		result.replace(pos, lookup.length(), replacement.c_str());
		if (!all)
			break;
		pos = result.find(lookup.c_str());
	}

	return result;

}

string Utility::toLower(const string& str){

	string s(str), result;

	for (string::iterator it = s.begin(); it != s.end(); ++it){
		char c = (*it);
		result.append(1, c > 'A' - 1 &&
				c < 'Z' + 1 ? c + STRING_CASE_CONVERSION : c);
	}

	return result;

}

string Utility::toUpper(const string& str){

	string s(str), result;

	for (string::iterator it = s.begin(); it != s.end(); ++it){
		char c = (*it);
		result.append(1, c > 'a' - 1 &&
				c < 'z' + 1 ? c - STRING_CASE_CONVERSION : c);
	}

	return result;

}

string Utility::reverse(const string& str){
	return string(str.rbegin(), str.rend());
}

//float Utility::round(const float num, const int precision){
//
//	stringstream ss;
//
//	ss.setf(ios::fixed | ios::showpoint);
//	ss.precision(precision);
//
//	ss << num;
//
//	return stringToFloat(ss.str());
//
//}

}
