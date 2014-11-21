/*
 * journey.h
 *
 *  Created on: 09/11/2014
 *      Author: greg
 */

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
	//float length;
	string day;
	string departureTime;
	string arrivalTime;
	System::Station *fromStation;
	System::Station *toStation;

public:
	Journey();
	//Journey(float length);
	Journey(string day, string departureTime, string arrivalTime, System::Station *fromStation, System::Station *toStation);
	//float getLength() const;
	string getDay() const;
	string getDepartureTime() const;
	string getArrivalTime() const;
	System::Station *getFromStation() const;
	System::Station *getToStation() const;
	string toString() const;
	int getHighestZone()const;
	//void setLength(float newValue);
};

}

#endif /* JOURNEY_H_ */
