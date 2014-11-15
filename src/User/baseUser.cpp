/*
 * baseUser.cpp
 *
 *  Created on: 09/11/2014
 *      Author: greg
 */


#include "baseUser.h"

namespace User {

	BaseUser::BaseUser(string id, string name, string email, float credit){

		this->id = id;
		this->name = name;
		this->email = email;
		this->credit = credit;
		this->tic = NULL;

	}

	BaseUser::~BaseUser(){}

	string BaseUser::getId() const {
		return this->id;
	}

	string BaseUser::getName() const {
		return this->name;
	}

	string BaseUser::getEmail() const {
		return this->email;
	}

	float BaseUser::getCredit() const {
		return this->credit;
	}

	Tic::MyTic* BaseUser::getTic() const {
		return this->tic;
	}

	void BaseUser::setId(string newValue){
		this->id = newValue;
	}

	void BaseUser::setName(string newValue){
		this->name = newValue;
	}

	void BaseUser::setEmail(string newValue){
		this->email = newValue;
	}

	void BaseUser::setCredit(float newValue){
		this->credit = newValue;
	}

	void BaseUser::setTic(Tic::MyTic* newValue){
		this->tic = newValue;
	}

	bool BaseUser::addCredit(float newValue){

		// TODO: throw Exception::InsufficientCredit
		if (this->credit + newValue < 0)
			return false;

		this->credit += newValue;

		return true;

	}

}

