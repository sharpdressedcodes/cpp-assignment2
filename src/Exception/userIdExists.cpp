
#include "userIdExists.h"

namespace Exception {

	UserIdExists::UserIdExists(string toAppend) : BaseException(string()){
		this->toAppend = toAppend;
	}

//	const char* UserIdExists::what() const throw(){
//		string s("Sorry, that id is already in use.");
//		s.append(toAppend);
//		return s.c_str();
//	}

	string UserIdExists::getMessage(){
		stringstream ss;
		ss << "Sorry, that id is already in use." << toAppend;
		return ss.str();
	}

}
