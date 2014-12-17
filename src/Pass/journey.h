/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef JOURNEY_H_
#define JOURNEY_H_

#include "../System/station.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

namespace Pass {

class Journey {

private:
    string day;
    string departureTime;
    string arrivalTime;
    System::Station *fromStation;
    System::Station *toStation;
    string departureDate;
    string arrivalDate;

public:
    Journey();
    Journey(string day, string departureDate, string arrivalDate,
            string departureTime, string arrivalTime,
            System::Station *fromStation, System::Station *toStation);
    ~Journey();
    string getDay() const;
    string getDepartureTime() const;
    string getArrivalTime() const;
    System::Station *getFromStation() const;
    System::Station *getToStation() const;
    string toString() const;
    int getHighestZone() const;
    string getDepartureDate() const;
    string getArrivalDate() const;
    bool isSameDay();
};

}

#endif /* JOURNEY_H_ */
