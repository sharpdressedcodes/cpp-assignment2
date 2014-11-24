/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef CONSOLEUI_H_
#define CONSOLEUI_H_

#include "../Tic/myTic.h"
#include "../Pass/travelPass.h"
#include "../Pass/twoHoursZone1.h"
#include "../Pass/twoHoursZone1And2.h"
#include "../Pass/allDayZone1.h"
#include "../Pass/allDayZone1And2.h"
#include "../System/myTicSystem.h"
#include "../System/dateTime.h"
#include "../System/utility.h"
#include "../Validation/emailAddress.h"
#include "baseUI.h"
//#include <string>
#include <vector>

using namespace std;
using std::vector;
using namespace Pass;
using Pass::AllDayZone1;
using System::Utility;

namespace Ui {

/*
 * User Interface (UI).
 * This class is implemented as a Singleton because it makes
 * sense to have one class controlling the UI.
 */
class Console : public BaseUI {

private:

	static string MENU_STRING_BUY;
	static string MENU_STRING_CHARGE;
	static string MENU_STRING_SHOW_CREDIT;
	static string MENU_STRING_PRINT;
	static string MENU_STRING_UPDATE;
	static string MENU_STRING_SHOW_STATS;
	static string MENU_STRING_ADD;
	static string MENU_STRING_QUIT;

	static string MESSAGE_MENU_OPTION;
	static string MESSAGE_MENU_SELECTION;
	static string MESSAGE_MENU_INVALID_SELECTION;
	static string MESSAGE_MENU_GOODBYE;
	static string MESSAGE_MENU_YOUR_SELECTION;

public:

	enum MENU_OPTIONS {
		MENU_INDEX_BUY = 1,
		MENU_INDEX_CHARGE,
		MENU_INDEX_SHOW_CREDIT,
		MENU_INDEX_PRINT,
		MENU_INDEX_UPDATE,
		MENU_INDEX_SHOW_STATS,
		MENU_INDEX_ADD,
		MENU_INDEX_QUIT,
		MAX_MENU
	};

	enum ARG_ORDER {
		App,
		LoadStations,
		LoadUsersAndZones,
		SaveUsersAndZones,
		MAX_ARG_ORDER
	};

	/*
	 * Since there is 1 main menu and 2 sub menus and they don't differ much
	 * it makes sense to use a template. For now, this swaps int and char.
	 */
	template <typename T>
	struct menuOptions {
		T index;
		unsigned int subIndex; // only used in subMenus
		string text;
		bool isQuit;
	};

	typedef Console::menuOptions<int>* mainMenuOption;
	typedef Console::menuOptions<char>* subMenuOption;
	typedef vector<mainMenuOption> mainMenu;
	typedef vector<subMenuOption> subMenu;

	Console();
	~Console();
	bool run(int argc, char *argv[]);
	bool buyJourney();
	User::BaseUser* rechargeTic();
	void showCredit(User::BaseUser* user = NULL);
	void printReports();
	bool updatePricing();
	void showStatistics();
	bool addUser();

private:
	mainMenu m_options;

	void loadMenu();
	void deleteMenu();
	User::BaseUser* getUserFromConsole();
	System::Station* getStationFromConsole(string prefix = string());
	Pass::TravelPass* getPassFromConsole(string suffix = string());
	string getDateFromConsole(string prefix = string());
	string getTimeFromConsole(string prefix = string());
	bool validateData(const string& str);
};

}

#endif /* CONSOLEUI_H_ */
