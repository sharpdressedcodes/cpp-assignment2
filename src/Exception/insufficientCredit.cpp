/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "insufficientCredit.h"

namespace Exception {

    InsufficientCredit::InsufficientCredit() : BaseException(string()) {}

    string InsufficientCredit::getMessage(){
        string s("Insufficient credit to perform that transaction!");
        return s;
    }

}

