/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef SENIOR_H_
#define SENIOR_H_

#include "baseUser.h"
#include "../Tic/seniorMyTic.h"

namespace User {

	class Senior : public BaseUser {
	public:
		Senior(string id, string name, string email, float credit);
		~Senior();
	};

}

#endif /* SENIOR_H_ */
