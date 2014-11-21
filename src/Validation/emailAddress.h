
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
