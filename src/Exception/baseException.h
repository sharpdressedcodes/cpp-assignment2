/*
 * baseException.h
 *
 *  Created on: 08/11/2014
 *      Author: greg
 */

#ifndef BASEEXCEPTION_H_
#define BASEEXCEPTION_H_

//#include <string>
#include <exception>

//using std::string;
using std::exception;

namespace Exception {

	class BaseException : public exception {
	//protected:
		//string message;

	public:
		//BaseException(string errorMessage);
		//virtual ~BaseException() = 0;
		//string getMessage() const throw();
		virtual const char* what() const throw() = 0;
	};
}


#endif /* BASEEXCEPTION_H_ */
