
#ifndef BASEVALIDATOR_H_
#define BASEVALIDATOR_H_

namespace Validation {

template <class T>
class BaseValidator {
public:
	//typedef bool (T::*memberFunction)();
	virtual ~BaseValidator(){}
	virtual bool validate(T obj) = 0;
};

}

#endif /* BASEVALIDATOR_H_ */
