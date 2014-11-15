
#include "journey.h"

namespace Pass {

Journey::Journey(){
	this->length = 0;
}

Journey::Journey(float length){
	this->length = length;
}

float Journey::getLength() const {
	return this->length;
}

void Journey::setLength(float newValue) {
	this->length = newValue;
}

}
