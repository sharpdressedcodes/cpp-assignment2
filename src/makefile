#****************************************************************************
# CPT 323 - Object Oriented Programming in C++
# Study Period 3 2014 Assignment 1 - "MelbourneConnect - RMIT" Ticketing System
# Full Name        : Greg Kappatos
# Student Number   : 3460969
# Course Code      : CPT323
# Program Code     : ?
# Start up code provided by Robert T.McQuillan
#****************************************************************************

RM		= rm -f
CC 		= g++
FLAGS 	= -Wall -pedantic
EXE		= mytic
OBJS	= testTravelPass.o baseException.o insufficientCredit.o invalidData.o invalidFileFormat.o passExists.o stationExists.o userIdExists.o allDayZone1.o allDayZone1And2.o journey.o travelPass.o twoHoursZone1.o twoHoursZone1And2.o weekly.o dateTime.o myTicSystem.o station.o utility.o consessionTic.o fullMyTic.o juniorMyTic.o myTic.o seniorMyTic.o baseUI.o console.o adult.o baseUser.o junior.o senior.o emailAddress.o inputData.o


$(EXE): $(OBJS)
	@echo 'Building $(EXE)'
	$(CC) -o $(EXE) $(OBJS)
	@echo 'Successfully built $(EXE)'
	@echo ' '
	
	
# Driver

testTravelPass.o: ./Driver/testTravelPass.cpp ./Driver/testTravelPass.h
	@echo 'Compiling testTravelPass.o'
	$(CC) -c $(FLAGS) ./Driver/testTravelPass.cpp
	@echo 'Successfully compiled testTravelPass.o'
	@echo ' '


# Exception

baseException.o: ./Exception/baseException.cpp ./Exception/baseException.h
	@echo 'Compiling baseException.o'
	$(CC) -c $(FLAGS) ./Exception/baseException.cpp
	@echo 'Successfully compiled baseException.o'
	@echo ' '
	
insufficientCredit.o: ./Exception/insufficientCredit.cpp ./Exception/insufficientCredit.h
	@echo 'Compiling insufficientCredit.o'
	$(CC) -c $(FLAGS) ./Exception/insufficientCredit.cpp
	@echo 'Successfully compiled insufficientCredit.o'
	@echo ' '	
	
invalidData.o: ./Exception/invalidData.cpp ./Exception/invalidData.h
	@echo 'Compiling invalidData.o'
	$(CC) -c $(FLAGS) ./Exception/invalidData.cpp
	@echo 'Successfully compiled invalidData.o'
	@echo ' '	
	
invalidFileFormat.o: ./Exception/invalidFileFormat.cpp ./Exception/invalidFileFormat.h
	@echo 'Compiling invalidFileFormat.o'
	$(CC) -c $(FLAGS) ./Exception/invalidFileFormat.cpp
	@echo 'Successfully compiled invalidFileFormat.o'
	@echo ' '	
	
passExists.o: ./Exception/passExists.cpp ./Exception/passExists.h
	@echo 'Compiling passExists.o'
	$(CC) -c $(FLAGS) ./Exception/passExists.cpp
	@echo 'Successfully compiled passExists.o'
	@echo ' '	
	
stationExists.o: ./Exception/stationExists.cpp ./Exception/stationExists.h
	@echo 'Compiling stationExists.o'
	$(CC) -c $(FLAGS) ./Exception/stationExists.cpp
	@echo 'Successfully compiled stationExists.o'
	@echo ' '	
	
userIdExists.o: ./Exception/userIdExists.cpp ./Exception/userIdExists.h
	@echo 'Compiling userIdExists.o'
	$(CC) -c $(FLAGS) ./Exception/userIdExists.cpp
	@echo 'Successfully compiled userIdExists.o'
	@echo ' '		
	
# Pass
	
allDayZone1.o: ./Pass/allDayZone1.cpp ./Pass/allDayZone1.h
	@echo 'Compiling allDayZone1.o'
	$(CC) -c $(FLAGS) ./Pass/allDayZone1.cpp
	@echo 'Successfully compiled allDayZone1.o'
	@echo ' '
	
allDayZone1And2.o: ./Pass/allDayZone1And2.cpp ./Pass/allDayZone1And2.h
	@echo 'Compiling allDayZone1And2.o'
	$(CC) -c $(FLAGS) ./Pass/allDayZone1And2.cpp
	@echo 'Successfully compiled allDayZone1And2.o'
	@echo ' '
	
journey.o: ./Pass/journey.cpp ./Pass/journey.h
	@echo 'Compiling journey.o'
	$(CC) -c $(FLAGS) ./Pass/journey.cpp
	@echo 'Successfully compiled journey.o'
	@echo ' '
	
travelPass.o: ./Pass/travelPass.cpp ./Pass/travelPass.h
	@echo 'Compiling travelPass.o'
	$(CC) -c $(FLAGS) ./Pass/travelPass.cpp
	@echo 'Successfully compiled travelPass.o'
	@echo ' '
	
twoHoursZone1.o: ./Pass/twoHoursZone1.cpp ./Pass/twoHoursZone1.h
	@echo 'Compiling twoHoursZone1.o'
	$(CC) -c $(FLAGS) ./Pass/twoHoursZone1.cpp
	@echo 'Successfully compiled twoHoursZone1.o'
	@echo ' '
	
twoHoursZone1And2.o: ./Pass/twoHoursZone1And2.cpp ./Pass/twoHoursZone1And2.h
	@echo 'Compiling twoHoursZone1And2.o'
	$(CC) -c $(FLAGS) ./Pass/twoHoursZone1And2.cpp
	@echo 'Successfully compiled twoHoursZone1And2.o'
	@echo ' '
	
weekly.o: ./Pass/weekly.cpp ./Pass/weekly.h
	@echo 'Compiling weekly.o'
	$(CC) -c $(FLAGS) ./Pass/weekly.cpp
	@echo 'Successfully compiled weekly.o'
	@echo ' '	
	
	
# System

dateTime.o: ./System/dateTime.cpp ./System/dateTime.h
	@echo 'Compiling dateTime.o'
	$(CC) -c $(FLAGS) ./System/dateTime.cpp
	@echo 'Successfully compiled dateTime.o'
	@echo ' '
	
myTicSystem.o: ./System/myTicSystem.cpp ./System/myTicSystem.h
	@echo 'Compiling myTicSystem.o'
	$(CC) -c $(FLAGS) ./System/myTicSystem.cpp
	@echo 'Successfully compiled myTicSystem.o'
	@echo ' '
	
station.o: ./System/station.cpp ./System/station.h
	@echo 'Compiling station.o'
	$(CC) -c $(FLAGS) ./System/station.cpp
	@echo 'Successfully compiled station.o'
	@echo ' '
	
#storage.o: ./System/storage.h
#	@echo 'Compiling storage.o'
#	$(CC) -c $(FLAGS) ./System/storage.h
#	@echo 'Successfully compiled storage.o'
#	@echo ' '
				
utility.o: ./System/utility.cpp ./System/utility.h
	@echo 'Compiling utility.o'
	$(CC) -c $(FLAGS) ./System/utility.cpp
	@echo 'Successfully compiled utility.o'
	@echo ' '


# Tic

consessionTic.o: ./Tic/consessionTic.cpp ./Tic/consessionTic.h
	@echo 'Compiling consessionTic.o'
	$(CC) -c $(FLAGS) ./Tic/consessionTic.cpp
	@echo 'Successfully compiled consessionTic.o'
	@echo ' '

fullMyTic.o: ./Tic/fullMyTic.cpp ./Tic/fullMyTic.h
	@echo 'Compiling fullMyTic.o'
	$(CC) -c $(FLAGS) ./Tic/fullMyTic.cpp
	@echo 'Successfully compiled fullMyTic.o'
	@echo ' '

juniorMyTic.o: ./Tic/juniorMyTic.cpp ./Tic/juniorMyTic.h
	@echo 'Compiling juniorMyTic.o'
	$(CC) -c $(FLAGS) ./Tic/juniorMyTic.cpp
	@echo 'Successfully compiled juniorMyTic.o'
	@echo ' '

myTic.o: ./Tic/myTic.cpp ./Tic/myTic.h
	@echo 'Compiling myTic.o'
	$(CC) -c $(FLAGS) ./Tic/myTic.cpp
	@echo 'Successfully compiled myTic.o'
	@echo ' '

seniorMyTic.o: ./Tic/seniorMyTic.cpp ./Tic/seniorMyTic.h
	@echo 'Compiling seniorMyTic.o'
	$(CC) -c $(FLAGS) ./Tic/seniorMyTic.cpp
	@echo 'Successfully compiled seniorMyTic.o'
	@echo ' '


# Ui
	
baseUI.o: ./Ui/baseUI.cpp ./Ui/baseUI.h
	@echo 'Compiling baseUI.o'
	$(CC) -c $(FLAGS) ./Ui/baseUI.cpp
	@echo 'Successfully compiled baseUI.o'
	@echo ' '

console.o: ./Ui/console.cpp ./Ui/console.h
	@echo 'Compiling console.o'
	$(CC) -c $(FLAGS) ./Ui/console.cpp
	@echo 'Successfully compiled console.o'
	@echo ' '


# User

adult.o: ./User/adult.cpp ./User/adult.h
	@echo 'Compiling adult.o'
	$(CC) -c $(FLAGS) ./User/adult.cpp
	@echo 'Successfully compiled adult.o'
	@echo ' '

baseUser.o: ./User/baseUser.cpp ./User/baseUser.h
	@echo 'Compiling baseUser.o'
	$(CC) -c $(FLAGS) ./User/baseUser.cpp
	@echo 'Successfully compiled baseUser.o'
	@echo ' '

junior.o: ./User/junior.cpp ./User/junior.h
	@echo 'Compiling junior.o'
	$(CC) -c $(FLAGS) ./User/junior.cpp
	@echo 'Successfully compiled junior.o'
	@echo ' '

senior.o: ./User/senior.cpp ./User/senior.h
	@echo 'Compiling senior.o'
	$(CC) -c $(FLAGS) ./User/senior.cpp
	@echo 'Successfully compiled senior.o'
	@echo ' '


# Validation	
	
#baseValidator.o: ./Validation/baseValidator.h
#	@echo 'Compiling baseValidator.o'
#	$(CC) -c $(FLAGS) ./Validation/baseValidator.h
#	@echo 'Successfully compiled baseValidator.o'
#	@echo ' '

emailAddress.o: ./Validation/emailAddress.cpp ./Validation/emailAddress.h
	@echo 'Compiling emailAddress.o'
	$(CC) -c $(FLAGS) ./Validation/emailAddress.cpp
	@echo 'Successfully compiled emailAddress.o'
	@echo ' '

inputData.o: ./Validation/inputData.cpp ./Validation/inputData.h
	@echo 'Compiling inputData.o'
	$(CC) -c $(FLAGS) ./Validation/inputData.cpp
	@echo 'Successfully compiled inputData.o'
	@echo ' '
	
	
# Clean

clean:
	@echo 'Deleting $(OBJS)'
	$(RM) $(OBJS)
	@echo ' '
	@echo 'Deleting $(EXE)'
	$(RM) $(EXE)
	@echo ' '
	@echo 'Clean done'
	@echo ' '
