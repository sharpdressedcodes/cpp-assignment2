/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef FULLMYTIC_H_
#define FULLMYTIC_H_

#include "myTic.h"

namespace Tic {

    class FullMyTic : public MyTic {
    public:
        FullMyTic();
        FullMyTic(float credit, vector<string> freeDays = vector<string>());
        ~FullMyTic();
        virtual float getRealAmount(const string& day, const float amount);

        string toString() const;
    };

}

#endif /* FULLMYTIC_H_ */
