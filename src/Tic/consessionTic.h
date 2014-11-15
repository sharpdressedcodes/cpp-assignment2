
#ifndef CONSESSIONTIC_H_
#define CONSESSIONTIC_H_

#include "myTic.h"

namespace Tic {

	class ConsessionTic : public MyTic {
	protected:
		static float DEFAULT_DISCOUNT_RATE;
		float discountRate;
	public:
		ConsessionTic();
		ConsessionTic(float discountRate);
		virtual ~ConsessionTic();
		virtual float getDiscountRate() const = 0;
		void setDiscountRate(float newValue);

		virtual string toString() const = 0;
	};

}


#endif /* CONSESSIONTIC_H_ */
