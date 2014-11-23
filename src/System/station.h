/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef STATION_H_
#define STATION_H_

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
		int zone;
		unsigned int startedJourneys;
		unsigned int finishedJourneys;

	public:
		static const int UNASSIGNED_ZONE;
		Station();
		Station(const string& name, const int& zone);
		~Station();
		string getName() const;
		int getZone() const;
		unsigned int getStartedJourneys() const;
		unsigned int getFinishedJourneys() const;
		void setName(string newValue);
		void setZone(const int& newValue);
		void incrementStartedJourneys();
		void incrementFinishedJourneys();

		friend ostream& operator<<(ostream& stream, Station& station);
		friend istream& operator>>(istream& stream, Station& station);
	};

}

#endif /* STATION_H_ */
