/*
 * baseUser.h
 *
 *  Created on: 09/11/2014
 *      Author: greg
 */

#ifndef BASEUSER_H_
#define BASEUSER_H_

#include <string>

using std::string;

namespace User {

	/*enum UserType {
		Adult,
		Junior,
		Senior
	};*/

	class BaseUser {

	public:
		enum UserType {
			Adult,
			Junior,
			Senior
		};
		BaseUser(string id, string name, string email, UserType type);
		string getId();
		string getName();
		BaseUser::UserType getType();
		string getEmail();
		void setId(string newValue);
		void setName(string newValue);
		void setEmail(string newValue);
		void setType(UserType newValue);

	protected:
		string id;
		string name;
		string email;
		BaseUser::UserType type;
	};

}

#endif /* BASEUSER_H_ */
