
#ifndef BASEEXCEPTION_H_
#define BASEEXCEPTION_H_

//#include <exception>

//using std::exception;

#include <string>

using std::string;

namespace Exception {

	class BaseException /*: public exception*/ {
	protected:
		string message;
	public:
		//virtual const char* what() const throw() = 0;
		BaseException();
		BaseException(string message);
		virtual ~BaseException();
		virtual string getMessage() = 0;

	};
}

#endif /* BASEEXCEPTION_H_ */
