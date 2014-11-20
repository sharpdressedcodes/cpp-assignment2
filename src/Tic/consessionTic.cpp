
#include "consessionTic.h"

namespace Tic {

	const float ConsessionTic::DEFAULT_DISCOUNT_RATE = 0.5;

	ConsessionTic::ConsessionTic() : MyTic() {
		this->discountRate = DEFAULT_DISCOUNT_RATE;
	}

	ConsessionTic::ConsessionTic(float credit, float discountRate, vector<string> freeDays) : MyTic() {
		this->discountRate = discountRate;
		this->credit = credit;
		this->freeDays = freeDays;
	}

	ConsessionTic::~ConsessionTic(){}

	float ConsessionTic::getRealAmount(const string& day, float amount){

		return isFreeDay(day) ? 0 : amount - (this->discountRate * amount);

	}

	void ConsessionTic::setDiscountRate(float newValue){
		this->discountRate = newValue;
	}

}
