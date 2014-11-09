/*
 * invalidData.cpp
 *
 *  Created on: 08/11/2014
 *      Author: greg
 */

#include "invalidData.h"

namespace Exception {

const char* InvalidData::what() const throw(){
	return "Invalid data was entered!";
}

}


