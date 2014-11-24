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
	int index;
	T data;
	string tag;
	bool autoDelete;

public:
	Storage(int index, T data, string tag = string(), bool autoDelete = false){

		this->index = index;
		this->data = data;
		this->tag = tag;
		this->autoDelete = autoDelete;

	}

	~Storage(){

		if (this->autoDelete)
			delete this->data;

	}

	int getIndex() const {
		return index;
	}

	T getData() const {
		return data;
	}

	string getTag() const {
		return tag;
	}

	void setIndex(int newValue){
		index = newValue;
	}

	void setData(T newValue) {
		data = newValue;
	}

	void setTag(string newValue){
		tag = newValue;
	}

};

}

#endif /* STORAGE_H_ */
