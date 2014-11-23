/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef STATIONEXISTS_H_
#define STATIONEXISTS_H_

#include "baseException.h"

namespace Exception {

	class StationExists : public BaseException {
	public:
		StationExists();
		string getMessage();

	};

}

#endif /* STATIONEXISTS_H_ */
