/*
 * baseUser.cpp
 *
 *  Created on: 09/11/2014
 *      Author: greg
 */


#include "baseUser.h"

namespace User {

	BaseUser::BaseUser(string id, string name, string email, UserType type){

		this->id = id;
		this->name = name;
		this->email = email;
		this->type = type;

	}

	string BaseUser::getId(){
		return this->id;
	}

	string BaseUser::getName(){
		return this->name;
	}

	BaseUser::UserType BaseUser::getType(){
		return this->type;
	}

	string BaseUser::getEmail(){
		return this->email;
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

	void BaseUser::setType(BaseUser::UserType newValue){
		this->type = newValue;
	}

}

