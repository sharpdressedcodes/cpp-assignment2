
#ifndef MYTICSYSTEM_H_
#define MYTICSYSTEM_H_

#include <map>
#include <string>
#include "../User/baseUser.h"
#include "../User/adult.h"
#include "../User/junior.h"
#include "../User/senior.h"
#include "../Pass/journey.h"
#include "dateTime.h"
#include "station.h"

using std::map;
using std::string;

namespace System {

	enum UserType {
		Adult,
		Junior,
		Senior
	};

	class MyTicSystem {
	private:
		map<string, User::BaseUser*> users;
		map<string, Station*> stations;
		map<string, Pass::TravelPass*> passes;
		static const string USER_FILE_FLAG;
		static const string ZONE_FILE_FLAG;
		static const string COMMENT_FILE_FLAG;
		static const string FILE_DATA_DELIM;
		static const unsigned int MAX_TRAVELPASSES;
	public:
		MyTicSystem();
		~MyTicSystem();
		map<string, User::BaseUser*> getUsers();
		map<string, Station*> getStations();
		map<string, Pass::TravelPass*> getPasses();
		User::BaseUser* getUser(const string& id);
		Station* getStation(const string& id);
		Pass::TravelPass* getPass(const string& id);
		void clearUsers();
		void clearStations();
		void clearPasses();
		bool loadStationsFromFile(const string& filename);
		bool loadUsersFromFile(const string& filename);
		bool loadZonePricesFromFile(const string& filename);
		Station* stationFromString(const string& data);
		User::BaseUser* userFromString(const string& data);
		Pass::TravelPass* zoneFromString(const string& data);
		void saveUsersToFile(const string& filename);
		void saveZonesToFile(const string& filename);
		UserType userStringToType(const string& data);
		string userTypeToString(User::BaseUser* user);
		size_t getLongestUserIdLength();
		size_t getLongestStationIdLength();
		static string prepareLengthAsKey(const string& length);
		static string prepareZoneAsKey(const string& zone);
		void addJourney(User::BaseUser* user, Pass::Journey* journey);
		void addPass(User::BaseUser* user, Pass::TravelPass* pass, Pass::Journey* journey);
		void upgradePass(User::BaseUser* user, Pass::TravelPass* pass, Pass::Journey* journey, int required, int hours);
		void transferJourneys(Pass::TravelPass *fromPass, Pass::TravelPass *toPass);
		void incrementStations(Pass::Journey *journey);
		Pass::TravelPass *createRequiredPass(User::BaseUser* user, Pass::Journey *journey, int required, int hours);

		template <class T, class T2>
		void upgradeTravelPass(User::BaseUser* user, T oldPass, T2 newPass, Pass::Journey* journey){

//			Pass::TwoHoursZone1 *thZone1 = dynamic_cast<Pass::TwoHoursZone1*>(passes.at("2HourZone1"));
//			Pass::TwoHoursZone1And2 *thZone12 = dynamic_cast<Pass::TwoHoursZone1And2*>(passes.at("2HourZone12"));
//			Pass::AllDayZone1 *adZone1 = dynamic_cast<Pass::AllDayZone1*>(passes.at("AllDayZone1"));
//			Pass::AllDayZone1 *adZone12 = dynamic_cast<Pass::AllDayZone1*>(passes.at("AllDayZone12"));
//			vector<TravelPass*> purchases = user->getTic()->getPurchases();
//			float cost = user->getTic()->getRealAmount(journey->getDay(), adZone1->getCost()) - user->getTic()->getPurchaseTotal(journey->getDay());
//
//			if (cost > 0 && user->getTic()->getCredit() < cost){
//				// TODO: throw exception
//				cerr << user->getId() << "does not have enough credit to buy a " << adZone1->getLength() << " pass." << endl;
//				return;
//			}
//
//			//Pass::AllDayZone1 *adz1 = new Pass::AllDayZone1(adZone1->getLength(), adZone1->getZones(), user->getTic()->getRealAmount(journey->getDay(), adZone1->getCost()));
//			//Pass::AllDayZone1 *adz1 = new Pass::AllDayZone1(adZone1->getLength(), adZone1->getZones(), user->getTic()->getRealAmount(journey->getDay(), cost));
//			Pass::TwoHoursZone1* zone = NULL;
//			vector<vector<TravelPass*>::iterator> temp;
//
//			// go back and look for all the 2 hour passes for that day, and grab the journeys from them
//			for (vector<TravelPass*>::iterator it = purchases.begin(); it != purchases.end(); ++it){
//				zone = dynamic_cast<Pass::TwoHoursZone1*>((*it));
//				if (zone != NULL)
//					transferJourneys((*it), adz1);
//			}
//
//			adz1->addJourney(journey);
//			//refund = user->getTic()->getPurchaseTotal(journey->getDay()) - user->getTic()->getRealAmount(journey->getDay(), adZone1->getCost());
//
//			//if (refund > 0)
//				//user->getTic()->addCredit(refund);
//			//else
//				//adz1->setCost(-refund);
//			if (cost < 0)
//				user->getTic()->addCredit(-cost);
//
//			user->getTic()->buyPass(adz1, journey->getDay());
//			incrementStations(journey);

		}

	};

}

#endif /* MYTICSYSTEM_H_ */
