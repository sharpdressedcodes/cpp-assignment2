#include "junior.h"

namespace User {

	Junior::Junior(string id, string name, string email, float credit)
		: BaseUser(id, name, email, credit){

		this->tic = new Tic::JuniorMyTic(credit);

	}

	Junior::~Junior(){}

}
