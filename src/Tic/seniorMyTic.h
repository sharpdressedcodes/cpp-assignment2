
#ifndef SENIORMYTIC_H_
#define SENIORMYTIC_H_

#include "consessionTic.h"

namespace Tic {

	class SeniorMyTic : public ConsessionTic {

	public:
		SeniorMyTic();
		SeniorMyTic(float discountRate);
		~SeniorMyTic();
		float getDiscountRate() const;

		string toString() const;

	};

}

#endif /* SENIORMYTIC_H_ */
