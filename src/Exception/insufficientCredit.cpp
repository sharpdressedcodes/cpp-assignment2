
#include "insufficientCredit.h"

namespace Exception {

	/*const char* InsuffcientCredit::what() const throw(){
		return "Insufficient credit to perform that transaction!";
	}*/

	InsufficientCredit::InsufficientCredit() : BaseException(string()) {}

	string InsufficientCredit::getMessage(){
		string s("Insufficient credit to perform that transaction!");
		return s;
	}

}

