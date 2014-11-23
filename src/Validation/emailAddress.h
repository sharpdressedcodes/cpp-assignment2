/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef EMAILADDRESS_H_
#define EMAILADDRESS_H_

#include "baseValidator.h"
#include <string>

using std::string;

namespace Validation {

class EmailAddress : public BaseValidator<string> {
private:
	string email;
public:
	EmailAddress(string email = string());
	bool operator() (string email);
	bool validate(string obj);
};

}

#endif /* EMAILADDRESS_H_ */
