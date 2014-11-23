/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef PASSEXISTS_H_
#define PASSEXISTS_H_

#include "baseException.h"

namespace Exception {

	class PassExists : public BaseException {
	public:
		PassExists();
		string getMessage();

	};

}

#endif /* PASSEXISTS_H_ */
