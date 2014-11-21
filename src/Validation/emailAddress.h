
#ifndef EMAILADDRESS_H_
#define EMAILADDRESS_H_

#include <string>

using std::string;

namespace Validation {

class EmailAddress {
private:
	string email;
	bool validate();
public:
	EmailAddress(string email = string());
	bool operator() (string email);

};

}

#endif /* EMAILADDRESS_H_ */
