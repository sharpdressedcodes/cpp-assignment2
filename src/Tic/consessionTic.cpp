
#include "consessionTic.h"

namespace Tic {

	float ConsessionTic::DEFAULT_DISCOUNT_RATE = 0.5;

	ConsessionTic::ConsessionTic(){
		this->discountRate = DEFAULT_DISCOUNT_RATE;
	}

	ConsessionTic::ConsessionTic(float discountRate){
		this->discountRate = discountRate;
	}

	ConsessionTic::~ConsessionTic(){

	}

	void ConsessionTic::setDiscountRate(float newValue){
		this->discountRate = newValue;
	}

}
