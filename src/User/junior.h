/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef JUNIOR_H_
#define JUNIOR_H_

#include "baseUser.h"
#include "../Tic/juniorMyTic.h"

namespace User {

	class Junior : public BaseUser {
	public:
		Junior(string id, string name, string email, float credit);
		~Junior();
	};

}

#endif /* JUNIOR_H_ */
