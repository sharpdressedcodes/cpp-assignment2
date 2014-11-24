/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef BASEUI_H_
#define BASEUI_H_

#include "../System/myTicSystem.h"
#include <string>

namespace Ui {

	class BaseUI {
protected:
	System::MyTicSystem* m_system;

public:
	BaseUI();
	virtual ~BaseUI();
	virtual System::MyTicSystem* getSystem();
	virtual bool run(int argc, char *argv[]) = 0;
	virtual bool buyJourney() = 0;
	virtual User::BaseUser* rechargeTic() = 0;
	virtual void showCredit(User::BaseUser* user = NULL) = 0;
	virtual void printReports() = 0;
	virtual bool updatePricing() = 0;
	virtual void showStatistics() = 0;
	virtual bool addUser() = 0;
};

}

#endif /* BASEUI_H_ */
