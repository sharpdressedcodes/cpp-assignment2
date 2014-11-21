
#include "insuffcientCredit.h"

namespace Exception {

	/*const char* InsuffcientCredit::what() const throw(){
		return "Insufficient credit to perform that transaction!";
	}*/

	InsuffcientCredit::InsuffcientCredit() : BaseException(string()) {}

	string InsuffcientCredit::getMessage(){
		string s("Insufficient credit to perform that transaction!");
		return s;
	}

}

