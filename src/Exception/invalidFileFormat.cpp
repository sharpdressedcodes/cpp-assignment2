/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "invalidFileFormat.h"

namespace Exception {

InvalidFileFormat::InvalidFileFormat(string filename) :BaseException(string()){
    this->filename = filename;
}

string InvalidFileFormat::getMessage(){

    stringstream ss;
    ss << "Invalid format when reading " << this->filename;

    return ss.str();

}

}

