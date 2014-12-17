/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef BASEVALIDATOR_H_
#define BASEVALIDATOR_H_

namespace Validation {

template <class T>
class BaseValidator {
public:
    //typedef bool (T::*memberFunction)();
    virtual ~BaseValidator(){}
    virtual bool validate(T obj) = 0;
};

}

#endif /* BASEVALIDATOR_H_ */
