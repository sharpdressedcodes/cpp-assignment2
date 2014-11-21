
#include "myTicSystem.h"

namespace System {

const string MyTicSystem::USER_FILE_FLAG = "#users";
const string MyTicSystem::ZONE_FILE_FLAG = "#prices";
const string MyTicSystem::COMMENT_FILE_FLAG = "#";
const string MyTicSystem::FILE_DATA_DELIM = ":";
const unsigned int MyTicSystem::MAX_TRAVELPASSES = 100;

MyTicSystem::MyTicSystem(){}

MyTicSystem::~MyTicSystem(){

	Utility::deleteObjectMap(this->users);
	Utility::deleteObjectMap(this->stations);
	Utility::deleteObjectMap(this->passes);

}

map<string, User::BaseUser*> MyTicSystem::getUsers(){
	return this->users;
}

map<string, Station*> MyTicSystem::getStations(){
	return this->stations;
}

map<string, Pass::TravelPass*> MyTicSystem::getPasses(){
	return this->passes;
}

User::BaseUser* MyTicSystem::getUser(const string& id){
	return this->users.count(id) == 0 ? NULL : this->users[id];
}

Station* MyTicSystem::getStation(const string& id){
	return this->stations.count(id) == 0 ? NULL : this->stations[id];
}

Pass::TravelPass* MyTicSystem::getPass(const string& id){
	return this->passes.count(id) == 0 ? NULL : this->passes[id];
}

void MyTicSystem::clearUsers(){

	Utility::deleteObjectMap(this->users);
	this->users.clear();

}

void MyTicSystem::clearStations(){

	Utility::deleteObjectMap(this->stations);
	this->stations.clear();

}

void MyTicSystem::clearPasses(){

	Utility::deleteObjectMap(this->passes);
	this->passes.clear();

}

bool MyTicSystem::loadStationsFromFile(const string& filename){

	ifstream fs;

	clearStations();

	if (Utility::fileExists(filename)){

		fs.open(filename.c_str());

		while (!fs.eof()){
			string line;
			getline(fs, line);
			line = Utility::trim(line, "\r");
			line = Utility::trim(line, " ");
			Station *station = stationFromString(line);
			if (station != NULL){
				if (this->stations.count(station->getName()) > 0){
					// TODO: error: dont allow duplicates
					fs.close();
					cout << station->getName() << " already exists\n";
					return false;
				}
				this->stations[station->getName()] = station;
			}
		}

		fs.close();

	}

	return this->stations.size() > 0;
}

bool MyTicSystem::loadUsersFromFile(const string& filename){

	bool parsing = false;
	ifstream fs;

	clearUsers();

	if (Utility::fileExists(filename)){

		fs.open(filename.c_str());

		while (!fs.eof()){

			string line;
			getline(fs, line);
			line = Utility::trim(line, "\r");
			line = Utility::trim(line, " ");

			// Only grab the parts we are interested in.
			if (Utility::startsWith(line, USER_FILE_FLAG)){
				parsing = true;
				continue;
			} else if(Utility::startsWith(line, ZONE_FILE_FLAG)){
				parsing = false;
				continue;
			} else if (Utility::startsWith(line, COMMENT_FILE_FLAG)){
				continue;
			}

			if (parsing){
				User::BaseUser* user = userFromString(line);
				if (user != NULL){
					if (this->users.count(user->getId()) > 0){
						// TODO: error: dont allow duplicates
						fs.close();
						cerr << user->getId() << " already exists\n";
						return false;
					}
					this->users[user->getId()] = user;
				}
			}

		}

		fs.close();

	}

	return this->users.size() > 0;

}

bool MyTicSystem::loadZonePricesFromFile(const string& filename){

	bool parsing = false;
	ifstream fs;

	clearPasses();

	if (Utility::fileExists(filename)){

		fs.open(filename.c_str());

		while (!fs.eof()){

			string line;
			getline(fs, line);
			line = Utility::trim(line, "\r");
			line = Utility::trim(line, " ");

			// Only grab the parts we are interested in.
			if (Utility::startsWith(line, ZONE_FILE_FLAG)){
				parsing = true;
				continue;
			} else if(Utility::startsWith(line, USER_FILE_FLAG)){
				parsing = false;
				continue;
			} else if (Utility::startsWith(line, COMMENT_FILE_FLAG)){
				continue;
			}

			if (parsing){
				Pass::TravelPass* pass = zoneFromString(line);
				if (pass != NULL){
					if (this->passes.count(pass->toString()) > 0){
						// TODO: error: dont allow duplicates
						fs.close();
						cerr << pass->toString() << " already exists\n";
						return false;
					}
					stringstream ss;
					ss << prepareLengthAsKey(pass->getLength()) << prepareZoneAsKey(pass->getZones());
					this->passes[ss.str()] = pass;
				}
			}

		}

		fs.close();

	}

	return this->passes.size() > 0;

}

Station* MyTicSystem::stationFromString(const string& data) {

	// TODO: throw exception InvalidFileFormat(filename)
	if (data.find(FILE_DATA_DELIM) == string::npos)
		return NULL;

	vector<string> arr = Utility::explode(data, FILE_DATA_DELIM);

	if (arr.size() != 2)
		return NULL;
	else if (arr.at(1).length() != 1 || !Utility::isNumeric(arr.at(1)))
		return NULL;

	return new Station(arr.at(0), Utility::stringToInt(arr.at(1)));

}

User::BaseUser* MyTicSystem::userFromString(const string& data){

	// TODO: throw exception InvalidFileFormat(filename)
	if (data.find(FILE_DATA_DELIM) == string::npos)
		return NULL;

	vector<string> arr = Utility::explode(data, FILE_DATA_DELIM);

	if (arr.size() != 5)
		return NULL;
	else if (!Utility::isNumeric(arr.at(4), true))
		return NULL;

	float credit = Utility::stringToFloat(arr.at(4));

	switch (userStringToType(arr.at(1))){
	case Senior:
		return new User::Senior(arr.at(0), arr.at(2), arr.at(3), credit);
	case Adult:
		return new User::Adult(arr.at(0), arr.at(2), arr.at(3), credit);
	case Junior:
		return new User::Junior(arr.at(1), arr.at(2), arr.at(3), credit);
	default:
		return NULL;
	}

}

Pass::TravelPass* MyTicSystem::zoneFromString(const string& data){

	// TODO: throw exception InvalidFileFormat(filename)
	if (data.find(FILE_DATA_DELIM) == string::npos)
		return NULL;

	vector<string> arr = Utility::explode(data, FILE_DATA_DELIM);

	if (arr.size() != 3)
		return NULL;
	else if (!Utility::isNumeric(arr.at(2), true))
		return NULL;

	Pass::TravelPass* pass = NULL;
	float cost = Utility::stringToFloat(arr.at(2));

	if (arr.at(0).compare("2Hour") == 0 && arr.at(1).compare("Zone1") == 0){
		pass = new Pass::TwoHoursZone1(cost);
	} else if (arr.at(0).compare("2Hour") == 0 && arr.at(1).compare("Zone12") == 0){
		pass = new Pass::TwoHoursZone1And2(cost);
	} else if (arr.at(0).compare("AllDay") == 0 && arr.at(1).compare("Zone1") == 0){
		pass = new Pass::AllDayZone1(cost);
	} else if (arr.at(0).compare("AllDay") == 0 && arr.at(1).compare("Zone12") == 0){
		pass = new Pass::AllDayZone1And2(cost);
	}

	return pass;


}

void MyTicSystem::saveUsersToFile(const string& filename){

	stringstream ss;
	vector<string> lines;

	lines.push_back(USER_FILE_FLAG);

	for (map<string, User::BaseUser*>::const_iterator it = this->users.begin(); it != this->users.end(); ++it){
		vector<string> arr;
		arr.push_back(it->second->getId());
		arr.push_back(userTypeToString(it->second));
		arr.push_back(it->second->getName());
		arr.push_back(it->second->getEmail());
		arr.push_back(Utility::floatToString(it->second->getTic()->getCredit(), 2));
		lines.push_back(Utility::implode(arr, FILE_DATA_DELIM));
	}

	ss << Utility::implode(lines, "\n") << endl;

	Utility::saveFile(filename, ss.str(), false);

}

void MyTicSystem::saveZonesToFile(const string& filename){

	stringstream ss;
	vector<string> lines;

	lines.push_back(ZONE_FILE_FLAG);

	for (map<string, Pass::TravelPass*>::const_iterator it = this->passes.begin(); it != this->passes.end(); ++it){
		vector<string> arr;
		arr.push_back(prepareLengthAsKey(it->second->getLength()));
		arr.push_back(prepareZoneAsKey(it->second->getZones()));
		arr.push_back(Utility::floatToString(it->second->getCost(), 2));
		lines.push_back(Utility::implode(arr, FILE_DATA_DELIM));
	}

	ss << Utility::implode(lines, "\n") << endl;

	Utility::saveFile(filename, ss.str(), true);

}

UserType MyTicSystem::userStringToType(const string& data){

	if (data.compare("senior") == 0)
		return Senior;
	else if (data.compare("adult") == 0)
		return Adult;
	else //if (data.compare("junior") == 0)
		return Junior;

}

string MyTicSystem::userTypeToString(User::BaseUser* user){

	if (dynamic_cast<User::Senior*>(user) != NULL)
		return "senior";
	else if (dynamic_cast<User::Adult*>(user) != NULL)
		return "adult";
	else //if (dynamic_cast<User::Junior*>(user) != NULL)
		return "junior";

}

size_t MyTicSystem::getLongestUserIdLength(){

	size_t len = 0;

	for (map<string, User::BaseUser*>::const_iterator it = users.begin(); it != users.end(); ++it)
		if (it->second->getId().length() > len)
			len = it->second->getId().length();

	return len;

}

size_t MyTicSystem::getLongestStationIdLength(){

	size_t len = 0;

	for (map<string, Station*>::const_iterator it = stations.begin(); it != stations.end(); ++it)
		if (it->second->getName().length() > len)
			len = it->second->getName().length();

	return len;

}

string MyTicSystem::prepareLengthAsKey(const string& length){

	string result = Utility::replace(length, " ");

	result = Utility::replace(result, "s");

	return result;

}

string MyTicSystem::prepareZoneAsKey(const string& zone){

	string result = Utility::replace(zone, "Zones ", "Zone");

	result = Utility::replace(result, " and ");
	result = Utility::replace(result, " ");

	return result;

}

void MyTicSystem::addJourney(User::BaseUser* user, Pass::Journey* journey){

	vector<TravelPass*> purchases = user->getTic()->getPurchases();
	TravelPass *pass1 = NULL;

	if (purchases.size() > 0){
		pass1 = purchases.at(purchases.size() - 1);
		if (pass1 && pass1->canAddJourney(journey)){
			pass1->addJourney(journey);
			incrementStations(journey);
			cout << "Current " << pass1->getLength() << " Travel Pass still valid" << endl;
			return;
		}
	}

	//Pass::TwoHoursZone1 *thZone1 = dynamic_cast<Pass::TwoHoursZone1*>(passes.at("2HourZone1"));
	//Pass::TwoHoursZone1And2 *thZone12 = dynamic_cast<Pass::TwoHoursZone1And2*>(passes.at("2HourZone12"));
	Pass::AllDayZone1 *adZone1 = dynamic_cast<Pass::AllDayZone1*>(passes.at("AllDayZone1"));
	Pass::AllDayZone1And2 *adZone12 = dynamic_cast<Pass::AllDayZone1And2*>(passes.at("AllDayZone12"));

	int required = journey->getHighestZone();
	Pass::TravelPass* currentZone = pass1;
	Pass::TravelPass* requiredZone = NULL;
	string travelTime = DateTime::subtractTime(journey->getDepartureTime(), journey->getArrivalTime());
	int hours = Utility::stringToInt(travelTime.substr(0, 2));
	string totalTime;
	int totalHours = hours;

	if (currentZone != NULL){
		totalTime = DateTime::subtractTime(currentZone->getStartTime(), journey->getArrivalTime());
		totalHours = Utility::stringToInt(totalTime.substr(0, 2));
	}

	requiredZone = createRequiredPass(user, journey, required, totalHours);

	if (currentZone == NULL){

		// stage 1
		// either TwoHourZone1 or TwoHourZone12, unless the travel time is more than 2 hours,
		//then either an AllDayZone1 or AllDayZone12 is needed

		cout << "stage 1" << endl;
		addPass(user, requiredZone, journey);

	} else {

		// stage 2 and onwards

		// At this stage, a new pass is needed.
		// A previous pass has been purchased, but cannot hold this new journey on it.

		stringstream ss;
		string key;

		ss << currentZone->getLength() << currentZone->getZones();
		key = ss.str();
		bool upgrade = false;

		if (key.compare("2 HoursZone 1") == 0){
			//upgrade = hours > 2;// && required == 2;
			//upgrade = hours > 2 || required == 2;
			upgrade = totalHours > 2 || required == 2;
			cout << "upgrade1=" << upgrade << endl;
			if (!upgrade){
				upgrade = user->getTic()->getPurchaseTotal(journey->getDay()) + user->getTic()->getRealAmount(journey->getDay(), requiredZone->getCost()) >=
						(user->getTic()->getRealAmount(journey->getDay(), required == 2 ? adZone12->getCost() : adZone1->getCost()));
			}
		} else if (key.compare("2 HoursZones 1 and 2") == 0){
			//upgrade = hours > 2;
			upgrade = totalHours > 2;
			//cout << "upgrade1=" << upgrade << endl;
			if (!upgrade){
				//float aa = user->getTic()->getPurchaseTotal(journey->getDay());// + user->getTic()->getRealAmount(journey->getDay(), requiredZone->getCost());
				//float bb = user->getTic()->getRealAmount(journey->getDay(), requiredZone->getCost());
				//float cc = user->getTic()->getRealAmount(journey->getDay(), adZone12->getCost());
				//cout << "aa=" << aa << " bb=" << bb << " cc=" << cc << " required=" << required << " hours=" << hours << " traveltime=" << travelTime << " requiredzone=" << requiredZone->toString() << endl;
				upgrade = user->getTic()->getPurchaseTotal(journey->getDay()) + user->getTic()->getRealAmount(journey->getDay(), requiredZone->getCost()) >=
						user->getTic()->getRealAmount(journey->getDay(), adZone12->getCost());
			}
		} else if (key.compare("All DayZone 1") == 0){
			upgrade = required == 2;
		} else if (key.compare("All DayZones 1 and 2") == 0){
			upgrade = false;
		}

		if (upgrade){
			upgradePass(user, requiredZone, journey, required, totalHours);
		} else {
			addPass(user, requiredZone, journey);
		}

	}

}

void MyTicSystem::addPass(User::BaseUser* user, Pass::TravelPass* pass, Pass::Journey* journey){

	if (!user->getTic()->canAfford(journey->getDay(), pass->getCost())){
		// TODO: throw exception
		cerr << user->getId() << "does not have enough credit to buy a " << pass->getLength() << pass->getZones() << " pass." << endl;
		delete pass;
		delete journey;
		return;
	}

	user->getTic()->buyPass(pass, journey->getDay());
	pass->addJourney(journey);
	incrementStations(journey);

	bool consession = dynamic_cast<Tic::ConsessionTic*>(user->getTic()) != NULL;
	cout << pass->getLength() << " " << pass->getZones() << (consession ? " (Consession)" : "") << " Pass purchased for " << user->getId() << " for $" << Utility::floatToString(pass->getCost(), 2) << endl;

	if (pass->getLength().find("AllDay") != string::npos)
		cout << "Valid until midnight" << endl;
	else
		cout << "Valid until " << DateTime::addTime(journey->getDepartureTime(), "0200") << endl;

}

void MyTicSystem::upgradePass(User::BaseUser* user, Pass::TravelPass* pass, Pass::Journey* journey, int required, int hours){

	vector<TravelPass*> purchases = user->getTic()->getPurchases();
	float cost = pass->getCost() - user->getTic()->getPurchaseTotal(journey->getDay());
	pass->setCost(cost);

	if (cost > 0 && user->getTic()->getCredit() < cost){
		cerr << user->getId() << "does not have enough credit to buy a " << pass->getLength() << " pass." << endl;
		delete pass;
		delete journey;
		return;
	}

	Pass::TravelPass* zone = NULL;
	vector<vector<TravelPass*>::iterator> temp;

	// go back and look for all the 2 hour passes for that day, and grab the journeys from them
	for (vector<TravelPass*>::iterator it = purchases.begin(); it != purchases.end(); ++it){
		zone = dynamic_cast<Pass::TwoHoursZone1*>((*it));
		if (zone == NULL)
			zone = dynamic_cast<Pass::TwoHoursZone1And2*>((*it));
		// TODO: what about the rest? (if weekly passes)
		if (zone != NULL)
			transferJourneys((*it), pass);
	}

	pass->addJourney(journey);
	user->getTic()->buyPass(pass, journey->getDay());
	incrementStations(journey);
	upgradeTravelPass(user, zone, pass, journey);

	cout << zone->getLength() << " Travel Pass upgraded to " << pass->getLength() << " Pass for " << user->getId() << " for $" << Utility::floatToString(cost, 2) << endl;

}

void MyTicSystem::transferJourneys(Pass::TravelPass *fromPass, Pass::TravelPass *toPass){

	vector<Pass::Journey*> j = fromPass->getJourneys();

	for (size_t i = 0, i_ = j.size(); i < i_; ++i){
		toPass->addJourney(j[i]);
		fromPass->removeJourney(j[i]);
	}

}

void MyTicSystem::incrementStations(Pass::Journey *journey){

	journey->getFromStation()->incrementStartedJourneys();
	journey->getToStation()->incrementFinishedJourneys();

}

Pass::TravelPass *MyTicSystem::createRequiredPass(User::BaseUser* user, Pass::Journey *journey, int required, int hours){

	Pass::TravelPass * requiredZone = NULL;
	Pass::TwoHoursZone1 *thZone1 = dynamic_cast<Pass::TwoHoursZone1*>(passes.at("2HourZone1"));
	Pass::TwoHoursZone1And2 *thZone12 = dynamic_cast<Pass::TwoHoursZone1And2*>(passes.at("2HourZone12"));
	Pass::AllDayZone1 *adZone1 = dynamic_cast<Pass::AllDayZone1*>(passes.at("AllDayZone1"));
	Pass::AllDayZone1And2 *adZone12 = dynamic_cast<Pass::AllDayZone1And2*>(passes.at("AllDayZone12"));

	if (hours < 2){
		if (required < 2){
			requiredZone = new Pass::TwoHoursZone1(thZone1->getLength(), thZone1->getZones(), user->getTic()->getRealAmount(journey->getDay(), thZone1->getCost()));
		} else {
			requiredZone = new Pass::TwoHoursZone1And2(thZone12->getLength(), thZone12->getZones(), user->getTic()->getRealAmount(journey->getDay(), thZone12->getCost()));
		}
	} else {
		if (required < 2){
			requiredZone = new Pass::AllDayZone1(adZone1->getLength(), adZone1->getZones(), user->getTic()->getRealAmount(journey->getDay(), adZone1->getCost()));
		} else {
			requiredZone = new Pass::AllDayZone1And2(adZone12->getLength(), adZone12->getZones(), user->getTic()->getRealAmount(journey->getDay(), adZone12->getCost()));
		}
	}

	return requiredZone;

}

}
