/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef INVALIDFILEFORMAT_H_
#define INVALIDFILEFORMAT_H_

#include "baseException.h"
#include <sstream>

using std::stringstream;

namespace Exception {

	class InvalidFileFormat : public BaseException {
	private:
		/*
		 * filename is used to show which filename caused the error.
		 */
		string filename;

	public:
		InvalidFileFormat(string filename);
		string getMessage();

	};

}

#endif /* INVALIDFILEFORMAT_H_ */
