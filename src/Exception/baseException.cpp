
#include "baseException.h"

namespace Exception {

BaseException::BaseException(){}

BaseException::~BaseException(){}

BaseException::BaseException(string message){
	this->message = message;
}

}
