/*
 * station.h
 *
 *  Created on: 09/11/2014
 *      Author: greg
 */

#ifndef STATION_H_
#define STATION_H_

//#include "../Pass/travelPass.h"
#include <istream>
#include <ostream>
#include <strstream>
#include <string>

using std::string;
using namespace std;

namespace System {

	class Station {

	private:
		string name;
		//Pass::TravelPass* zone;
		int zone;
		unsigned int startedJourneys;
		unsigned int finishedJourneys;
	public:
		static const int UNASSIGNED_ZONE;
		Station();
		//Station(string name, Pass::TravelPass* zone);
		Station(const string& name, const int& zone);
		string getName() const;
		//Pass::TravelPass* getZone() const;
		int getZone() const;
		unsigned int getStartedJourneys() const;
		unsigned int getFinishedJourneys() const;
		void setName(string newValue);
		//void setZone(Pass::TravelPass* newValue);
		void setZone(const int& newValue);
		void incrementStartedJourneys();
		void incrementFinishedJourneys();

		friend ostream& operator<<(ostream& stream, Station& station);
		friend istream& operator>>(istream& stream, Station& station);
	};

}

#endif /* STATION_H_ */
