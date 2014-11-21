
#include "invalidData.h"

namespace Exception {

//const char* InvalidData::what() const throw(){
//	return "Invalid data was entered!";
//}

string InvalidData::getMessage(){
	string s("Invalid data was entered!");
	return s;
}

}


