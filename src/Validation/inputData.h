
#ifndef INPUTDATA_H_
#define INPUTDATA_H_

#include "baseValidator.h"
#include <string>

using std::string;

namespace Validation {

class InputData : public BaseValidator<string> {
private:
	string delim;
public:
	InputData(string delim);
	bool operator() (string data);
	bool validate(string data);
};

}

#endif /* INPUTDATA_H_ */
