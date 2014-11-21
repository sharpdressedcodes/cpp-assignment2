
#include "emailAddress.h"

namespace Validation {

EmailAddress::EmailAddress(string email){
	this->email = email;
	//validate();
}

bool EmailAddress::operator ()(string email){

	this->email = email;
	return validate();

}

bool EmailAddress::validate(){

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
