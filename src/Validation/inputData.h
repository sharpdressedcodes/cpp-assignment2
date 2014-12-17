/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef INPUTDATA_H_
#define INPUTDATA_H_

#include "baseValidator.h"
#include <string>

using std::string;

namespace Validation {

class InputData : public BaseValidator<string> {
private:
    string delim;
public:
    InputData(string delim);
    bool operator() (string data);
    bool validate(string data);
};

}

#endif /* INPUTDATA_H_ */
