/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef WEEKLY_H_
#define WEEKLY_H_

#include "../System/dateTime.h"
#include "travelPass.h"

namespace Pass {

class Weekly : public TravelPass {
public:
    static const float DEFAULT_PRICE;
    static const string DEFAULT_LENGTH;
    static const string DEFAULT_ZONES;

    Weekly();
    Weekly(float theCost);
    Weekly(string theLength, string theZones, float theCost);
    ~Weekly();
    void input();   // Data input for a Weekly object
    void print();  // Data output for a Weekly object
    bool isTravelPass(TravelPass& pUnknown);
    string toString();

    friend ostream& operator<<(ostream& stream, Weekly& pass);
    friend istream& operator>>(istream& stream, Weekly& pass);
    bool canAddJourney(Journey* journey);
    string getEndDate();
};

}


#endif /* WEEKLY_H_ */
