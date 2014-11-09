/*
 * invalidFileFormat.h
 *
 *  Created on: 09/11/2014
 *      Author: greg
 */

#ifndef INVALIDFILEFORMAT_H_
#define INVALIDFILEFORMAT_H_

#include "baseException.h"
#include <sstream>

using std::stringstream;

namespace Exception {

	class InvalidFileFormat : public BaseException {
	private:
		char *filename;
	public:
		InvalidFileFormat(const char *filename);
		const char* what() const throw();
	};

}


#endif /* INVALIDFILEFORMAT_H_ */
