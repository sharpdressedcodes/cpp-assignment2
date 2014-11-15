
#ifndef JUNIORMYTIC_H_
#define JUNIORMYTIC_H_

#include "consessionTic.h"

namespace Tic {

	class JuniorMyTic : public ConsessionTic {

	public:
		JuniorMyTic();
		JuniorMyTic(float discountRate);
		~JuniorMyTic();
		float getDiscountRate() const;

		string toString() const;
	};

}

#endif /* JUNIORMYTIC_H_ */
