
#ifndef INVALIDDATA_H_
#define INVALIDDATA_H_

#include "baseException.h"

namespace Exception {

	class InvalidData : public BaseException {
	public:
		//const char* what() const throw();
		string getMessage();
	};

}


#endif /* INVALIDDATA_H_ */
