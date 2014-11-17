/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "twoHoursZone1And2.h"

namespace Pass {

	const float TwoHoursZone1And2::DEFAULT_PRICE = 3.5;
	const string TwoHoursZone1And2::DEFAULT_LENGTH = "2 Hours";
	const string TwoHoursZone1And2::DEFAULT_ZONES = "Zones 1 and 2";

	TwoHoursZone1And2::TwoHoursZone1And2()
		: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, DEFAULT_PRICE) {}

	TwoHoursZone1And2::TwoHoursZone1And2(float theCost)
		: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, theCost) {}

	TwoHoursZone1And2::TwoHoursZone1And2(string theLength, string theZones, float theCost)
		: TravelPass(theLength, theZones, theCost) {}

	TwoHoursZone1And2::~TwoHoursZone1And2(){}

	/*
	 * Shortcut for Task C. This does not validate user input.
	 */
	void TwoHoursZone1And2::input(){

		cin >> *this;

	}

	void TwoHoursZone1And2::print(){

		cout << this->toString();

	}

	/*
	 * I couldn't really see a use for this function. I think it should be
	 * static because if you have to call this method from an already created
	 * TwoHoursZone1And2 instance, then you should already know what it is.
	 * Calling it statically makes more sense.
	 */
	bool TwoHoursZone1And2::isTravelPass(TravelPass& pUnknown){

		TwoHoursZone1And2* test = dynamic_cast<TwoHoursZone1And2*>(&pUnknown);

		if (test)
			return true;
		else
			return false;

	}

	/*
	 * Output a string representing this instance.
	 */
	string TwoHoursZone1And2::toString(){

		stringstream ss;

		ss << this->length << " pass for " << this->zones << ", costing $"
			<< Utility::floatToString(this->cost, 2) << endl;

		return ss.str();

	}

	/*
	 * Task C - C3.
	 */
	ostream& operator<<(ostream& stream, TwoHoursZone1And2& pass){

		stream << pass.toString();

		return stream;

	}

	/*
	 * Task C - C3. This does not validate user input.
	 */
	istream& operator>>(istream& stream, TwoHoursZone1And2& pass){

		cout << "Enter length: ";
		stream >> pass.length;

		cout << "Enter zones: ";
		stream >> pass.zones;

		cout << "Enter cost: ";
		stream >> pass.cost;

		return stream;

	}


	bool TwoHoursZone1And2::canAddJourney(Journey* journey){

		// TODO: implement canAddJourney
		return true;

	}

}
