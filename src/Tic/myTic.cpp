/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#include "myTic.h"

namespace Tic {

	float MyTic::MAX_LIMIT = 100;
	unsigned int MyTic::AMOUNT_DIVISOR = 5;

	MyTic::MyTic()
	: credit(0.0), limit(MAX_LIMIT), maxPasses(0) {}

	MyTic::MyTic(int maxPasses_)
		: credit(0), limit(MAX_LIMIT), maxPasses(maxPasses_){}

	MyTic::MyTic(float theCredit,
			float theLimit, int maxPasses_, vector<string> freeDays)
	: credit(theCredit), limit(theLimit), maxPasses(maxPasses_){
		this->freeDays = freeDays;
	}

	MyTic::~MyTic(){
		Utility::deleteObjectVector(purchases);
	}

	float MyTic::getCredit() const {
		return credit;
	}

	float MyTic::getLimit() const {
		return limit;
	}

	unsigned int MyTic::getMaxPasses() const {
		return maxPasses;
	}

	vector<string> MyTic::getFreeDays() const {
		return this->freeDays;
	}

	void MyTic::setMaxPasses(unsigned int newValue){
		maxPasses = newValue;
	}

	void MyTic::setFreeDays(vector<string> newValue){
		freeDays = newValue;
	}

	/*
	 * Not used. I thought it was better to have this functionality inside the
	 * UI class.
	 */
	void MyTic::input(){}

	/*
	 * Not used. I thought it was better to have this functionality inside the
	 * UI class.
	 */
	void MyTic::print(){}

	bool MyTic::isFreeDay(const string& day){

		if (this->freeDays.size() > 0){
			for (vector<string>::const_iterator it =
					freeDays.begin(); it != freeDays.end(); ++it)
				if (day.compare((*it)) == 0)
					return true;
		}

		return false;

	}

	bool MyTic::canAfford(const string& day, const float amount){

		return getRealAmount(day, amount) <= this->credit;

	}

	/*
	 * Attempt to add credit to an account.
	 * If the amount exceeds the limit, this
	 * function will return false.
	 */
	bool MyTic::addCredit(float amount){

		if (credit + amount > limit)
			return false;

		credit += amount;
		return true;

	}

	/*
	 * Attempt to buy a TravelPass. This function will return false if the user
	 * already has the maximum allowed passes.
	 */
	bool MyTic::buyPass(Pass::TravelPass* pass, const string& day){

		if (maxPasses > 0 && purchases.size() >= maxPasses)
			return false;

		addCredit(-pass->getCost());
		purchases.push_back(pass);

		return true;

	}

	/*
	 * Clear the TravelPasses from memory and empty the vector.
	 */
	void MyTic::clearPurchases(){

		Utility::deleteObjectVector(purchases);
		purchases.clear();

	}

	unsigned int MyTic::getPurchaseCount() const {
		return purchases.size();
	}

	vector<Pass::TravelPass*> MyTic::getPurchases() const {
		return purchases;
	}

	/*
	 * Iterate over the purchases vector and add up the cost of each purchase.
	 */
	float MyTic::getPurchaseTotal(string day) const {

		float result = 0;

		for (vector<Pass::TravelPass*>::const_iterator it =
				purchases.begin(); it != purchases.end(); ++it){
			if (day.length() > 0 &&
					(*it)->getJourneys().size() > 0 &&
					day.compare(Utility::isNumeric(day) ?
					(*it)->getJourneys()[0]->getDepartureDate() :
					(*it)->getJourneys()[0]->getDay()) != 0)
				continue;
			result += (*it)->getCost();
		}

		return result;

	}

	float MyTic::getPurchaseTotalForWeek(const string& endDate) const {

		float result = 0;

		for (vector<Pass::TravelPass*>::const_reverse_iterator it =
				purchases.rbegin(); it != purchases.rend(); ++it){
			if (dynamic_cast<Pass::Weekly*>((*it)) != NULL)
				break;

			if ((*it)->getJourneys().size() > 0 &&
					System::DateTime::compareDates((*it)->getStartDate(),
							System::DateTime::getStartOfWeek(endDate)) >= 0 &&
					System::DateTime::compareDates((*it)->getEndDate(),
							endDate) <= 0)
				result += (*it)->getCost();
		}

		return result;

	}

	void MyTic::removePurchases(const string& day){

//		cout << "Deleting " << purchases[0]->getLength() << endl;
//		delete purchases[0];
//		purchases.erase(purchases.begin());
//		return;
//
//		for (size_t i = 0, i_ = purchases.size(); i < i_; ++i){
//			Pass::TwoHoursZone1* zone =
//			dynamic_cast<Pass::TwoHoursZone1*>(purchases[i]);
//			if (zone != NULL){
//				cout << "Deleting " << zone->getLength() << endl;
//				//delete zone;
//				//delete purchases[i];
//				//purchases.erase(purchases.begin() + i);
//			}
//		}

	}

}
