/*
 * junior.h
 *
 *  Created on: 09/11/2014
 *      Author: greg
 */

#ifndef JUNIOR_H_
#define JUNIOR_H_

#include "baseUser.h"
#include "../Tic/juniorMyTic.h"

namespace User {

	class Junior : public BaseUser {
	public:
		Junior(string id, string name, string email, float credit);
		~Junior();
	};

}


#endif /* JUNIOR_H_ */
