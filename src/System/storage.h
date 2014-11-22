
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
