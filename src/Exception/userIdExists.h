
#ifndef USERIDEXISTS_H_
#define USERIDEXISTS_H_

#include "baseException.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

namespace Exception {

	class UserIdExists : public BaseException {
	private:
		//char* toAppend;
		string toAppend;
	public:
		UserIdExists(string toAppend = string());
		//const char* what() const throw();
		string getMessage();
	};

}

#endif /* USERIDEXISTS_H_ */
