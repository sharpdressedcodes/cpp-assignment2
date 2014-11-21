
#include "inputData.h"

namespace Validation {

InputData::InputData(string delim){
	this->delim = delim;
}

bool InputData::operator ()(string data) {

	return validate(data);

}

bool InputData::validate(string data){

	return data.find(delim) == string::npos;

}

}
