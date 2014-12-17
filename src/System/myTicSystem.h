/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef MYTICSYSTEM_H_
#define MYTICSYSTEM_H_

#include <map>
#include <string>
#include "../Exception/insufficientCredit.h"
#include "../Exception/invalidFileFormat.h"
#include "../Exception/passExists.h"
#include "../Exception/stationExists.h"
#include "../Exception/userIdExists.h"
#include "../Pass/journey.h"
#include "../Pass/weekly.h"
#include "../User/baseUser.h"
#include "../User/adult.h"
#include "../User/junior.h"
#include "../User/senior.h"
#include "../Validation/emailAddress.h"
#include "../Validation/inputData.h"
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
        map<string, Validation::BaseValidator<string>*> validators;
        static const string USER_FILE_FLAG;
        static const string ZONE_FILE_FLAG;
        static const string COMMENT_FILE_FLAG;

    public:
        static const string FILE_DATA_DELIM;
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
        void addPass(User::BaseUser* user,
                Pass::TravelPass* pass, Pass::Journey* journey);
        void upgradePass(User::BaseUser* user, Pass::TravelPass* pass,
                Pass::Journey* journey, int required, int hours);
        void transferJourneys(Pass::TravelPass *fromPass,
                Pass::TravelPass *toPass);
        void incrementStations(Pass::Journey *journey);
        Pass::TravelPass *createRequiredPass(User::BaseUser* user,
                Pass::Journey *journey, int required, int hours);
        void addUser(User::BaseUser* user);
        map<string, Validation::BaseValidator<string>*> getValidators();
        Validation::BaseValidator<string>* getValidator(const string& key);

    };

}

#endif /* MYTICSYSTEM_H_ */
