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

	vector<Journey*> TravelPass::getJourneys(string day) {

		if (day.length() == 0)
			return this->journeys;
		else {
			vector<Journey*> j;
			for (vector<Journey*>::const_iterator it = journeys.begin(); it != journeys.end(); ++it){
				if (day.compare((*it)->getDay()) == 0)
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

	void TravelPass::addJourney(Journey* journey){

		//if (canAddJourney(journey)){
			this->journeys.push_back(journey);
		//}

	}

	void TravelPass::clearJourneys(){

		Utility::deleteObjectVector(journeys);
		this->journeys.clear();

	}

	void TravelPass::removeJourney(Journey *journey){

		//journeys.
		//size_t i = 0;
		//vector<Journey*>::iterator it = remove(journeys.begin(), journeys.end(), 1);

		for (size_t i = 0, i_ = journeys.size(); i < i_; ++i){
			if (journey->toString().compare(journeys[i]->toString()) == 0){
				//journeys.erase(journeys.begin() + i);
				cout << "Erasing " << journeys[i]->toString() << endl;
				journeys.erase(journeys.begin() + i);
				break;
			}
		}

	}

}
