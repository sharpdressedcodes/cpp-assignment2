/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "weekly.h"

namespace Pass {

	const float Weekly::DEFAULT_PRICE = 15;
	const string Weekly::DEFAULT_LENGTH = "Weekly";
	const string Weekly::DEFAULT_ZONES = "Zones 1 and 2";

	Weekly::Weekly()
		: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, DEFAULT_PRICE) {}

	Weekly::Weekly(float theCost)
		: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, theCost) {}

	Weekly::Weekly(string theLength, string theZones, float theCost)
		: TravelPass(theLength, theZones, theCost) {}

	Weekly::~Weekly(){}

	/*
	 * Shortcut for Task C. This does not validate user input.
	 */
	void Weekly::input(){

		cin >> *this;

	}

	void Weekly::print(){

		cout << this->toString();

	}

	/*
	 * I couldn't really see a use for this function. I think it should be
	 * static because if you have to call this method from an already created
	 * AlLDayZone1 instance, then you should already know what it is.
	 * Calling it statically makes more sense.
	 */
	bool Weekly::isTravelPass(TravelPass& pUnknown){

		Weekly* test = dynamic_cast<Weekly*>(&pUnknown);

		if (test)
			return true;
		else
			return false;

	}

	/*
	 * Output a string representing this instance.
	 */
	string Weekly::toString(){

		stringstream ss;

		ss << this->length << " pass for " << this->zones << ", costing $"
			<< Utility::floatToString(this->cost, 2) << endl;

		return ss.str();

	}

	/*
	 * Task C - C3.
	 */
	ostream& operator<<(ostream& stream, Weekly& pass){

		stream << pass.toString();

		return stream;

	}

	/*
	 * Task C - C3. This does not validate user input.
	 */
	istream& operator>>(istream& stream, Weekly& pass){

		cout << "Enter length: ";
		stream >> pass.length;

		cout << "Enter zones: ";
		stream >> pass.zones;

		cout << "Enter cost: ";
		stream >> pass.cost;

		return stream;

	}

	bool Weekly::canAddJourney(Journey* journey){

		// is the end date of this pass >= journey end date?

		int i = System::DateTime::compareDates(this->getEndDate(),
				journey->getArrivalDate());

		return i >= 0;

	}

	string Weekly::getEndDate(){
		return System::DateTime::getEndOfWeek(startDate);
	}

}
