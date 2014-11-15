
#ifndef MYTICSYSTEM_H_
#define MYTICSYSTEM_H_

#include <map>
#include <string>
#include "../User/baseUser.h"
#include "../User/adult.h"
#include "../User/junior.h"
#include "../User/senior.h"
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
		string stationsFilename;
		string ticsInputFilename;
		string ticsOutputFilename;
		static const string USER_FILE_FLAG;
		static const string ZONE_FILE_FLAG;
		static const string COMMENT_FILE_FLAG;
		static const string FILE_DATA_DELIM;
	public:
		MyTicSystem();
		~MyTicSystem();
		map<string, User::BaseUser*> getUsers();
		map<string, Station*> getStations();
		map<string, Pass::TravelPass*> getPasses();
		User::BaseUser* getUser(const string& id);
		Station* getStation(const string& id);
		Pass::TravelPass* getPass(const string& id);
		string getStationsFilename() const;
		string getTicsInputFilename() const;
		string getTicsOutputFilename() const;
		void setStationsFilename(string newValue);
		void setTicsInputFilename(string newValue);
		void setTicsOutputFilename(string newValue);
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
	};

}

#endif /* MYTICSYSTEM_H_ */
