
#ifndef FULLMYTIC_H_
#define FULLMYTIC_H_

#include "myTic.h"

namespace Tic {

	class FullMyTic : public MyTic {
	public:
		FullMyTic();
		FullMyTic(float credit, vector<string> freeDays = vector<string>());
		~FullMyTic();
		virtual float getRealAmount(const string& day, const float amount);

		string toString() const;
	};

}


#endif /* FULLMYTIC_H_ */
