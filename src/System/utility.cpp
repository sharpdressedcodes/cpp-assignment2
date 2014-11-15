/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "utility.h"

namespace System {

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
		const string& errorMessage, bool allowEmpty = true){

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
		const string& errorMessage, bool allowEmpty = true){

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

	std::stringstream ss;

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

bool Utility::saveFile(const string& filename, const string& data, bool append = false){

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

	for (vector<string>::const_iterator it = arr.begin(); it != arr.end(); ++it){
		result.append((*it));
		result.append(delim);
	}

	if (result.length() > 0 && result.compare(result.size() - delim.size(), delim.size(), delim) == 0)
		result = result.substr(0, result.size() - delim.size());

	return result;

}

bool Utility::startsWith(const string& str, const string& lookup){

	if (str.length() == 0 || lookup.length() == 0 || lookup.length() > str.length())
		return false;

	return str.compare(0, lookup.length(), lookup.c_str()) == 0;

}

bool Utility::endsWith(const string& str, const string& lookup){

	if (str.length() == 0 || lookup.length() == 0 || lookup.length() > str.length())
		return false;

	return str.compare(str.length() - lookup.length(), lookup.length(), lookup.c_str()) == 0;

}

string Utility::ltrim(const string& str, const string& lookup){

	string result(str);

		/*	bool b = result.compare(0, lookup.length(), lookup.c_str()) == 0;

	while (b && lookup.length() < result.length()){
		result = result.substr(lookup.length());
		b = result.compare(0, lookup.length(), lookup.c_str()) == 0;
	}*/

	while (Utility::startsWith(result, lookup) && lookup.length() < result.length())
		result = result.substr(lookup.length());


	return result;

}

string Utility::rtrim(const string& str, const string& lookup){

	string result(str);

	/*if (result.length() == 0 || result.compare(lookup) == 0){
		result = "";
		return result;
	}

	bool b = result.compare(result.length() - lookup.length(), lookup.length(), lookup.c_str()) == 0;

	while (b){
		result = result.substr(0, result.length() - lookup.length());
		b = result.compare(result.length() - lookup.length(), lookup.length(), lookup.c_str()) == 0;
	}*/

	while (Utility::endsWith(result, lookup))
		result = result.substr(0, result.length() - lookup.length());

	return result;

}

string Utility::trim(const string& str, const string& lookup){

	string result(str);

	result = rtrim(ltrim(result, lookup), lookup);

	return result;

}

string Utility::replace(const string& str, const string& lookup, string replacement, bool all){

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

}
