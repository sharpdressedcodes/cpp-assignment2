
#ifndef SENIORMYTIC_H_
#define SENIORMYTIC_H_

#include "consessionTic.h"
#include "../System/dateTime.h"

namespace Tic {

	class SeniorMyTic : public ConsessionTic {

	public:
		SeniorMyTic();
		SeniorMyTic(float credit, float discountRate = ConsessionTic::DEFAULT_DISCOUNT_RATE, vector<string> freeDays = vector<string>());
		~SeniorMyTic();
		float getDiscountRate() const;
		string toString() const;
	};

}

#endif /* SENIORMYTIC_H_ */
