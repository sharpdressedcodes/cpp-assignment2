/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "fullMyTic.h"

namespace Tic {

FullMyTic::FullMyTic(){}

FullMyTic::FullMyTic(float credit, vector<string> freeDays) : MyTic() {
	this->credit = credit;
	this->freeDays = freeDays;
}

FullMyTic::~FullMyTic(){}

/*
 * Calculate the real amount this user should be charged.
 */
float FullMyTic::getRealAmount(const string& day, float amount){

	return isFreeDay(day) ? 0 : amount;

}

string FullMyTic::toString() const {
	return "";
}

}
