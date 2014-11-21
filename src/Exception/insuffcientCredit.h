
#ifndef INSUFFCIENTCREDIT_H_
#define INSUFFCIENTCREDIT_H_

#include "baseException.h"

namespace Exception {

	class InsuffcientCredit : public BaseException {
	public:
		//const char* what() const throw();
		InsuffcientCredit();
		string getMessage();
	};

}

#endif /* INSUFFCIENTCREDIT_H_ */
