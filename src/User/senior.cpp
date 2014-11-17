
#include "senior.h"

namespace User {

	Senior::Senior(string id, string name, string email, float credit)
		: BaseUser(id, name, email, credit){

		this->tic = new Tic::SeniorMyTic();

	}

	Senior::~Senior(){}

}

