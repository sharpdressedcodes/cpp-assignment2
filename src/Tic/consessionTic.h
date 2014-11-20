
#ifndef CONSESSIONTIC_H_
#define CONSESSIONTIC_H_

#include "myTic.h"

namespace Tic {

	class ConsessionTic : public MyTic {
	protected:
		static const float DEFAULT_DISCOUNT_RATE;
		float discountRate;

	public:
		ConsessionTic();
		ConsessionTic(float credit, float discountRate = ConsessionTic::DEFAULT_DISCOUNT_RATE, vector<string> freeDays = vector<string>());
		virtual ~ConsessionTic();
		virtual float getRealAmount(const string& day, const float amount);
		virtual float getDiscountRate() const = 0;
		virtual void setDiscountRate(float newValue);
		virtual string toString() const = 0;
	};

}


#endif /* CONSESSIONTIC_H_ */
