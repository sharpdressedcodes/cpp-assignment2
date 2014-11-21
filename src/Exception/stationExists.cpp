
#include "stationExists.h"

namespace Exception {

//	const char* StationExists::what() const throw(){
//		return "Sorry, that station is already in use.";
//	}

StationExists::StationExists() : BaseException(string()){}

string StationExists::getMessage() {
	string s("Sorry, that station is already in use.");
	return s;
}

}
