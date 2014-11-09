
#ifndef ADULT_H_
#define ADULT_H_

#include "baseUser.h"

namespace User {

	class Adult : public BaseUser {
	public:
		Adult(string id, string name, string email);
	};

}


#endif /* ADULT_H_ */
