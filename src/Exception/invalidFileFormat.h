
#ifndef INVALIDFILEFORMAT_H_
#define INVALIDFILEFORMAT_H_

#include "baseException.h"
#include <sstream>

using std::stringstream;

namespace Exception {

	class InvalidFileFormat : public BaseException {
	private:
		//char *filename;
		string filename;
	public:
		//InvalidFileFormat(const char *filename);
		InvalidFileFormat(string filename);
		string getMessage();
		//const char* what() const throw();
	};

}


#endif /* INVALIDFILEFORMAT_H_ */
