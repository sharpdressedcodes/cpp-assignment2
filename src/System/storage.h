/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef STORAGE_H_
#define STORAGE_H_

namespace System {

template <class T>
class Storage {
protected:
	T data;
public:
	Storage(){}
	~Storage(){}

	T getData() const {
		return data;
	}
	void setData(T newValue) {
		data = newValue;
	}

};

}

#endif /* STORAGE_H_ */
