/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "consessionTic.h"

namespace Tic {

    const float ConsessionTic::DEFAULT_DISCOUNT_RATE = 0.5;

    ConsessionTic::ConsessionTic() : MyTic() {
        this->discountRate = DEFAULT_DISCOUNT_RATE;
    }

    ConsessionTic::ConsessionTic(float credit,
            float discountRate, vector<string> freeDays) : MyTic() {
        this->discountRate = discountRate;
        this->credit = credit;
        this->freeDays = freeDays;
    }

    ConsessionTic::~ConsessionTic(){}

    /*
     * Calculate the real amount this user should be charged.
     */
    float ConsessionTic::getRealAmount(const string& day, float amount){

        return isFreeDay(day) ? 0 : amount - (this->discountRate * amount);

    }

    void ConsessionTic::setDiscountRate(float newValue){
        this->discountRate = newValue;
    }

}
