/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef BASEEXCEPTION_H_
#define BASEEXCEPTION_H_

#include <string>

using std::string;

namespace Exception {

    class BaseException{
    protected:
        string message;

    public:
        BaseException();
        BaseException(string message);
        virtual ~BaseException();
        virtual string getMessage() = 0;

    };
}

#endif /* BASEEXCEPTION_H_ */
