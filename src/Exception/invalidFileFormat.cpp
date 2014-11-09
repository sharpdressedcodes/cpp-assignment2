/*
 * invalidFileFormat.cpp
 *
 *  Created on: 09/11/2014
 *      Author: greg
 */


#include "invalidFileFormat.h"

namespace Exception {

	InvalidFileFormat::InvalidFileFormat(const char *filename){
		this->filename = (char*)filename;
	}

	const char* InvalidFileFormat::what() const throw(){
		stringstream ss;
		ss << "Invalid format when reading " << this->filename;
		return ss.str().c_str();
	}

}

