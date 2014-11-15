
#ifndef SENIOR_H_
#define SENIOR_H_

#include "baseUser.h"
#include "../Tic/seniorMyTic.h"

namespace User {

	class Senior : public BaseUser {
	public:
		Senior(string id, string name, string email, float credit);
	};

}


#endif /* SENIOR_H_ */
