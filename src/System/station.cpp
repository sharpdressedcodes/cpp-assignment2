
#include "station.h"

namespace System {

const int Station::UNASSIGNED_ZONE = -1;

Station::Station(){

	this->name = "";
	this->zone = UNASSIGNED_ZONE;
	this->startedJourneys = 0;
	this->finishedJourneys = 0;

}

//Station::Station(string name, Pass::TravelPass* zone){
Station::Station(const string& name, const int& zone){

	this->name = name;
	this->zone = zone;
	this->startedJourneys = 0;
	this->finishedJourneys = 0;

}

string Station::getName() const {
	return this->name;
}

//Pass::TravelPass* Station::getZone() const {
int Station::getZone() const {
	return this->zone;
}

unsigned int Station::getStartedJourneys() const {
	return this->startedJourneys;
}

unsigned int Station::getFinishedJourneys() const {
	return this->finishedJourneys;
}

void Station::setName(string newValue) {
	this->name = newValue;
}

//void Station::setZone(Pass::TravelPass* newValue) {
void Station::setZone(const int& newValue) {
	this->zone = newValue;
}

void Station::incrementStartedJourneys(){
	this->startedJourneys++;
}

void Station::incrementFinishedJourneys(){
	this->finishedJourneys++;
}

ostream& operator<<(ostream& stream, Station& station){

	//stream << station.toString();

	return stream;

}

istream& operator>>(istream& stream, Station& station){

	//stringstream ss;
	//const string colon = ":";
	//string ela;

	//ss >> station.name >> ":";


	//stream >> station.name;// >> ":";// >> station.zone;// >> std::endl;
	//stream >> colon;
	//stream >> station.zone;
	//stream >> ela;
	//stream >> std::endl();

/*		cout << "Enter name: ";
	stream >> station.name;

	cout << "Enter zones: ";
	stream >> station.zones;

	cout << "Enter cost: ";
	stream >> station.cost;*/

	return stream;

}

}
