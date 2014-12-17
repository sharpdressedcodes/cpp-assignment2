/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef CONSESSIONTIC_H_
#define CONSESSIONTIC_H_

#include "myTic.h"

namespace Tic {

    class ConsessionTic : public MyTic {
    protected:
        static const float DEFAULT_DISCOUNT_RATE;
        float discountRate;

    public:
        ConsessionTic();
        ConsessionTic(float credit,
                float discountRate = ConsessionTic::DEFAULT_DISCOUNT_RATE,
                vector<string> freeDays = vector<string>());
        virtual ~ConsessionTic();
        virtual float getRealAmount(const string& day, const float amount);
        virtual float getDiscountRate() const = 0;
        virtual void setDiscountRate(float newValue);
        virtual string toString() const = 0;
    };

}

#endif /* CONSESSIONTIC_H_ */
