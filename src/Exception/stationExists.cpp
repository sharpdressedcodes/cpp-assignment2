/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "stationExists.h"

namespace Exception {

StationExists::StationExists() : BaseException(string()){}

string StationExists::getMessage() {
	string s("Sorry, that station is already in use.");
	return s;
}

}
