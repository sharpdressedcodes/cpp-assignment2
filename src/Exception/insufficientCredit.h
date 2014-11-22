
#ifndef INSUFFCIENTCREDIT_H_
#define INSUFFCIENTCREDIT_H_

#include "baseException.h"

namespace Exception {

	class InsufficientCredit : public BaseException {
	public:
		//const char* what() const throw();
		InsufficientCredit();
		string getMessage();
	};

}

#endif /* INSUFFCIENTCREDIT_H_ */
