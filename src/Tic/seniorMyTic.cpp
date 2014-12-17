/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "seniorMyTic.h"

namespace Tic {

SeniorMyTic::SeniorMyTic() : ConsessionTic (){}

SeniorMyTic::SeniorMyTic(float credit,
        float discountRate, vector<string> freeDays)
    : ConsessionTic (credit, discountRate, freeDays){

    vector<string> days;

    days.push_back(System::DateTime::DAYS[System::Sunday]);
    this->setFreeDays(days);

}

SeniorMyTic::~SeniorMyTic(){}

/*
 * Calculate the real amount this user should be charged.
 */
float SeniorMyTic::getDiscountRate() const {
    return this->discountRate;
}

string SeniorMyTic::toString() const {
    return "";
}

}
