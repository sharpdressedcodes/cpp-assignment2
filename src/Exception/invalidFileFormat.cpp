
#include "invalidFileFormat.h"

namespace Exception {

//	InvalidFileFormat::InvalidFileFormat(const char *filename){
//		this->filename = (char*)filename;
//	}
//
//	const char* InvalidFileFormat::what() const throw(){
//		stringstream ss;
//		ss << "Invalid format when reading " << this->filename;
//		return ss.str().c_str();
//	}

InvalidFileFormat::InvalidFileFormat(string filename) : BaseException(string()){
	this->filename = filename;
}

string InvalidFileFormat::getMessage(){

	stringstream ss;
	ss << "Invalid format when reading " << this->filename;
	return ss.str();
}

}

