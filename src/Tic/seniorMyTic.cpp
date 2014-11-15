
#include "seniorMyTic.h"

namespace Tic {

SeniorMyTic::SeniorMyTic() : ConsessionTic (){}

SeniorMyTic::SeniorMyTic(float discountRate) : ConsessionTic (discountRate){}

SeniorMyTic::~SeniorMyTic(){}

float SeniorMyTic::getDiscountRate() const {
	return this->discountRate;
}

string SeniorMyTic::toString() const {
	return "";
}

}
