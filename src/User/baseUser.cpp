/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "baseUser.h"

namespace User {

    const unsigned int BaseUser::ID_LEN_MAX = 2;
    const unsigned int BaseUser::NAME_LEN_MAX = 100;
    const unsigned int BaseUser::EMAIL_LEN_MAX = 100;

    BaseUser::BaseUser(string id, string name, string email, float credit){

        this->id = id;
        this->name = name;
        this->email = email;
        this->credit = credit;
        this->tic = NULL;

    }

    BaseUser::~BaseUser(){
        delete this->tic;
    }

    string BaseUser::getId() const {
        return this->id;
    }

    string BaseUser::getName() const {
        return this->name;
    }

    string BaseUser::getEmail() const {
        return this->email;
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

    void BaseUser::setTic(Tic::MyTic* newValue){
        this->tic = newValue;
    }

}

