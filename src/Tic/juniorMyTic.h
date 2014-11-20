
#ifndef JUNIORMYTIC_H_
#define JUNIORMYTIC_H_

#include "consessionTic.h"

namespace Tic {

	class JuniorMyTic : public ConsessionTic {

	public:
		JuniorMyTic();
		JuniorMyTic(float credit, float discountRate = ConsessionTic::DEFAULT_DISCOUNT_RATE, vector<string> freeDays = vector<string>());
		~JuniorMyTic();
		float getDiscountRate() const;

		string toString() const;
	};

}

#endif /* JUNIORMYTIC_H_ */
