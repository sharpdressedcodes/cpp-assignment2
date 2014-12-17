/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "allDayZone1And2.h"

namespace Pass {

    const float AllDayZone1And2::DEFAULT_PRICE = 6.8;
    const string AllDayZone1And2::DEFAULT_LENGTH = "All Day";
    const string AllDayZone1And2::DEFAULT_ZONES = "Zones 1 and 2";

    AllDayZone1And2::AllDayZone1And2()
        : TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, DEFAULT_PRICE) {}

    AllDayZone1And2::AllDayZone1And2(float theCost)
        : TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, theCost) {}

    AllDayZone1And2::AllDayZone1And2(string theLength,
            string theZones, float theCost)
        : TravelPass(theLength, theZones, theCost) {}

    AllDayZone1And2::~AllDayZone1And2(){}

    void AllDayZone1And2::input(){

        cin >> *this;

    }

    void AllDayZone1And2::print(){

        cout << this->toString();

    }

    /*
     * I couldn't really see a use for this function. I think it should be
     * static because if you have to call this method from an already created
     * AllDayZone1And2 instance, then you should already know what it is.
     * Calling it statically makes more sense.
     */
    bool AllDayZone1And2::isTravelPass(TravelPass& pUnknown){

        AllDayZone1And2* test = dynamic_cast<AllDayZone1And2*>(&pUnknown);

        if (test)
            return true;
        else
            return false;

    }

    /*
     * Output a string representing this instance.
     */
    string AllDayZone1And2::toString(){

        stringstream ss;

        ss << this->length << " pass for " << this->zones << ", costing $"
            << Utility::floatToString(this->cost, 2) << endl;

        return ss.str();

    }

    ostream& operator<<(ostream& stream, AllDayZone1And2& pass){

        stream << pass.toString();

        return stream;

    }

    istream& operator>>(istream& stream, AllDayZone1And2& pass){

        cout << "Enter length: ";
        stream >> pass.length;

        cout << "Enter zones: ";
        stream >> pass.zones;

        cout << "Enter cost: ";
        stream >> pass.cost;

        return stream;

    }


    bool AllDayZone1And2::canAddJourney(Journey* journey){

        // Don't bother going any further if the journey isn't on the same day.
        if (!journey->isSameDay())
            return false;

        // Do we have any existing journeys?
        if (journeys.size() == 0)
            return true;

        // Are they for this day?
        vector<Journey*> j = getJourneys(journey->getDepartureDate());
        if (j.size() == 0)
            return false;

        // Is the time correct?
        if (Utility::stringToInt(j[j.size() - 1]->getArrivalTime()) <=
                Utility::stringToInt(journey->getDepartureTime()))
            return true;

        return false;

    }

}
