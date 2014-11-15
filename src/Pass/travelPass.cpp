/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "travelPass.h"

namespace Pass {

	TravelPass::TravelPass()
		: cost(0) {}

	TravelPass::TravelPass(string theLength, string theZones, float theCost)
		: length(theLength), zones(theZones), cost(theCost){}

	TravelPass::~TravelPass(){}

	string TravelPass::getLength() const {
		return length;
	}

	string TravelPass::getZones() const {
		return zones;
	}

	float TravelPass::getCost() const {
		return cost;
	}

	vector<Journey*> TravelPass::getJourneys() {
		return this->journeys;
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

	void TravelPass::addJourney(Journey* journey){
		this->journeys.push_back(journey);
	}

	void TravelPass::clearJourneys(){
		this->journeys.clear();
	}

}
