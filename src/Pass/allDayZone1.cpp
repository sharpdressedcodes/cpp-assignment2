/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "allDayZone1.h"

namespace Pass {

	const float AllDayZone1::DEFAULT_PRICE = 4.9;
	const string AllDayZone1::DEFAULT_LENGTH = "All Day";
	const string AllDayZone1::DEFAULT_ZONES = "Zone 1";

	AllDayZone1::AllDayZone1()
		: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, DEFAULT_PRICE) {}

//	AllDayZone1::AllDayZone1(const AllDayZone1& zone)
//		: TravelPass(zone.getLength(), zone.getZones(), zone.getCost()) {
//
//	}

	AllDayZone1::AllDayZone1(float theCost)
		: TravelPass(DEFAULT_LENGTH, DEFAULT_ZONES, theCost) {}

	AllDayZone1::AllDayZone1(string theLength, string theZones, float theCost)
		: TravelPass(theLength, theZones, theCost) {}

	AllDayZone1::~AllDayZone1(){}

	/*
	 * Shortcut for Task C. This does not validate user input.
	 */
	void AllDayZone1::input(){

		cin >> *this;

	}

	void AllDayZone1::print(){

		cout << this->toString();

	}

	/*
	 * I couldn't really see a use for this function. I think it should be
	 * static because if you have to call this method from an already created
	 * AlLDayZone1 instance, then you should already know what it is.
	 * Calling it statically makes more sense.
	 */
	bool AllDayZone1::isTravelPass(TravelPass& pUnknown){

		AllDayZone1* test = dynamic_cast<AllDayZone1*>(&pUnknown);

		if (test)
			return true;
		else
			return false;

	}

	/*
	 * Output a string representing this instance.
	 */
	string AllDayZone1::toString(){

		stringstream ss;

		ss << this->length << " pass for " << this->zones << ", costing $"
			<< Utility::floatToString(this->cost, 2) << endl;

		return ss.str();

	}

	/*
	 * Task C - C3.
	 */
	ostream& operator<<(ostream& stream, AllDayZone1& pass){

		stream << pass.toString();

		return stream;

	}

	/*
	 * Task C - C3. This does not validate user input.
	 */
	istream& operator>>(istream& stream, AllDayZone1& pass){

		cout << "Enter length: ";
		stream >> pass.length;

		cout << "Enter zones: ";
		stream >> pass.zones;

		cout << "Enter cost: ";
		stream >> pass.cost;

		return stream;

	}






	bool AllDayZone1::canAddJourney(Journey* journey){

		// TODO: implement canAddJourney
		return true;

	}







}
