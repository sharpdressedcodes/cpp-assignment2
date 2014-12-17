/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "travelPass.h"

namespace Pass {

    TravelPass::TravelPass()
        : length(string()), zones(string()), cost(0) {}

    TravelPass::TravelPass(string theLength, string theZones, float theCost)
        : length(theLength), zones(theZones), cost(theCost){}

    TravelPass::~TravelPass(){
        Utility::deleteObjectVector(journeys);
    }

    string TravelPass::getLength() const {
        return length;
    }

    string TravelPass::getZones() const {
        return zones;
    }

    float TravelPass::getCost() const {
        return cost;
    }

    /*
     * Return all journeys, or all journeys for a certain day.
     */
    vector<Journey*> TravelPass::getJourneys(string day) {

        if (day.length() == 0)
            return this->journeys;
        else {
            vector<Journey*> j;
            for (vector<Journey*>::const_iterator it = journeys.begin();
                    it != journeys.end(); ++it){
                string s(Utility::isNumeric(day) ?
                        (*it)->getDepartureDate() :
                        (*it)->getDay());
                if (day.compare(s) == 0)
                    j.push_back((*it));
            }
            return j;
        }

    }

    void TravelPass::setLength(string newLength){
        length = newLength;
    }

    void TravelPass::setZones(string newZones){
        zones = newZones;
    }

    void TravelPass::setCost(float newCost){
        cost = newCost;
    }

    /*
     * Add journey, and initialise required variables.
     */
    void TravelPass::addJourney(Journey* journey){

        if (journeys.size() == 0){
            startTime = journey->getDepartureTime();
            startDay = journey->getDay();
            startDate = journey->getDepartureDate();
        }

        journeys.push_back(journey);

    }

    void TravelPass::clearJourneys(){

        Utility::deleteObjectVector(journeys);
        this->journeys.clear();

    }

    void TravelPass::removeJourney(Journey *journey){

        for (size_t i = 0, i_ = journeys.size(); i < i_; ++i){
            if (journey->toString().compare(journeys[i]->toString()) == 0){
                journeys.erase(journeys.begin() + i);
                break;
            }
        }

    }

    string TravelPass::getStartTime() const {
        return startTime;
    }

    string TravelPass::getStartDay() const {
        return startDay;
    }

    string TravelPass::getStartDate() const {
        return startDate;
    }

    void TravelPass::setStartDate(string newValue){
        this->startDate = newValue;
    }

    string TravelPass::getEndDate(){
        return startDate;
    }

}
