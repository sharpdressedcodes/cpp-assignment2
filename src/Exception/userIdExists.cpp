/*
 * userIdExists.cpp
 *
 *  Created on: 09/11/2014
 *      Author: greg
 */


#include "userIdExists.h"

namespace Exception {

	const char* UserIdExists::what() const throw(){
		return "Sorry, that id is already in use.";
	}

}

