/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

// testTravelPass.cpp for CPT 323 Assignment 2 SP3 2014
//
//
// CPT323 2014  assignment 2

#include "testTravelPass.h"

/*
 * Program entry point.
 */
int main(int argc, char *argv[]){

	Ui::Console console;

	// Requirement 8 example
	System::Storage<int> *storage = new System::Storage<int>();
	delete storage;
	// end example

	if (!console.run(argc, argv))
		return EXIT_FAILURE;

	return EXIT_SUCCESS;

}
