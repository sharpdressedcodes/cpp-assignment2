/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "juniorMyTic.h"

namespace Tic {

JuniorMyTic::JuniorMyTic() : ConsessionTic(){

}

JuniorMyTic::JuniorMyTic(float credit,
        float discountRate, vector<string> freeDays)
    : ConsessionTic(credit, discountRate, freeDays){

}

JuniorMyTic::~JuniorMyTic(){

}

/*
 * Calculate the real amount this user should be charged.
 */
float JuniorMyTic::getDiscountRate() const {
    return this->discountRate;
}

string JuniorMyTic::toString() const {
    return "";
}

}
