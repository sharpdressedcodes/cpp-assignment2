/*
 * invalidData.h
 *
 *  Created on: 08/11/2014
 *      Author: greg
 */

#ifndef INVALIDDATA_H_
#define INVALIDDATA_H_

#include "baseException.h"

namespace Exception {

	class InvalidData : public BaseException {
	private:
		//string
	public:
		const char* what() const throw();
	};

}


#endif /* INVALIDDATA_H_ */
