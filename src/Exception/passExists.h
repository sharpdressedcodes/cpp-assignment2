
#ifndef PASSEXISTS_H_
#define PASSEXISTS_H_

#include "baseException.h"

namespace Exception {

	class PassExists : public BaseException {
	public:
		//const char* what() const throw();
		PassExists();
		string getMessage();
	};

}

#endif /* PASSEXISTS_H_ */
