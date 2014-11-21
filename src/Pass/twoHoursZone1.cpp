/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "twoHoursZone1.h"

namespace Pass {

	const float TwoHoursZone1::DEFAULT_PRICE = 2.5;
	const string TwoHoursZone1::DEFAULT_LENGTH = "2 Hours";
	const string TwoHoursZone1::DEFAULT_ZONES = "Zone 1";

	TwoHoursZone1::TwoHoursZone1()
		: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, DEFAULT_PRICE) {}

	TwoHoursZone1::TwoHoursZone1(float theCost)
		: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, theCost){}

	TwoHoursZone1::TwoHoursZone1(string theLength, string theZones, float theCost)
		: TravelPass(theLength, theZones, theCost) {}

	TwoHoursZone1::~TwoHoursZone1(){}

	/*
	 * Shortcut for Task C. This does not validate user input.
	 */
	void TwoHoursZone1::input(){

		cin >> *this;

	}

	void TwoHoursZone1::print(){

		cout << this->toString();

	}

	/*
	 * I couldn't really see a use for this function. I think it should be
	 * static because if you have to call this method from an already created
	 * TwoHoursZone1 instance, then you should already know what it is.
	 * Calling it statically makes more sense.
	 */
	bool TwoHoursZone1::isTravelPass(TravelPass& pUnknown){

		TwoHoursZone1* test = dynamic_cast<TwoHoursZone1*>(&pUnknown);

		if (test)
			return true;
		else
			return false;

	}

	/*
	 * Output a string representing this instance.
	 */
	string TwoHoursZone1::toString(){

		stringstream ss;

		ss << this->length << " pass for " << this->zones << ", costing $"
			<< Utility::floatToString(this->cost, 2) << endl;

		return ss.str();

	}

	/*
	 * Task C - C3.
	 */
	ostream& operator<<(ostream& stream, TwoHoursZone1& pass){

		stream << pass.toString();

		return stream;

	}

	/*
	 * Task C - C3. This does not validate user input.
	 */
	istream& operator>>(istream& stream, TwoHoursZone1& pass){

		cout << "Enter length: ";
		stream >> pass.length;

		cout << "Enter zones: ";
		stream >> pass.zones;

		cout << "Enter cost: ";
		stream >> pass.cost;

		return stream;

	}

	bool TwoHoursZone1::canAddJourney(Journey* journey){

		bool correctDay = true;
		bool correctTime = true;
		string diff = System::DateTime::subtractTime(journey->getDepartureTime(), journey->getArrivalTime());
		int hours = Utility::stringToInt(diff.substr(0, 2));
		int required = journey->getHighestZone();

		if (journeys.size() > 0){

			// calculate the time between first departure and last arrival
			// and see if that plus the new journey is longer than 2 hours

			string current = System::DateTime::subtractTime(
				journeys[0]->getDepartureTime(),
				//journeys[journeys.size() - 1]->getArrivalTime()
				journey->getArrivalTime()
			);
			string added = current;//System::DateTime::addTime(current, diff);
			//cout << "Current=" << current << " added=" << added << endl;
			hours = Utility::stringToInt(added.substr(0, 2));
			correctDay = journey->getDay().compare(journeys[0]->getDay()) == 0;
			correctTime = journeys[0]->getArrivalTime() <= journey->getDepartureTime();

		}

		return required < 2 && correctDay && correctTime && hours < 2;

	}


}
