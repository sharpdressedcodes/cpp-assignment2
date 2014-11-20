/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "console.h"

namespace Ui {

string Console::MENU_STRING_BUY = "Buy a Journey for a User";
string Console::MENU_STRING_CHARGE = "Recharge a MyTic card for a User";
string Console::MENU_STRING_SHOW_CREDIT = "Show remaining credit for a User";
string Console::MENU_STRING_PRINT = "Print User Reports";
string Console::MENU_STRING_UPDATE = "Update pricing";
string Console::MENU_STRING_SHOW_STATS = "Show Stations Statistics";
string Console::MENU_STRING_ADD = "Add a new User";
string Console::MENU_STRING_QUIT = "Save/Quit";

string Console::CREDIT_PREFIX = "Your credit = $";
string Console::YOU_PURCHASED_PREFIX = "You purchased ";
string Console::PURCHASED_PREFIX = "Purchased ";
string Console::PURCHASES_PREFIX = "\nPurchases: ($";
string Console::PURCHASES_SUFFIX = ")\n";

string Console::MESSAGE_CANNOT_ADD_CREDIT = "You cannot add anymore credit!";
string Console::MESSAGE_ADD_CREDIT = "How much do you want to add: ";
string Console::MESSAGE_CREDIT_OVER = "Sorry, the maximum allowed credit is $";
string Console::MESSAGE_CREDIT_DIVISOR = "Sorry, you can only add multiples of $";
string Console::MESSAGE_NOT_ENOUGH_CREDIT =
		"Sorry, you don't have enough credit for that selection.";
string Console::MESSAGE_NO_PURCHASES = "No purchases found.\n\n";
string Console::MESSAGE_NO_CREDIT = "You don't have any credit!";
string Console::MESSAGE_MAX_PASSES =
		"You have reached the maximum number of Travel Passes";
//string UI::MESSAGE_MENU_WELCOME = "Welcome to MyTic!";
//string UI::MESSAGE_MENU_OPTION = "Choose an option:";
string Console::MESSAGE_MENU_OPTION = "Options:";
//string UI::MESSAGE_MENU_SELECTION = "Please make a selection: ";
string Console::MESSAGE_MENU_SELECTION = "What is your selection: ";
string Console::MESSAGE_MENU_INVALID_SELECTION =
		"Sorry, that is an invalid option!";
string Console::MESSAGE_MENU_GOODBYE = "Goodbye!";
string Console::MESSAGE_MENU_TIME_PERIOD = "\nWhat time period:";
string Console::MESSAGE_MENU_YOUR_SELECTION = "Your selection: ";
string Console::MESSAGE_MENU_ZONE = "\nWhich zone:";

Console::Console(){

	loadMenu();

}

Console::~Console(){

	deleteMenu();

}

/*
 * Load the time submenu variables into the struct.
 */
//void UI::loadTimeMenu(subMenu& timeOptions){
//
//	//int i = 0;
//
//	/*for (i = 0; i < Ui::MAX_MENU_TIME; i++)
//		timeOptions.push_back(new UI::menuOptions<char>());
//
//	i = 0;
//
//	timeOptions[i]->index = MENU_INDEX_TIME_2HOURS;
//	timeOptions[i]->subIndex = i;
//	timeOptions[i++]->text = Pass::TwoHoursZone1::DEFAULT_LENGTH;
//
//	timeOptions[i]->index = MENU_INDEX_TIME_DAY;
//	timeOptions[i]->subIndex = i;
//	timeOptions[i++]->text = Pass::AllDayZone1::DEFAULT_LENGTH;
//
//	timeOptions[i]->isQuit = true;
//	timeOptions[i]->index = MENU_INDEX_TIME_CANCEL;
//	timeOptions[i]->subIndex = i;
//	timeOptions[i++]->text = MENU_STRING_CANCEL;*/
//
//}

/*
 * Load the zone submenu variables into the struct.
 */
//void UI::loadZoneMenu(subMenu& zoneOptions){
//
//	//int i = 0;
//
//	/*for (i = 0; i < MAX_MENU_ZONE; i++)
//		zoneOptions.push_back(new UI::menuOptions<char>());
//
//	i = 0;
//
//	zoneOptions[i]->index = MENU_INDEX_ZONE_1;
//	zoneOptions[i]->subIndex = i;
//	zoneOptions[i++]->text = AllDayZone1::DEFAULT_ZONES;
//
//	zoneOptions[i]->index = MENU_INDEX_ZONE_1AND2;
//	zoneOptions[i]->subIndex = i;
//	zoneOptions[i++]->text = AllDayZone1And2::DEFAULT_ZONES;
//
//	zoneOptions[i]->isQuit = true;
//	zoneOptions[i]->index = MENU_INDEX_ZONE_CANCEL;
//	zoneOptions[i]->subIndex = i;
//	zoneOptions[i++]->text = MENU_STRING_CANCEL;*/
//
//}

/*
 * Remove the time submenu structs from memory.
 */
//void UI::deleteTimeMenu(subMenu& timeOptions){
//
//	for (size_t i = 0; i < timeOptions.size(); i++)
//		delete timeOptions[i];
//
//	timeOptions.clear();
//
//}

/*
 * Remove the zone submenu structs from memory.
 */
//void UI::deleteZoneMenu(subMenu& zoneOptions){
//
//	for (size_t i = 0; i < zoneOptions.size(); i++)
//		delete zoneOptions[i];
//
//	zoneOptions.clear();
//
//}

//void UI::showCredit(const Tic::MyTic& tic) {
//
//	cout << CREDIT_PREFIX
//		<< Utility::floatToString(tic.getCredit(), 2) << "\n\n";
//
//}

/*
 * Attempt to add credit to the MyTic object.
 */
//void UI::addCredit(Tic::MyTic& tic){
//
//	bool chargeValid = false;
//	int charge = 0;
//	stringstream ss;
//
//	ss << MESSAGE_CREDIT_OVER
//		<< Utility::floatToString((float)tic.getLimit(), 2);
//
//	while (!chargeValid){
//
//		// Don't proceed if they have full credit.
//		if (tic.getCredit() >= tic.getLimit()){
//			cerr << MESSAGE_CANNOT_ADD_CREDIT << endl;
//			break;
//		}
//
//		charge = Utility::getIntFromConsole(
//				Tic::MyTic::AMOUNT_DIVISOR,
//			tic.getLimit(),
//			MESSAGE_ADD_CREDIT,
//			ss.str(),
//			false
//		);
//
//		// Will this blow their budget?
//		if (tic.getCredit() + charge > tic.getLimit()){
//			cerr << ss.str() << endl;
//
//		// Test for divisor
//		} else if (charge % Tic::MyTic::AMOUNT_DIVISOR != 0){
//			cerr << MESSAGE_CREDIT_DIVISOR
//				<< Utility::floatToString((float)Tic::MyTic::AMOUNT_DIVISOR, 2)
//				<< endl;
//
//		} else {
//			chargeValid = true;
//			tic.addCredit(charge);
//		}
//
//	}
//
//}

/*
 * Attempt to buy a ticket. The user can press 'c' for Cancel at any time
 * throughout this process.
 */
//bool UI::buyTicket(Tic::MyTic& tic, subMenu timeOptions, subMenu zoneOptions){
//
//	bool result = false;
//	subMenuOption timeOption = NULL;
//	subMenuOption zoneOption = NULL;
//
//	// Don't proceed if they are broke.
//	if (tic.getCredit() == 0){
//		cerr << MESSAGE_NO_CREDIT << endl;
//		return false;
//	}
//
//	timeOption = enterTimeMenu(timeOptions);
//
//	if (timeOption != NULL){
//		zoneOption = enterZoneMenu(zoneOptions);
//
//		if (zoneOption != NULL){
//
//			// Assign a generic TravelPass pointer.
//			TravelPass *pass = assignTravelPass(timeOption, zoneOption);
//			if (pass != NULL){
//
//				float cost = pass->getCost();
//
//				// Make sure they have enough credit for this purchase.
//				if (cost > tic.getCredit()){
//					cerr << MESSAGE_NOT_ENOUGH_CREDIT << endl;
//					delete pass;
//
//				} else {
//
//					// The MyTic::buyPass() method will check if the user
//					// can buy any more passes.
//					if (tic.buyPass(pass)){
//						cout << YOU_PURCHASED_PREFIX;
//						pass->print();
//						showCredit(tic);
//
//					// The user has reached the max number of passes allowed.
//					} else {
//						cerr << MESSAGE_MAX_PASSES << endl;
//						delete pass;
//					}
//
//				}
//
//			}
//
//		}
//	}
//
//	return result;
//
//}

/*
 * Iterates over the purchases vector and prints each purchase.
 */
//void UI::printPurchases(Tic::MyTic& tic){
//
//	vector<TravelPass*> purchases = tic.getPurchases();
//
//	cout << PURCHASES_PREFIX
//			<< Utility::floatToString(tic.getPurchaseTotal(), 2)
//			<< PURCHASES_SUFFIX;
//
//	if (purchases.size() > 0){
//		for (vector<TravelPass*>::const_iterator it = purchases.begin();
//				it != purchases.end(); ++it){
//			cout << PURCHASED_PREFIX;
//			(*it)->print();
//		}
//		cout << endl;
//	} else {
//		cout << MESSAGE_NO_PURCHASES;
//	}
//
//}

/*
 * Main Menu.
 * Present the user with a set of main options.
 */
//bool UI::enterMenu(/*Tic::MyTic& tic, */int argc, char *argv[], mainMenu options){//,
//		//subMenu timeOptions, subMenu zoneOptions){
//
//	bool hasQuit = false;
//
//	if (argc != UI::ARG_ORDER_MAX){
//		cerr << "Invalid number of arguments supplied.\nExpected: "
//			<< UI::ARG_ORDER_MAX << " Received: " << argc << endl;
//		return false;
//	}
//
//	if (!m_system.loadStationsFromFile(argv[LoadStations])){
//		cerr << "Error: Did not load any Stations." << endl;
//		return false;
//	} else if (!m_system.loadUsersFromFile(argv[LoadUsersAndZones])){
//		cerr << "Error: Did not load any Users." << endl;
//		return false;
//	} else if (!m_system.loadZonePricesFromFile(argv[LoadUsersAndZones])){
//		cerr << "Error: Did not load any TravelPasses." << endl;
//		return false;
//	}
//
//	//cout << MESSAGE_MENU_WELCOME << endl;
//
//	while (!hasQuit) {
//
//		mainMenuOption quitOption = NULL;
//
//		cout << MESSAGE_MENU_OPTION << endl;
//
//		// Iterate over the main menu structs and display each option.
//		for (mainMenu::iterator it = options.begin();
//				it != options.end(); ++it){
//			mainMenuOption option = (*it);
//			// Always display the quit option last.
//			if (!option->isQuit)
//				cout << option->index << ". " << option->text << endl;
//			else
//				quitOption = option;
//		}
//
//		if (quitOption)
//			cout << quitOption->index << ". " << quitOption->text << endl;
//
//		int selection = Utility::getIntFromConsole(
//			MENU_INDEX_QUIT,
//			MAX_MENU - 1,
//			MESSAGE_MENU_SELECTION,
//			MESSAGE_MENU_INVALID_SELECTION,
//			false
//		);
//
//		switch (selection){
//
//		case MENU_INDEX_BUY:
//
//			//buyTicket(tic, timeOptions, zoneOptions);
//			break;
//
//		case MENU_INDEX_CHARGE:
//
//			//addCredit(tic);
//			//showCredit(tic);
//			break;
//
//		case MENU_INDEX_SHOW_CREDIT:
//
//			//showCredit(tic);
//			break;
//
//		case MENU_INDEX_PRINT:
//
//			//printPurchases(tic);
//			break;
//
//		case MENU_INDEX_UPDATE:
//
//			//
//			break;
//
//		case MENU_INDEX_SHOW_STATS:
//
//			//
//			break;
//
//		case MENU_INDEX_ADD:
//
//			//
//			break;
//
//		case MENU_INDEX_QUIT:
//
//			hasQuit = true;
//			break;
//
//		}
//
//	}
//
//	// Clean memory.
//	//tic.clearPurchases();
//	m_system.saveUsersToFile(argv[UI::SaveUsersAndZones]);
//	m_system.saveZonesToFile(argv[UI::SaveUsersAndZones]);
//
//	//cout << MESSAGE_MENU_GOODBYE << endl;
//
//	return true;
//
//}

/*
 * Time Sub Menu.
 * Present the user with a set of sub options to select a ticket type
 * based on time.
 */
//UI::subMenuOption UI::enterTimeMenu(subMenu timeOptions){
//
//	/*bool hasQuit = false;
//
//	while (!hasQuit){
//
//		subMenuOption quitOption = NULL;
//
//		cout << MESSAGE_MENU_TIME_PERIOD << endl;
//
//		// Iterate over the sub menu structs and display each option.
//		for (subMenu::iterator it = timeOptions.begin();
//				it != timeOptions.end(); ++it){
//			subMenuOption option = (*it);
//			// Always display the quit option last.
//			if (!option->isQuit)
//				cout << option->index << ") " << option->text << endl;
//			else
//				quitOption = option;
//		}
//
//		if (quitOption)
//			cout << quitOption->index << ") " << quitOption->text << endl;
//
//		string selection;
//		bool validSelection = true;
//
//		do {
//			validSelection = false;
//			selection = Utility::getStringFromConsole(
//				1,
//				1,
//				MESSAGE_MENU_YOUR_SELECTION,
//				MESSAGE_MENU_INVALID_SELECTION,
//				false
//			);
//			// Validate the selected option.
//			if (!selection.empty())
//				validSelection = validateTimeOption(selection[0], timeOptions);
//			if (!validSelection)
//				cerr << MESSAGE_MENU_INVALID_SELECTION << endl;
//		} while (!validSelection);
//
//		// Iterate over the sub menu structs to find which option was selected.
//		for (subMenu::iterator it = timeOptions.begin();
//				it != timeOptions.end(); ++it){
//
//			subMenuOption option = (*it);
//
//			if (selection[0] == option->index){
//
//				if (option->index == MENU_INDEX_TIME_CANCEL){
//					hasQuit = true;
//					break;
//				} else {
//					return timeOptions[option->subIndex];
//				}
//
//			}
//
//		}
//
//	}*/
//
//	return NULL;
//
//}

/*
 * Zone Sub Menu.
 * Present the user with a set of sub options to select a ticket type
 * based on zone.
 */
//UI::subMenuOption UI::enterZoneMenu(subMenu zoneOptions){
//
//	/*bool hasQuit = false;
//
//	while (!hasQuit){
//
//		subMenuOption quitOption = NULL;
//
//		cout << MESSAGE_MENU_ZONE << endl;
//
//		// Iterate over the sub menu structs and display each option.
//		for (subMenu::iterator it = zoneOptions.begin();
//				it != zoneOptions.end(); ++it){
//			subMenuOption option = (*it);
//			// Always display the quit option last.
//			if (!option->isQuit)
//				cout << option->index << ") " << option->text << endl;
//			else
//				quitOption = option;
//		}
//
//		if (quitOption)
//			cout << quitOption->index << ") " << quitOption->text << endl;
//
//		string selection;
//		bool validSelection = true;
//
//		do {
//			validSelection = false;
//			selection = Utility::getStringFromConsole(
//				1,
//				1,
//				MESSAGE_MENU_YOUR_SELECTION,
//				MESSAGE_MENU_INVALID_SELECTION,
//				false
//			);
//			// Validate the selected option.
//			if (!selection.empty())
//				validSelection = validateZoneOption(selection[0], zoneOptions);
//			if (!validSelection)
//				cerr << MESSAGE_MENU_INVALID_SELECTION << endl;
//		} while (!validSelection);
//
//		// Iterate over the sub menu structs to find which option was selected.
//		for (subMenu::iterator it = zoneOptions.begin();
//				it != zoneOptions.end(); ++it){
//
//			subMenuOption option = (*it);
//
//			if (selection[0] == option->index){
//
//				if (option->index == MENU_INDEX_ZONE_CANCEL){
//					hasQuit = true;
//					break;
//				} else {
//					return zoneOptions[option->subIndex];
//				}
//
//			}
//
//		}
//
//	}*/
//
//	return NULL;
//
//}

/*
 * Validates the time sub menu option.
 */
//bool UI::validateTimeOption(const char option, subMenu timeOptions){
//
//	bool result = false;
//
//	for (subMenu::iterator it = timeOptions.begin();
//			it != timeOptions.end(); ++it){
//		if ((*it)->index == option){
//			result = true;
//			break;
//		}
//	}
//
//	return result;
//
//}

/*
 * Validates the zone sub menu option.
 */
//bool UI::validateZoneOption(const char option, subMenu zoneOptions){
//
//	bool result = false;
//
//	for (subMenu::iterator it = zoneOptions.begin();
//			it != zoneOptions.end(); ++it){
//		if ((*it)->index == option){
//			result = true;
//			break;
//		}
//	}
//
//	return result;
//
//}

/*
 * Assigns a generic TravelPass pointer based on time and zone.
 */
//Pass::TravelPass* UI::assignTravelPass(subMenuOption timeOption,
//		subMenuOption zoneOption){
//
//	Pass::TravelPass* pass = NULL;
//
//	/*switch (timeOption->index){
//
//	case MENU_INDEX_TIME_2HOURS:
//
//		switch (zoneOption->index){
//		case MENU_INDEX_ZONE_1:
//			pass = new Pass::TwoHoursZone1();
//			break;
//		case MENU_INDEX_ZONE_1AND2:
//			pass = new Pass::TwoHoursZone1And2();
//			break;
//		}
//		break;
//
//	case MENU_INDEX_TIME_DAY:
//
//		switch (zoneOption->index){
//		case MENU_INDEX_ZONE_1:
//			pass = new Pass::AllDayZone1();
//			break;
//		case MENU_INDEX_ZONE_1AND2:
//			pass = new Pass::AllDayZone1And2();
//			break;
//		}
//
//		break;
//
//	}*/
//
//	return pass;
//
//}

bool Console::run(int argc, char *argv[]){

	bool hasQuit = false;

	if (argc != Console::MAX_ARG_ORDER){
		cerr << "Invalid number of arguments supplied.\nExpected: "
			<< Console::MAX_ARG_ORDER << " Received: " << argc << endl;
		return false;
	}

	if (!m_system.loadStationsFromFile(argv[LoadStations])){
		cerr << "Error: Did not load any Stations." << endl;
		return false;
	} else if (!m_system.loadUsersFromFile(argv[LoadUsersAndZones])){
		cerr << "Error: Did not load any Users." << endl;
		return false;
	} else if (!m_system.loadZonePricesFromFile(argv[LoadUsersAndZones])){
		cerr << "Error: Did not load any TravelPasses." << endl;
		return false;
	}

	map<string, System::Station*> stations = m_system.getStations();
	for (map<string, System::Station*>::const_iterator it = stations.begin(); it != stations.end(); ++it)
		cout << it->first << " " << it->second->getZone() << endl;

	map<string, User::BaseUser*> users = m_system.getUsers();
	for (map<string, User::BaseUser*>::const_iterator it = users.begin(); it != users.end(); ++it)
		cout << it->first << " " << it->second->getName() << " " << it->second->getEmail() << " " << it->second->getTic()->getCredit() << endl;

	map<string, Pass::TravelPass*> passes = m_system.getPasses();
	for (map<string, Pass::TravelPass*>::const_iterator it = passes.begin(); it != passes.end(); ++it)
		cout << it->first << endl; /*<< " " << it->second->getLength() << " " << it->second->getZones() << " " << it->second->getCost() << endl*/;

	while (!hasQuit) {

		mainMenuOption quitOption = NULL;
		User::BaseUser* user = NULL;

		cout << "\n" << MESSAGE_MENU_OPTION << endl;

		// Iterate over the main menu structs and display each option.
		for (mainMenu::iterator it = m_options.begin();
				it != m_options.end(); ++it){
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
			MENU_INDEX_BUY,
			MENU_INDEX_QUIT,
			MESSAGE_MENU_SELECTION,
			MESSAGE_MENU_INVALID_SELECTION,
			false
		);

		cout << endl;

		switch (selection){

		case MENU_INDEX_BUY:

			buyJourney(true);
			break;

		case MENU_INDEX_CHARGE:

			user = rechargeTic();
			if (user)
				showCredit(user);

			break;

		case MENU_INDEX_SHOW_CREDIT:

			showCredit();
			break;

		case MENU_INDEX_PRINT:

			printReports();
			break;

		case MENU_INDEX_UPDATE:

			updatePricing();
			break;

		case MENU_INDEX_SHOW_STATS:

			showStatistics();
			break;

		case MENU_INDEX_ADD:

			addUser();
			break;

		case MENU_INDEX_QUIT:

			hasQuit = true;
			break;

		}

	}

	cout << MESSAGE_MENU_GOODBYE << endl;

	// Persist user and zone states.
	m_system.saveUsersToFile(argv[Console::SaveUsersAndZones]);
	m_system.saveZonesToFile(argv[Console::SaveUsersAndZones]);

	return true;

}

bool Console::buyJourney(bool debug){

	const unsigned int minDayLength = 3;
	string day, departureTime, arrivalTime;
	static int ela = 10;

	if (debug){
		User::BaseUser* user = m_system.getUser("bs");
		System::Station* fromStation = m_system.getStation("epping");
		System::Station* toStation = m_system.getStation("central");
		day = "Monday";
		//departureTime = "0700";
		//arrivalTime = "0800";
		departureTime = Utility::intToString(ela);
		departureTime.append("00");
		arrivalTime = Utility::intToString(ela);
		arrivalTime.append("20");
		ela++;
		Journey *journey = new Journey(day, departureTime, arrivalTime, fromStation, toStation);
		m_system.addJourney(user, journey);
		showCredit(user);
	} else {
		User::BaseUser* user = getUserFromConsole();
		System::Station* fromStation = getStationFromConsole("From");
		System::Station* toStation = getStationFromConsole("To");

		while (fromStation->getName().compare(toStation->getName()) == 0){
			cerr << "Error: stations must be different." << endl;
			toStation = getStationFromConsole("To");
		}

		day = Utility::getSubstringChoiceFromConsole(
			minDayLength,
			System::DateTime::getDaysAsVector(),
			"What day: ",
			"Error: Invalid day."
		);
		departureTime = getTimeFromConsole("Departure ");
		arrivalTime = getTimeFromConsole("Arrival ");

		Journey *journey = new Journey(day, departureTime, arrivalTime, fromStation, toStation);
		m_system.addJourney(user, journey);
		showCredit(user);
	}



	//Journey *journey = new Journey(day, departureTime, arrivalTime, fromStation, toStation);
	//m_system.addJourney(user, journey);

//	showCredit(user);

	return false;
}

User::BaseUser* Console::rechargeTic(){

	bool b = false;
	int credit = 0;
	stringstream ss;
	User::BaseUser* user = NULL;

	user = getUserFromConsole();
	ss << "How much do you want to add to " << user->getId() << "'s card: ";
	//credit = Utility::getIntFromConsole(0, Tic::MyTic::MAX_LIMIT, ss.str(), "Error: Invalid amount.");

	// TODO: test this
	while (!b){
		credit = Utility::getIntFromConsole(0, Tic::MyTic::MAX_LIMIT, ss.str(), "Error: Invalid amount.");
		//b = user->addCredit(credit);
		b = user->getTic()->addCredit(credit);
		if (!b)
			cerr << "Error: Cannot add that amount." << endl;
	}

	cout << "Added $" << Utility::floatToString(credit, 2) << " to " << user->getId() << "'s card" << endl;

	return user;
}

void Console::showCredit(User::BaseUser* user){

	if (user == NULL)
		user = getUserFromConsole();

	cout << "Credit remaining for " << user->getId() << ": $" << Utility::floatToString(user->getTic()->getCredit(), 2) << endl;

}

void Console::printReports(){

	bool printed = false;
	map<string, User::BaseUser*> users = m_system.getUsers();

	cout << "User Reports:" << endl;

	for (map<string, User::BaseUser*>::const_iterator it = users.begin(); it != users.end(); ++it){

		vector<Pass::TravelPass*> passes = it->second->getTic()->getPurchases();
		unsigned int counter = 1;

		if (passes.size() > 0){
			if (printed)
				cout << endl;
			printed = true;
			cout << "Purchases by " << it->second->getId() << ":" << endl;
		}

		for (vector<Pass::TravelPass*>::const_iterator it2 = passes.begin(); it2 != passes.end(); ++it2){
			Pass::TravelPass* pass = (*it2);
			bool consession = dynamic_cast<Tic::ConsessionTic*>(it->second->getTic()) != NULL;
			if (pass->getJourneys().size() == 0){
				//cerr << "No journeys for " << pass->toString() << endl;
				//return;
				continue;
			}
			Journey *journey = pass->getJourneys().at(0);
			cout << counter << ". " << pass->getLength() << " "
				<< pass->getZones() << (consession ? " Consession" : "")
				<< " Travel Pass purchased on " << journey->getDay()
				<< " at " << journey->getDepartureTime()
				<< " for $" << Utility::floatToString(pass->getCost(), 2) << endl;

			cout << "Journeys on this pass:" << endl;

			char letter = 'a';
			vector<Journey*> journeys = pass->getJourneys();

			for (vector<Journey*>::const_iterator it3 = journeys.begin(); it3 != journeys.end(); ++it3, ++letter){
				journey = (*it3);
				cout << letter << ". " << journey->getFromStation()->getName()
					<< " to " << journey->getToStation()->getName()
					<< " at " << journey->getDepartureTime() << endl;
			}

			++counter;

		}

	}

	if (!printed)
		cout << "No purchases found." << endl;

}

bool Console::updatePricing(){

	bool b = false;
	Pass::TravelPass* pass = getPassFromConsole(" to update");

	while (!b){
		string cost = Utility::getStringFromConsole(1, 5, "What is the new price: ", "Error: Invalid price.");

		if (Utility::isNumeric(cost, true)){

			float value = Utility::stringToFloat(cost);

			if (value > Tic::MyTic::MAX_LIMIT){
				cerr << "Error: That amount is over the maximum (" << Tic::MyTic::MAX_LIMIT << ")." << endl;
			} else {
				pass->setCost(value);
				b = true;
			}

		} else {

			cerr << "Error: Invalid price." << endl;

		}
	}

	cout << "New price of " << pass->getLength()
		<< " " << pass->getZones() << " Travel Pass is $"
		<< Utility::floatToString(pass->getCost(), 2) << endl;

	return false;
}

void Console::showStatistics(){

	map<string, System::Station*> stations = m_system.getStations();

	cout << "Station travel statistics:" << endl;

	for (map<string, System::Station*>::const_iterator it = stations.begin(); it != stations.end(); ++it){
		System::Station *station = it->second;
		cout << station->getName() << ": "
			<< station->getStartedJourneys() << " journeys started here, "
			<< station->getFinishedJourneys() << " journeys finished here."
			<< endl;
	}

}

bool Console::addUser(){

	bool b = false;
	string id, name, email, type;
	User::BaseUser* user = NULL;
	vector<string> choices;

	choices.push_back("a");
	choices.push_back("j");
	choices.push_back("s");

	while (!b){
		id = Utility::getStringFromConsole(1, m_system.getLongestUserIdLength(), "Choose an id: ", "Error: Invalid id.");
		user = m_system.getUser(id);
		if (user != NULL){
			cerr << "Sorry that id is already in use.";
		} else {
			b = true;
		}
	}

	name = Utility::getStringFromConsole(1, User::BaseUser::NAME_LEN_MAX, "User name: ", "Error: Invalid name.");
	email = Utility::getStringFromConsole(1, User::BaseUser::EMAIL_LEN_MAX, "User email address: ", "Error: Invalid email.");
	type = Utility::getStringChoiceFromConsole(choices, "What type of user: (a)dult, (j)unior, (s)enior?", "That is an invalid type of user.");

	switch (type[0]){
	case 's':
		user = new User::Senior(id, name, email, 0);
		type = "Senior";
		break;
	case 'a':
		user = new User::Adult(id, name, email, 0);
		type = "Adult";
		break;
	case 'j':
		user = new User::Junior(id, name, email, 0);
		type = "Junior";
		break;
	}

	m_system.getUsers()[id] = user;
	cout << "Created new " << type << " user with id " << id << endl;

	return true;
}



/*
 * Private methods.
 */

/*
 * Load the main menu variables into the struct.
 */
void Console::loadMenu(/*mainMenu& options*/){

	int i = 0;

	for (i = MENU_INDEX_BUY; i < MAX_MENU; ++i)
		m_options.push_back(new Console::menuOptions<int>());

	i = 0;

	m_options[i]->index = MENU_INDEX_BUY;
	m_options[i++]->text = MENU_STRING_BUY;

	m_options[i]->index = MENU_INDEX_CHARGE;
	m_options[i++]->text = MENU_STRING_CHARGE;

	m_options[i]->index = MENU_INDEX_SHOW_CREDIT;
	m_options[i++]->text = MENU_STRING_SHOW_CREDIT;

	m_options[i]->index = MENU_INDEX_PRINT;
	m_options[i++]->text = MENU_STRING_PRINT;

	m_options[i]->index = MENU_INDEX_UPDATE;
	m_options[i++]->text = MENU_STRING_UPDATE;

	m_options[i]->index = MENU_INDEX_SHOW_STATS;
	m_options[i++]->text = MENU_STRING_SHOW_STATS;

	m_options[i]->index = MENU_INDEX_ADD;
	m_options[i++]->text = MENU_STRING_ADD;

	m_options[i]->isQuit = true;
	m_options[i]->index = MENU_INDEX_QUIT;
	m_options[i++]->text = MENU_STRING_QUIT;

}

/*
 * Remove the main menu structs from memory.
 */
void Console::deleteMenu(/*mainMenu& options*/){

	for (size_t i = 0; i < m_options.size(); i++)
		delete m_options[i];

	m_options.clear();

}

User::BaseUser* Console::getUserFromConsole(){

	User::BaseUser* user = NULL;

	while (user == NULL){
		string id = Utility::getStringFromConsole(1, m_system.getLongestUserIdLength(), "What user: ", "Error: Input string too long.");
		user = m_system.getUser(id);
		if (user == NULL)
			cerr << "Error: Cannot find that user, try again." << endl;
	}

	return user;

}

System::Station* Console::getStationFromConsole(string prefix){

	System::Station *station = NULL;
	string message;

	message.append(prefix);
	message.append(prefix.length() > 0 ? " w" : "W");
	message.append("hat station: ");

	while (station == NULL){
		string name = Utility::getStringFromConsole(1, m_system.getLongestStationIdLength(), message, "Error: Input string too long.");
		station = m_system.getStation(name);
		if (station == NULL)
			cerr << "Error: Cannot find that station, try again." << endl;
	}

	return station;

}

Pass::TravelPass* Console::getPassFromConsole(string suffix){

	Pass::TravelPass* pass = NULL;
	string message1, message2, error1, error2;
	vector<string> arr1, arr2;

	message1.append("Which Duration Pass do you want");
	message1.append(suffix);
	message1.append(": (2)Hour or (A)ll Day: ");

	message2.append("Which Zone Pass do you want");
	message2.append(suffix);
	message2.append(": Zone (1) or Zone 1-(2): ");

	error1 = "Error: Invalid duration.";
	error2 = "Error: Invalid zone.";

	arr1.push_back("2");
	arr1.push_back("A");

	arr2.push_back("1");
	arr2.push_back("2");

	while (pass == NULL){

		stringstream ss;
		string length = Utility::getStringChoiceFromConsole(arr1, message1, error1);
		string zone = Utility::getStringChoiceFromConsole(arr2, message2, error2);

		switch (length[0]){
		case '2':
			ss << "2Hour";
			break;
		case 'A':
			ss << "AllDay";
			break;
		}

		switch (zone[0]){
		case '1':
			ss << "Zone1";
			break;
		case '2':
			ss << "Zone12";
			break;
		}

		pass = m_system.getPass(ss.str());

		if (pass == NULL)
			cerr << "Error: Cannot find that Pass, try again." << endl;

	}

	return pass;

}

string Console::getTimeFromConsole(string prefix){

	bool b = false;
	string result, errorMessage("Error: Invalid time."), message(prefix);
	const int timeSize = 4;
	const int hourMax = 24;
	const int minuteMax = 60;
	int ts = timeSize >> 1;

	if (prefix.length() > 0)
		message.append("t");
	else
		message.append("T");

	message.append("ime: ");

	while (!b){
		result = Utility::getStringFromConsole(timeSize, timeSize, message, errorMessage);
		if (!Utility::isNumeric(result)){
			cerr << errorMessage << endl;
		} else if (Utility::stringToInt(result.substr(0, ts)) >= hourMax){
			cerr << errorMessage << endl;
		} else if (Utility::stringToInt(result.substr(ts, ts)) >= minuteMax){
			cerr << errorMessage << endl;
		} else {
			b = true;
		}
	}

	return result;

}

}
