
#ifndef INSUFFCIENTCREDIT_H_
#define INSUFFCIENTCREDIT_H_

#include "baseException.h"

namespace Exception {

	class InsuffcientCredit : public BaseException {

	public:
		//InsuffcientCredit();
		//~InsuffcientCredit();
		const char* what() const throw();
	};

}


#endif /* INSUFFCIENTCREDIT_H_ */
