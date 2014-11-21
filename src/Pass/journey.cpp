
#include "journey.h"

namespace Pass {

/*Journey::Journey(){
	this->length = 0;
}

Journey::Journey(float length){
	this->length = length;
}

float Journey::getLength() const {
	return this->length;
}

void Journey::setLength(float newValue) {
	this->length = newValue;
}*/

Journey::Journey ()
	: day(string()), departureTime(string()), arrivalTime(string()), fromStation(NULL), toStation(NULL){}

Journey::Journey(string day, string departureTime, string arrivalTime, System::Station *fromStation, System::Station *toStation){

	this->day = day;
	this->departureTime = departureTime;
	this->arrivalTime = arrivalTime;
	this->fromStation = fromStation;
	this->toStation = toStation;

}

string Journey::getDay() const {
	return this->day;
}

string Journey::getDepartureTime() const {
	return this->departureTime;
}

string Journey::getArrivalTime() const {
	return this->arrivalTime;
}

System::Station *Journey::getFromStation() const {
	return this->fromStation;
}

System::Station *Journey::getToStation() const {
	return this->toStation;
}

string Journey::toString() const {

	stringstream ss;

	ss << fromStation->getName() << " to " << toStation->getName() << " at " << departureTime;

	return ss.str();

}

int Journey::getHighestZone() const{

	int result = 0;

	if (fromStation->getZone() > result)
		result = fromStation->getZone();

	if (toStation->getZone() > result)
		result = toStation->getZone();

	return result;

}

}
