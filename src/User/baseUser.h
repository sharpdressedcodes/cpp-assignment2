/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef BASEUSER_H_
#define BASEUSER_H_

#include <string>
#include "../Tic/myTic.h"

using std::string;

namespace User {

    class BaseUser {

    public:

        static const unsigned int ID_LEN_MAX;
        static const unsigned int NAME_LEN_MAX;
        static const unsigned int EMAIL_LEN_MAX;

        BaseUser(string id, string name, string email, float credit);
        virtual ~BaseUser() = 0;
        virtual string getId() const;
        virtual string getName() const;
        virtual string getEmail() const;
        virtual Tic::MyTic* getTic() const;
        virtual void setId(string newValue);
        virtual void setName(string newValue);
        virtual void setEmail(string newValue);
        virtual void setTic(Tic::MyTic* newValue);

    protected:
        string id;
        string name;
        string email;
        float credit;
        Tic::MyTic* tic;
    };

}

#endif /* BASEUSER_H_ */
