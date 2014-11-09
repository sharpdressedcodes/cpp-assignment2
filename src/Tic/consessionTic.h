
#ifndef CONSESSIONTIC_H_
#define CONSESSIONTIC_H_

#include "myTic.h"

namespace Tic {

	class ConsessionTic : public MyTic {
	protected:
		static float defaultDiscountRate;
		float discountRate;
	public:
		virtual ~ConsessionTic();
		virtual float getDiscountRate() = 0;
		void setDiscountRate(float newValue);
	};

}


#endif /* CONSESSIONTIC_H_ */
