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

bool Console::run(int argc, char *argv[]){

	bool hasQuit = false;

	if (argc != Console::MAX_ARG_ORDER){
		cerr << "Invalid number of arguments supplied.\nExpected: "
			<< Console::MAX_ARG_ORDER << " Received: " << argc << endl;
		return false;
	}

	//cout << "ela" << endl;

	try {
		if (!m_system.loadStationsFromFile(argv[LoadStations])){
			//cerr << "Error: Did not load any Stations." << endl;
			//return false;
		} else if (!m_system.loadUsersFromFile(argv[LoadUsersAndZones])){
			//cerr << "Error: Did not load any Users." << endl;
			//return false;
		} else if (!m_system.loadZonePricesFromFile(argv[LoadUsersAndZones])){
			//cerr << "Error: Did not load any TravelPasses." << endl;
			//return false;
		}
	} catch (Exception::BaseException& e){
		cerr << e.getMessage() << endl;
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
			//buyJourney();
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
	string day, departureTime, arrivalTime, departureDate, arrivalDate;
	//static int ela = 10;

	if (debug){

		User::BaseUser* user = m_system.getUser("bs");
		System::Station* fromStation = m_system.getStation("central");
		System::Station* toStation = m_system.getStation("flagstaff");
		day = "Monday";
		//departureTime = "0900";
		//arrivalTime = "0905";
		departureTime = "900";
		arrivalTime = "905";
		departureDate = "01012014";
		arrivalDate = "01012014";
		//departureTime = Utility::intToString(ela);
		//departureTime.append("00");
		//arrivalTime = Utility::intToString(ela);
		//arrivalTime.append("20");
		//ela++;
		Journey *journey = new Journey(day, departureDate, arrivalDate, departureTime, arrivalTime, fromStation, toStation);
		try {
			m_system.addJourney(user, journey);
			showCredit(user);
			cout << endl;
		} catch (Exception::InsuffcientCredit &noCredit){
			cerr << noCredit.getMessage() << endl;
			return false;
		}

		fromStation = m_system.getStation("flagstaff");
		toStation = m_system.getStation("richmond");
		day = "Monday";
		departureTime = "1000";
		arrivalTime = "1015";
		departureDate = "01012014";
		arrivalDate = "01012014";
		journey = new Journey(day, departureDate, arrivalDate, departureTime, arrivalTime, fromStation, toStation);
		try {
			m_system.addJourney(user, journey);
			showCredit(user);
			cout << endl;
		} catch (Exception::InsuffcientCredit &noCredit){
			cerr << noCredit.getMessage() << endl;
			return false;
		}


		fromStation = m_system.getStation("richmond");
		toStation = m_system.getStation("flagstaff");
		day = "Monday";
		departureTime = "1500";
		arrivalTime = "1525";
		departureDate = "01012014";
		arrivalDate = "01012014";
		journey = new Journey(day, departureDate, arrivalDate, departureTime, arrivalTime, fromStation, toStation);
		try {
			m_system.addJourney(user, journey);
			showCredit(user);
			cout << endl;
		} catch (Exception::InsuffcientCredit &noCredit){
			cerr << noCredit.getMessage() << endl;
			return false;
		}

		fromStation = m_system.getStation("flagstaff");
		toStation = m_system.getStation("epping");
		day = "Wednesday";
		departureTime = "1500";
		arrivalTime = "1525";
		departureDate = "03012014";
		arrivalDate = "04012014";
		journey = new Journey(day, departureDate, arrivalDate, departureTime, arrivalTime, fromStation, toStation);
		try {
			m_system.addJourney(user, journey);
			showCredit(user);
			cout << endl;
		} catch (Exception::InsuffcientCredit &noCredit){
			cerr << noCredit.getMessage() << endl;
			return false;
		}



		user = m_system.getUser("ws");
		fromStation = m_system.getStation("flagstaff");
		toStation = m_system.getStation("richmond");
		day = "Monday";
		departureTime = "1600";
		arrivalTime = "1650";
		departureDate = "01012014";
		arrivalDate = "01012014";
		journey = new Journey(day, departureDate, arrivalDate, departureTime, arrivalTime, fromStation, toStation);
		try {
			m_system.addJourney(user, journey);
			showCredit(user);
			cout << endl;
		} catch (Exception::InsuffcientCredit &noCredit){
			cerr << noCredit.getMessage() << endl;
			return false;
		}

		fromStation = m_system.getStation("richmond");
		toStation = m_system.getStation("lilydale");
		day = "Monday";
		departureTime = "1700";
		arrivalTime = "1730";
		departureDate = "01012014";
		arrivalDate = "01012014";
		journey = new Journey(day, departureDate, arrivalDate, departureTime, arrivalTime, fromStation, toStation);
		try {
			m_system.addJourney(user, journey);
			showCredit(user);
			cout << endl;
		} catch (Exception::InsuffcientCredit &noCredit){
			cerr << noCredit.getMessage() << endl;
			return false;
		}

		fromStation = m_system.getStation("lilydale");
		toStation = m_system.getStation("epping");
		day = "Monday";
		departureTime = "1800";
		arrivalTime = "1950";
		departureDate = "01012014";
		arrivalDate = "01012014";
		journey = new Journey(day, departureDate, arrivalDate, departureTime, arrivalTime, fromStation, toStation);
		try {
			m_system.addJourney(user, journey);
			showCredit(user);
			cout << endl;
		} catch (Exception::InsuffcientCredit &noCredit){
			cerr << noCredit.getMessage() << endl;
			return false;
		}


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
		departureDate = getDateFromConsole("Departure ");
		departureTime = getTimeFromConsole("Departure ");
		arrivalDate = getDateFromConsole("Arrival ");
		arrivalTime = getTimeFromConsole("Arrival ");


		// TODO: make sure arrival date is after departure date
		int id, ia;
		id = Utility::stringToInt(departureTime);
		ia = Utility::stringToInt(arrivalTime);

		while (id >= ia){
			cerr << "Departure time must be before arrival time." << endl;
			departureTime = getTimeFromConsole("Departure ");
			arrivalTime = getTimeFromConsole("Arrival ");
			id = Utility::stringToInt(departureTime);
			ia = Utility::stringToInt(arrivalTime);
		}

		Journey *journey = new Journey(day, departureDate, arrivalDate, departureTime, arrivalTime, fromStation, toStation);
		try {
			m_system.addJourney(user, journey);
			showCredit(user);
			cout << endl;
		} catch (Exception::InsuffcientCredit &noCredit){
			cerr << noCredit.getMessage() << endl;
			return false;
		}
	}

	return true;
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
				<< " Travel Pass purchased on " << journey->getDay() << " " << journey->getDepartureDate()
				<< " at " << journey->getDepartureTime()
				<< " for $" << Utility::floatToString(pass->getCost(), 2) << endl;

			cout << "Journeys on this pass:" << endl;

			char letter = 'a';
			vector<Journey*> journeys = pass->getJourneys();

			for (vector<Journey*>::const_iterator it3 = journeys.begin(); it3 != journeys.end(); ++it3, ++letter){
				journey = (*it3);
				cout << letter << ". " << journey->getFromStation()->getName()
					<< " to " << journey->getToStation()->getName()
					<< " on " << journey->getDepartureDate()
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
		if (!validateData(id))
			continue;
		user = m_system.getUser(id);

		if (user != NULL){
			// throw Exception::userIdExists();
			Exception::BaseException *e = new Exception::UserIdExists();
			cerr << e->getMessage() << endl;
			delete e;
		} else {
			b = true;
		}
	}

	b = false;
	while (!b){
		name = Utility::getStringFromConsole(1, User::BaseUser::NAME_LEN_MAX, "User name: ", "Error: Invalid name.");
		b = validateData(name);
	}


	b = false;
	while (!b){
		email = Utility::getStringFromConsole(1, User::BaseUser::EMAIL_LEN_MAX, "User email address: ", "Error: Invalid email.");
		//Validation::BaseValidator<string>* emailValidator = dynamic_cast<Validation::EmailAddress*>(m_system.getValidator("email"));
		Validation::EmailAddress emailValidator;
		b = emailValidator(email);
		//b = m_system.getValidator("email")(email);
		if (!b) {
			cerr << "Error: Invalid email format." << endl;
		} else {
			b = validateData(id);
		}

	}
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

	m_system.addUser(user);
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

string Console::getDateFromConsole(string prefix){

	//01012014
	//1012014
	bool b = false;
	string result, errorMessage("Error: Invalid date."), message(prefix);
	const int dateSize = 8;
	const int dayMax = 31;
	const int monthMax = 12;

	if (prefix.length() > 0)
		message.append("d");
	else
		message.append("D");

	message.append("ate: ");

	while (!b){
		result = Utility::getStringFromConsole(dateSize - 1, dateSize, message, errorMessage);
		if (result.length() == dateSize - 1)
			result.insert(0, "0");

		if (!Utility::isNumeric(result)){
			cerr << errorMessage << endl;
		} else if (Utility::stringToInt(result.substr(0, 2)) >= dayMax){
			cerr << errorMessage << endl;
		} else if (Utility::stringToInt(result.substr(2, 2)) >= monthMax){
			cerr << errorMessage << endl;
		} else if (Utility::stringToInt(result.substr(4, 2)) != 20){
			cerr << errorMessage << endl;
		} else {
			b = true;
		}
	}

	return result;

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
		result = Utility::getStringFromConsole(timeSize - 1, timeSize, message, errorMessage);
		if (result.length() == timeSize - 1)
			result.insert(0, "0");
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

bool Console::validateData(const string& str){

	return str.find(System::MyTicSystem::FILE_DATA_DELIM) == string::npos;

}

}
