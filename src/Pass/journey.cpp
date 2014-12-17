/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "journey.h"

namespace Pass {

Journey::Journey ()
    : day(string()), departureTime(string()), arrivalTime(string()),
      fromStation(NULL), toStation(NULL){}

Journey::Journey(string day, string departureDate, string arrivalDate,
        string departureTime, string arrivalTime, System::Station *fromStation,
        System::Station *toStation){

    this->day = day;
    this->departureTime = departureTime;
    this->arrivalTime = arrivalTime;
    this->fromStation = fromStation;
    this->toStation = toStation;
    this->departureDate = departureDate;
    this->arrivalDate = arrivalDate;

}

Journey::~Journey(){}

string Journey::getDay() const {
    return this->day;
}

string Journey::getDepartureTime() const {
    return this->departureTime;
}

string Journey::getArrivalTime() const {
    return this->arrivalTime;
}

System::Station *Journey::getFromStation() const {
    return this->fromStation;
}

System::Station *Journey::getToStation() const {
    return this->toStation;
}

string Journey::toString() const {

    stringstream ss;

    ss << fromStation->getName() << " to "
            << toStation->getName() << " at " << departureTime;

    return ss.str();

}

/*
 * Returns the highest zone required.
 */
int Journey::getHighestZone() const{

    int result = 0;

    if (fromStation->getZone() > result)
        result = fromStation->getZone();

    if (toStation->getZone() > result)
        result = toStation->getZone();

    return result;

}

string Journey::getDepartureDate() const {
    return departureDate;
}

string Journey::getArrivalDate() const {
    return arrivalDate;
}

bool Journey::isSameDay(){

    return departureDate.compare(arrivalDate) == 0;

}

}
