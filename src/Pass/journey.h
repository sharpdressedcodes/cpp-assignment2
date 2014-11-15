/*
 * journey.h
 *
 *  Created on: 09/11/2014
 *      Author: greg
 */

#ifndef JOURNEY_H_
#define JOURNEY_H_

namespace Pass {

class Journey {

private:
	float length;

public:
	Journey();
	Journey(float length);
	float getLength() const;
	void setLength(float newValue);
};

}

#endif /* JOURNEY_H_ */
