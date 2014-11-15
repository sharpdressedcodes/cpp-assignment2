/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 1 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

// testTravelPass.cpp for CPT 323 Assignment 1 SP3 2014
//
//
// CPT323 2014  assignment 1

#include "testTravelPass.h"

/*
 * Program entry point.
 */
int main(int argc, char *argv[]){

	//System::MyTicSystem system;
	UI::mainMenu options;

	/*if (argc != UI::ARG_ORDER_MAX){
		cerr << "Invalid number of arguments supplied.\nExpected: "
			<< UI::ARG_ORDER_MAX << " Received: " << argc << endl;
		return EXIT_FAILURE;
	}

	system.loadStationsFromFile(argv[UI::LoadStations]);
	system.loadUsersFromFile(argv[UI::LoadUsersAndZones]);
	system.loadZonePricesFromFile(argv[UI::LoadUsersAndZones]);

	if (system.getStations().size() == 0){
		cerr << "Error: Did not load any Stations." << endl;
		return EXIT_FAILURE;
	} else if (system.getUsers().size() == 0){
		cerr << "Error: Did not load any Users." << endl;
		return EXIT_FAILURE;
	} else if (system.getPasses().size() == 0){
		cerr << "Error: Did not load any TravelPasses." << endl;
		return EXIT_FAILURE;
	}*/


	UI::instance()->loadMenu(options);

	if (!UI::instance()->enterMenu(argc, argv, options))
		return EXIT_FAILURE;

//	map<string, System::Station*> stations = system.getStations();
//	for (map<string, System::Station*>::const_iterator it = stations.begin(); it != stations.end(); ++it)
//		cout << it->first << " " << it->second->getZone() << endl;
//
//	map<string, User::BaseUser*> users = system.getUsers();
//	for (map<string, User::BaseUser*>::const_iterator it = users.begin(); it != users.end(); ++it)
//		cout << it->first << " " << it->second->getName() << " " << it->second->getEmail() << " " << it->second->getCredit() << endl;
//
//	map<string, Pass::TravelPass*> passes = system.getPasses();
//	for (map<string, Pass::TravelPass*>::const_iterator it = passes.begin(); it != passes.end(); ++it)
//		cout << it->first /*<< " " << it->second->getLength() << " " << it->second->getZones() << " " << it->second->getCost() << endl*/;

	UI::instance()->deleteMenu(options);

	//system.saveUsersToFile(argv[UI::SaveUsersAndZones]);
	//system.saveZonesToFile(argv[UI::SaveUsersAndZones]);

	//Create MyTic object and use this object in the menu
	/*Tic::MyTic tic(MAX_TRAVELPASSES);
	UI::mainMenu options;
	UI::subMenu timeOptions;
	UI::subMenu zoneOptions;

	// Load menus.
	UI::instance()->loadMenu(options);
	UI::instance()->loadTimeMenu(timeOptions);
	UI::instance()->loadZoneMenu(zoneOptions);
   
	// Enter main menu. This will also trigger the sub menus if selected.
	UI::instance()->enterMenu(tic, options, timeOptions, zoneOptions);

	// Clean up.
	UI::instance()->deleteMenu(options);
	UI::instance()->deleteTimeMenu(timeOptions);
	UI::instance()->deleteZoneMenu(zoneOptions);*/

	/*
	 * Task C4 - uncomment to check.
	 */
	//TwoHoursZone1 thz1;
	//cin >> thz1;
	//cout << thz1;

	return EXIT_SUCCESS;

}
