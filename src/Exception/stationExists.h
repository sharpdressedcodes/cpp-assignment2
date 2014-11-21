
#ifndef STATIONEXISTS_H_
#define STATIONEXISTS_H_

#include "baseException.h"

namespace Exception {

	class StationExists : public BaseException {
	public:
		//const char* what() const throw();
		StationExists();
		string getMessage();
	};

}

#endif /* STATIONEXISTS_H_ */
