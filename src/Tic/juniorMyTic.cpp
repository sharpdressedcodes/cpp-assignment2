
#include "juniorMyTic.h"

namespace Tic {

JuniorMyTic::JuniorMyTic() : ConsessionTic(){

}

JuniorMyTic::JuniorMyTic(float credit, float discountRate, vector<string> freeDays)
	: ConsessionTic(credit, discountRate, freeDays){

}

JuniorMyTic::~JuniorMyTic(){

}

float JuniorMyTic::getDiscountRate() const {
	return this->discountRate;
}

string JuniorMyTic::toString() const {
	return "";
}

}
