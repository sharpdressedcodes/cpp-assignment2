
#ifndef ADULT_H_
#define ADULT_H_

#include "baseUser.h"
#include "../Tic/fullMyTic.h"

namespace User {

	class Adult : public BaseUser {
	public:
		Adult(string id, string name, string email, float credit);
		~Adult();
	};

}


#endif /* ADULT_H_ */
