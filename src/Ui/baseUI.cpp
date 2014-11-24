/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "baseUI.h"

namespace Ui {

BaseUI::BaseUI(){
	m_system = new System::MyTicSystem();
}

BaseUI::~BaseUI(){
	delete m_system;
}

System::MyTicSystem* BaseUI::getSystem() {
	return m_system;
}

}
