/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "uI.h"

UI *UI::m_instance = NULL;

string UI::MENU_STRING_QUIT = "Quit";
string UI::MENU_STRING_BUY = "Buy a travel pass";
string UI::MENU_STRING_CHARGE = "Charge my MyTic";
string UI::MENU_STRING_SHOW = "Show remaining credit";
string UI::MENU_STRING_PRINT = "Print purchases";
string UI::MENU_STRING_CANCEL = "Cancel";

string UI::CREDIT_PREFIX = "Your credit = $";
string UI::YOU_PURCHASED_PREFIX = "You purchased ";
string UI::PURCHASED_PREFIX = "Purchased ";
string UI::PURCHASES_PREFIX = "\nPurchases: ($";
string UI::PURCHASES_SUFFIX = ")\n";

string UI::MESSAGE_CANNOT_ADD_CREDIT = "You cannot add anymore credit!";
string UI::MESSAGE_ADD_CREDIT = "How much do you want to add: ";
string UI::MESSAGE_CREDIT_OVER = "Sorry, the maximum allowed credit is $";
string UI::MESSAGE_CREDIT_DIVISOR = "Sorry, you can only add multiples of $";
string UI::MESSAGE_NOT_ENOUGH_CREDIT =
		"Sorry, you don't have enough credit for that selection.";
string UI::MESSAGE_NO_PURCHASES = "No purchases found.\n\n";
string UI::MESSAGE_NO_CREDIT = "You don't have any credit!";
string UI::MESSAGE_MAX_PASSES =
		"You have reached the maximum number of Travel Passes";
string UI::MESSAGE_MENU_WELCOME = "Welcome to MyTic!";
string UI::MESSAGE_MENU_OPTION = "Choose an option:";
string UI::MESSAGE_MENU_SELECTION = "Please make a selection: ";
string UI::MESSAGE_MENU_INVALID_SELECTION =
		"Sorry, that is an invalid option!";
string UI::MESSAGE_MENU_GOODBYE = "Goodbye!";
string UI::MESSAGE_MENU_TIME_PERIOD = "\nWhat time period:";
string UI::MESSAGE_MENU_YOUR_SELECTION = "Your selection: ";
string UI::MESSAGE_MENU_ZONE = "\nWhich zone:";

UI *UI::instance(){

	//Only create 1 instance, then keep returning that each time.

	if (!m_instance)
		m_instance = new UI();

	return m_instance;

}

/*
 * Load the main menu variables into the struct.
 */
void UI::loadMenu(mainMenu& options){

	int i = 0;

	for (i = 0; i < MAX_MENU; i++)
		options.push_back(new UI::menuOptions<int>());

	i = 0;

	options[i]->isQuit = true;
	options[i]->index = MENU_INDEX_QUIT;
	options[i++]->text = MENU_STRING_QUIT;

	options[i]->index = MENU_INDEX_BUY;
	options[i++]->text = MENU_STRING_BUY;

	options[i]->index = MENU_INDEX_CHARGE;
	options[i++]->text = MENU_STRING_CHARGE;

	options[i]->index = MENU_INDEX_SHOW;
	options[i++]->text = MENU_STRING_SHOW;

	options[i]->index = MENU_INDEX_PRINT;
	options[i++]->text = MENU_STRING_PRINT;

}

/*
 * Load the time submenu variables into the struct.
 */
void UI::loadTimeMenu(subMenu& timeOptions){

	int i = 0;

	for (i = 0; i < MAX_MENU_TIME; i++)
		timeOptions.push_back(new UI::menuOptions<char>());

	i = 0;

	timeOptions[i]->index = MENU_INDEX_TIME_2HOURS;
	timeOptions[i]->subIndex = i;
	timeOptions[i++]->text = Pass::TwoHoursZone1::DEFAULT_LENGTH;

	timeOptions[i]->index = MENU_INDEX_TIME_DAY;
	timeOptions[i]->subIndex = i;
	timeOptions[i++]->text = Pass::AllDayZone1::DEFAULT_LENGTH;

	timeOptions[i]->isQuit = true;
	timeOptions[i]->index = MENU_INDEX_TIME_CANCEL;
	timeOptions[i]->subIndex = i;
	timeOptions[i++]->text = MENU_STRING_CANCEL;

}

/*
 * Load the zone submenu variables into the struct.
 */
void UI::loadZoneMenu(subMenu& zoneOptions){

	int i = 0;

	for (i = 0; i < MAX_MENU_ZONE; i++)
		zoneOptions.push_back(new UI::menuOptions<char>());

	i = 0;

	zoneOptions[i]->index = MENU_INDEX_ZONE_1;
	zoneOptions[i]->subIndex = i;
	zoneOptions[i++]->text = AllDayZone1::DEFAULT_ZONES;

	zoneOptions[i]->index = MENU_INDEX_ZONE_1AND2;
	zoneOptions[i]->subIndex = i;
	zoneOptions[i++]->text = AllDayZone1And2::DEFAULT_ZONES;

	zoneOptions[i]->isQuit = true;
	zoneOptions[i]->index = MENU_INDEX_ZONE_CANCEL;
	zoneOptions[i]->subIndex = i;
	zoneOptions[i++]->text = MENU_STRING_CANCEL;

}

/*
 * Remove the main menu structs from memory.
 */
void UI::deleteMenu(mainMenu& options){

	for (size_t i = 0; i < options.size(); i++)
		delete options[i];

	options.clear();

}

/*
 * Remove the time submenu structs from memory.
 */
void UI::deleteTimeMenu(subMenu& timeOptions){

	for (size_t i = 0; i < timeOptions.size(); i++)
		delete timeOptions[i];

	timeOptions.clear();

}

/*
 * Remove the zone submenu structs from memory.
 */
void UI::deleteZoneMenu(subMenu& zoneOptions){

	for (size_t i = 0; i < zoneOptions.size(); i++)
		delete zoneOptions[i];

	zoneOptions.clear();

}

void UI::showCredit(const Tic::MyTic& tic) {

	cout << CREDIT_PREFIX
		<< Utility::floatToString(tic.getCredit(), 2) << "\n\n";

}

/*
 * Attempt to add credit to the MyTic object.
 */
void UI::addCredit(Tic::MyTic& tic){

	bool chargeValid = false;
	int charge = 0;
	stringstream ss;

	ss << MESSAGE_CREDIT_OVER
		<< Utility::floatToString((float)tic.getLimit(), 2);

	while (!chargeValid){

		// Don't proceed if they have full credit.
		if (tic.getCredit() >= tic.getLimit()){
			cerr << MESSAGE_CANNOT_ADD_CREDIT << endl;
			break;
		}

		charge = Utility::getIntFromConsole(
				Tic::MyTic::AMOUNT_DIVISOR,
			tic.getLimit(),
			MESSAGE_ADD_CREDIT,
			ss.str(),
			false
		);

		// Will this blow their budget?
		if (tic.getCredit() + charge > tic.getLimit()){
			cerr << ss.str() << endl;

		// Test for divisor
		} else if (charge % Tic::MyTic::AMOUNT_DIVISOR != 0){
			cerr << MESSAGE_CREDIT_DIVISOR
				<< Utility::floatToString((float)Tic::MyTic::AMOUNT_DIVISOR, 2)
				<< endl;

		} else {
			chargeValid = true;
			tic.addCredit(charge);
		}

	}

}

/*
 * Attempt to buy a ticket. The user can press 'c' for Cancel at any time
 * throughout this process.
 */
bool UI::buyTicket(Tic::MyTic& tic, subMenu timeOptions, subMenu zoneOptions){

	bool result = false;
	subMenuOption timeOption = NULL;
	subMenuOption zoneOption = NULL;

	// Don't proceed if they are broke.
	if (tic.getCredit() == 0){
		cerr << MESSAGE_NO_CREDIT << endl;
		return false;
	}

	timeOption = enterTimeMenu(timeOptions);

	if (timeOption != NULL){
		zoneOption = enterZoneMenu(zoneOptions);

		if (zoneOption != NULL){

			// Assign a generic TravelPass pointer.
			TravelPass *pass = assignTravelPass(timeOption, zoneOption);
			if (pass != NULL){

				float cost = pass->getCost();

				// Make sure they have enough credit for this purchase.
				if (cost > tic.getCredit()){
					cerr << MESSAGE_NOT_ENOUGH_CREDIT << endl;
					delete pass;

				} else {

					// The MyTic::buyPass() method will check if the user
					// can buy any more passes.
					if (tic.buyPass(pass)){
						cout << YOU_PURCHASED_PREFIX;
						pass->print();
						showCredit(tic);

					// The user has reached the max number of passes allowed.
					} else {
						cerr << MESSAGE_MAX_PASSES << endl;
						delete pass;
					}

				}

			}

		}
	}

	return result;

}

/*
 * Iterates over the purchases vector and prints each purchase.
 */
void UI::printPurchases(Tic::MyTic& tic){

	vector<TravelPass*> purchases = tic.getPurchases();

	cout << PURCHASES_PREFIX
			<< Utility::floatToString(tic.getPurchaseTotal(), 2)
			<< PURCHASES_SUFFIX;

	if (purchases.size() > 0){
		for (vector<TravelPass*>::const_iterator it = purchases.begin();
				it != purchases.end(); ++it){
			cout << PURCHASED_PREFIX;
			(*it)->print();
		}
		cout << endl;
	} else {
		cout << MESSAGE_NO_PURCHASES;
	}

}

/*
 * Main Menu.
 * Present the user with a set of main options.
 */
void UI::enterMenu(Tic::MyTic& tic, mainMenu options,
		subMenu timeOptions, subMenu zoneOptions){

	bool hasQuit = false;

	cout << MESSAGE_MENU_WELCOME << endl;

	while (!hasQuit) {

		mainMenuOption quitOption = NULL;

		cout << MESSAGE_MENU_OPTION << endl;

		// Iterate over the main menu structs and display each option.
		for (mainMenu::iterator it = options.begin();
				it != options.end(); ++it){
			mainMenuOption option = (*it);
			// Always display the quit option last.
			if (!option->isQuit)
				cout << option->index << ". " << option->text << endl;
			else
				quitOption = option;
		}

		if (quitOption)
			cout << quitOption->index << ". " << quitOption->text << endl;

		int selection = Utility::getIntFromConsole(
			MENU_INDEX_QUIT,
			MAX_MENU - 1,
			MESSAGE_MENU_SELECTION,
			MESSAGE_MENU_INVALID_SELECTION,
			false
		);

		switch (selection){

		case MENU_INDEX_BUY:

			buyTicket(tic, timeOptions, zoneOptions);
			break;

		case MENU_INDEX_CHARGE:

			addCredit(tic);
			showCredit(tic);
			break;

		case MENU_INDEX_SHOW:

			showCredit(tic);
			break;

		case MENU_INDEX_PRINT:

			printPurchases(tic);
			break;

		case MENU_INDEX_QUIT:

			hasQuit = true;
			break;

		}

	}

	// Clean memory.
	tic.clearPurchases();
	cout << MESSAGE_MENU_GOODBYE << endl;

}

/*
 * Time Sub Menu.
 * Present the user with a set of sub options to select a ticket type
 * based on time.
 */
UI::subMenuOption UI::enterTimeMenu(subMenu timeOptions){

	bool hasQuit = false;

	while (!hasQuit){

		subMenuOption quitOption = NULL;

		cout << MESSAGE_MENU_TIME_PERIOD << endl;

		// Iterate over the sub menu structs and display each option.
		for (subMenu::iterator it = timeOptions.begin();
				it != timeOptions.end(); ++it){
			subMenuOption option = (*it);
			// Always display the quit option last.
			if (!option->isQuit)
				cout << option->index << ") " << option->text << endl;
			else
				quitOption = option;
		}

		if (quitOption)
			cout << quitOption->index << ") " << quitOption->text << endl;

		string selection;
		bool validSelection = true;

		do {
			validSelection = false;
			selection = Utility::getStringFromConsole(
				1,
				1,
				MESSAGE_MENU_YOUR_SELECTION,
				MESSAGE_MENU_INVALID_SELECTION,
				false
			);
			// Validate the selected option.
			if (!selection.empty())
				validSelection = validateTimeOption(selection[0], timeOptions);
			if (!validSelection)
				cerr << MESSAGE_MENU_INVALID_SELECTION << endl;
		} while (!validSelection);

		// Iterate over the sub menu structs to find which option was selected.
		for (subMenu::iterator it = timeOptions.begin();
				it != timeOptions.end(); ++it){

			subMenuOption option = (*it);

			if (selection[0] == option->index){

				if (option->index == MENU_INDEX_TIME_CANCEL){
					hasQuit = true;
					break;
				} else {
					return timeOptions[option->subIndex];
				}

			}

		}

	}

	return NULL;

}

/*
 * Zone Sub Menu.
 * Present the user with a set of sub options to select a ticket type
 * based on zone.
 */
UI::subMenuOption UI::enterZoneMenu(subMenu zoneOptions){

	bool hasQuit = false;

	while (!hasQuit){

		subMenuOption quitOption = NULL;

		cout << MESSAGE_MENU_ZONE << endl;

		// Iterate over the sub menu structs and display each option.
		for (subMenu::iterator it = zoneOptions.begin();
				it != zoneOptions.end(); ++it){
			subMenuOption option = (*it);
			// Always display the quit option last.
			if (!option->isQuit)
				cout << option->index << ") " << option->text << endl;
			else
				quitOption = option;
		}

		if (quitOption)
			cout << quitOption->index << ") " << quitOption->text << endl;

		string selection;
		bool validSelection = true;

		do {
			validSelection = false;
			selection = Utility::getStringFromConsole(
				1,
				1,
				MESSAGE_MENU_YOUR_SELECTION,
				MESSAGE_MENU_INVALID_SELECTION,
				false
			);
			// Validate the selected option.
			if (!selection.empty())
				validSelection = validateZoneOption(selection[0], zoneOptions);
			if (!validSelection)
				cerr << MESSAGE_MENU_INVALID_SELECTION << endl;
		} while (!validSelection);

		// Iterate over the sub menu structs to find which option was selected.
		for (subMenu::iterator it = zoneOptions.begin();
				it != zoneOptions.end(); ++it){

			subMenuOption option = (*it);

			if (selection[0] == option->index){

				if (option->index == MENU_INDEX_ZONE_CANCEL){
					hasQuit = true;
					break;
				} else {
					return zoneOptions[option->subIndex];
				}

			}

		}

	}

	return NULL;

}

/*
 * Validates the time sub menu option.
 */
bool UI::validateTimeOption(const char option, subMenu timeOptions){

	bool result = false;

	for (subMenu::iterator it = timeOptions.begin();
			it != timeOptions.end(); ++it){
		if ((*it)->index == option){
			result = true;
			break;
		}
	}

	return result;

}

/*
 * Validates the zone sub menu option.
 */
bool UI::validateZoneOption(const char option, subMenu zoneOptions){

	bool result = false;

	for (subMenu::iterator it = zoneOptions.begin();
			it != zoneOptions.end(); ++it){
		if ((*it)->index == option){
			result = true;
			break;
		}
	}

	return result;

}

/*
 * Assigns a generic TravelPass pointer based on time and zone.
 */
Pass::TravelPass* UI::assignTravelPass(subMenuOption timeOption,
		subMenuOption zoneOption){

	Pass::TravelPass* pass = NULL;

	switch (timeOption->index){

	case MENU_INDEX_TIME_2HOURS:

		switch (zoneOption->index){
		case MENU_INDEX_ZONE_1:
			pass = new Pass::TwoHoursZone1();
			break;
		case MENU_INDEX_ZONE_1AND2:
			pass = new Pass::TwoHoursZone1And2();
			break;
		}
		break;

	case MENU_INDEX_TIME_DAY:

		switch (zoneOption->index){
		case MENU_INDEX_ZONE_1:
			pass = new Pass::AllDayZone1();
			break;
		case MENU_INDEX_ZONE_1AND2:
			pass = new Pass::AllDayZone1And2();
			break;
		}

		break;

	}

	return pass;

}
