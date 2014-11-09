/*
 * userIdExists.h
 *
 *  Created on: 09/11/2014
 *      Author: greg
 */

#ifndef USERIDEXISTS_H_
#define USERIDEXISTS_H_

#include "baseException.h"

namespace Exception {

	class UserIdExists : public BaseException {
	public:
		const char* what() const throw();
	};

}


#endif /* USERIDEXISTS_H_ */
