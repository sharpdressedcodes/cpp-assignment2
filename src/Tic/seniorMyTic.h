/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef SENIORMYTIC_H_
#define SENIORMYTIC_H_

#include "consessionTic.h"
#include "../System/dateTime.h"

namespace Tic {

	class SeniorMyTic : public ConsessionTic {

	public:
		SeniorMyTic();
		SeniorMyTic(float credit,
				float discountRate = ConsessionTic::DEFAULT_DISCOUNT_RATE,
				vector<string> freeDays = vector<string>());
		~SeniorMyTic();
		float getDiscountRate() const;
		string toString() const;
	};

}

#endif /* SENIORMYTIC_H_ */
