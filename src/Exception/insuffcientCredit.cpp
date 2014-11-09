
#include "insuffcientCredit.h"

namespace Exception {

/*InsuffcientCredit::InsuffcientCredit()
	: BaseException("Insufficient credit to perform that transaction!"){}

InsuffcientCredit::~InsuffcientCredit(){}*/

	const char* InsuffcientCredit::what() const throw(){
		return "Insufficient credit to perform that transaction!";
	}

}

