/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef ADULT_H_
#define ADULT_H_

#include "baseUser.h"
#include "../Tic/fullMyTic.h"

namespace User {

    class Adult : public BaseUser {
    public:
        Adult(string id, string name, string email, float credit);
        ~Adult();
    };

}


#endif /* ADULT_H_ */
