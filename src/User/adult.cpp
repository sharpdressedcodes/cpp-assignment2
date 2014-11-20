
#include "adult.h"

namespace User {

	Adult::Adult(string id, string name, string email, float credit)
		: BaseUser(id, name, email, credit){

		this->tic = new Tic::FullMyTic(credit);

	}

	Adult::~Adult(){}

}

