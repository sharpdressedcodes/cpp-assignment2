/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef JUNIORMYTIC_H_
#define JUNIORMYTIC_H_

#include "consessionTic.h"

namespace Tic {

	class JuniorMyTic : public ConsessionTic {

	public:
		JuniorMyTic();
		JuniorMyTic(float credit,
				float discountRate = ConsessionTic::DEFAULT_DISCOUNT_RATE,
				vector<string> freeDays = vector<string>());
		~JuniorMyTic();
		float getDiscountRate() const;

		string toString() const;
	};

}

#endif /* JUNIORMYTIC_H_ */
