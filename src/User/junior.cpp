/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "junior.h"

namespace User {

    Junior::Junior(string id, string name, string email, float credit)
        : BaseUser(id, name, email, credit){

        this->tic = new Tic::JuniorMyTic(credit);

    }

    Junior::~Junior(){}

}
