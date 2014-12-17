/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "inputData.h"

namespace Validation {

InputData::InputData(string delim){
    this->delim = delim;
}

bool InputData::operator ()(string data) {

    return validate(data);

}

bool InputData::validate(string data){

    return data.find(delim) == string::npos;

}

}
