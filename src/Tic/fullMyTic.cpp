#include "fullMyTic.h"

namespace Tic {

FullMyTic::FullMyTic(){}

FullMyTic::FullMyTic(float credit, vector<string> freeDays) : MyTic() {
	this->credit = credit;
	this->freeDays = freeDays;
}

FullMyTic::~FullMyTic(){}

float FullMyTic::getRealAmount(const string& day, float amount){

	return isFreeDay(day) ? 0 : amount;

}

string FullMyTic::toString() const {
	// TODO: FullMyTic::toString()
	return "";
}

}
