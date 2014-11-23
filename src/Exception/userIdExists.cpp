/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "userIdExists.h"

namespace Exception {

	UserIdExists::UserIdExists(string toAppend) : BaseException(string()){
		this->toAppend = toAppend;
	}

	string UserIdExists::getMessage(){
		stringstream ss;
		ss << "Sorry, that id is already in use." << toAppend;
		return ss.str();
	}

}
