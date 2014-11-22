
#ifndef WEEKLY_H_
#define WEEKLY_H_

#include "../System/dateTime.h"
#include "travelPass.h"

namespace Pass {

class Weekly : public TravelPass {
public:
	static const float DEFAULT_PRICE;
	static const string DEFAULT_LENGTH;
	static const string DEFAULT_ZONES;

	Weekly();
//		Weekly(const Weekly& zone);
	Weekly(float theCost);
	Weekly(string theLength, string theZones, float theCost);
	~Weekly();
	void input();   // Data input for a Weekly object
	void print();  // Data output for a Weekly object
	bool isTravelPass(TravelPass& pUnknown);
	string toString();

	friend ostream& operator<<(ostream& stream, Weekly& pass);
	friend istream& operator>>(istream& stream, Weekly& pass);
	bool canAddJourney(Journey* journey);
	string getEndDate();
};

}


#endif /* WEEKLY_H_ */
