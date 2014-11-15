
#include "juniorMyTic.h"

namespace Tic {

JuniorMyTic::JuniorMyTic() : ConsessionTic(){

}

JuniorMyTic::JuniorMyTic(float discountRate) : ConsessionTic(discountRate){

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
