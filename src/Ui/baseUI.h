
#ifndef BASEUI_H_
#define BASEUI_H_

#include "../System/myTicSystem.h"
#include <string>

namespace Ui {

	class BaseUI {
protected:
	System::MyTicSystem m_system;

public:
	BaseUI();
	virtual ~BaseUI();
	System::MyTicSystem getSystem() const;
	virtual bool run(int argc, char *argv[]) = 0;
	virtual bool buyJourney(bool debug = false) = 0;
	virtual User::BaseUser* rechargeTic() = 0;
	virtual void showCredit(User::BaseUser* user = NULL) = 0;
	virtual void printReports() = 0;
	virtual bool updatePricing() = 0;
	virtual void showStatistics() = 0;
	virtual bool addUser() = 0;
};

}

#endif /* BASEUI_H_ */
