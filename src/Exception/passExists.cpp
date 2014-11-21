
#include "passExists.h"

namespace Exception {

//	const char* PassExists::what() const throw(){
//		return "Sorry, that Travel Pass is already in use.";
//	}

PassExists::PassExists() : BaseException(string()) {}

string PassExists::getMessage() {
	string s("Sorry, that Travel Pass is already in use.");
	return s;
}

}
