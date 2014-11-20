
#include "seniorMyTic.h"

namespace Tic {

SeniorMyTic::SeniorMyTic() : ConsessionTic (){}

SeniorMyTic::SeniorMyTic(float credit, float discountRate, vector<string> freeDays)
	: ConsessionTic (credit, discountRate, freeDays){

	vector<string> days;

	days.push_back(System::DateTime::DAYS[System::Sunday]);
	this->setFreeDays(days);

}

SeniorMyTic::~SeniorMyTic(){}

float SeniorMyTic::getDiscountRate() const {
	return this->discountRate;
}

string SeniorMyTic::toString() const {
	return "";
}

}
