/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "emailAddress.h"

namespace Validation {

EmailAddress::EmailAddress(string email){
	this->email = email;
	//validate();
}

bool EmailAddress::operator ()(string email){

	this->email = email;
	return validate(email);

}

bool EmailAddress::validate(string obj){

	bool result = false;
	size_t at = email.find('@');
	size_t dot = email.find('.', at != string::npos ? at : 0);

	result = email.length() > 4;
	result &= at != string::npos;
	result &= dot != string::npos;
	result &= at < dot;
	result &= at != 0;
	result &= dot != email.length() - 1;

	return result;

}

}
