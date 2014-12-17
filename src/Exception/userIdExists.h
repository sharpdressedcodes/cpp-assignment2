/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef USERIDEXISTS_H_
#define USERIDEXISTS_H_

#include "baseException.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

namespace Exception {

    class UserIdExists : public BaseException {
    private:
        string toAppend;

    public:
        UserIdExists(string toAppend = string());
        string getMessage();

    };

}

#endif /* USERIDEXISTS_H_ */
