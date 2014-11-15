
#include "myTicSystem.h"

namespace System {

const string MyTicSystem::USER_FILE_FLAG = "#users";
const string MyTicSystem::ZONE_FILE_FLAG = "#prices";
const string MyTicSystem::COMMENT_FILE_FLAG = "#";
const string MyTicSystem::FILE_DATA_DELIM = ":";

MyTicSystem::MyTicSystem(){}

MyTicSystem::~MyTicSystem(){
	// TODO: save users
	// TODO: save prices
	Utility::deleteObjectMap(this->users);
	Utility::deleteObjectMap(this->stations);
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

string MyTicSystem::getStationsFilename() const {
	return this->stationsFilename;
}

string MyTicSystem::getTicsInputFilename() const {
	return this->ticsInputFilename;
}

string MyTicSystem::getTicsOutputFilename() const {
	return this->ticsOutputFilename;
}

void MyTicSystem::setStationsFilename(string newValue){
	this->stationsFilename = newValue;
}

void MyTicSystem::setTicsInputFilename(string newValue){
	this->ticsInputFilename = newValue;
}

void MyTicSystem::setTicsOutputFilename(string newValue){
	this->ticsOutputFilename = newValue;
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

	bool result = false;
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

	return result;
}

bool MyTicSystem::loadUsersFromFile(const string& filename){

	bool result = false;
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
			} else if (line.substr(0, COMMENT_FILE_FLAG.length()) == COMMENT_FILE_FLAG){
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


	return result;

}

bool MyTicSystem::loadZonePricesFromFile(const string& filename){

	bool result = false;
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
			} else if (line.substr(0, COMMENT_FILE_FLAG.length()) == COMMENT_FILE_FLAG){
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
					this->passes[pass->toString()] = pass;
				}
			}

		}

		fs.close();

	}


	return result;

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
		arr.push_back(Utility::floatToString(it->second->getCredit(), 2));
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
		string length = Utility::replace(it->second->getLength(), " ");
		string zones = Utility::replace(it->second->getZones(), "Zones ", "Zone");
		zones = Utility::replace(zones, " and ");
		zones = Utility::replace(zones, " ");
		arr.push_back(Utility::replace(length, "s"));
		arr.push_back(zones);
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

}
