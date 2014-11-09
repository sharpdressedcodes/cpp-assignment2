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
OBJS 	= allDayZone1.o allDayZone1And2.o myTic.o testTravelPass.o travelPass.o twoHoursZone1.o twoHoursZone1And2.o uI.o utility.o
EXE		= mytic

$(EXE): $(OBJS)
	@echo 'Building $(EXE)'
	$(CC) -o $(EXE) $(OBJS)
	@echo 'Successfully built $(EXE)'
	@echo ' '
	
allDayZone1.o: allDayZone1.cpp allDayZone1.h
	@echo 'Compiling allDayZone1.o'
	$(CC) -c $(FLAGS) allDayZone1.cpp
	@echo 'Successfully compiled allDayZone1.o'
	@echo ' '
	
allDayZone1And2.o: allDayZone1And2.cpp allDayZone1And2.h
	@echo 'Compiling allDayZone1And2.o'
	$(CC) -c $(FLAGS) allDayZone1And2.cpp
	@echo 'Successfully compiled allDayZone1And2.o'
	@echo ' '
	
myTic.o: myTic.cpp myTic.h
	@echo 'Compiling myTic.o'
	$(CC) -c $(FLAGS) myTic.cpp
	@echo 'Successfully compiled myTic.o'
	@echo ' '
	
testTravelPass.o: testTravelPass.cpp testTravelPass.h
	@echo 'Compiling testTravelPass.o'
	$(CC) -c $(FLAGS) testTravelPass.cpp
	@echo 'Successfully compiled testTravelPass.o'
	@echo ' '
	
travelPass.o: travelPass.cpp travelPass.h
	@echo 'Compiling travelPass.o'
	$(CC) -c $(FLAGS) travelPass.cpp
	@echo 'Successfully compiled travelPass.o'
	@echo ' '
	
twoHoursZone1.o: twoHoursZone1.cpp twoHoursZone1.h
	@echo 'Compiling twoHoursZone1.o'
	$(CC) -c $(FLAGS) twoHoursZone1.cpp
	@echo 'Successfully compiled twoHoursZone1.o'
	@echo ' '
	
twoHoursZone1And2.o: twoHoursZone1And2.cpp twoHoursZone1And2.h
	@echo 'Compiling twoHoursZone1And2.o'
	$(CC) -c $(FLAGS) twoHoursZone1And2.cpp
	@echo 'Successfully compiled twoHoursZone1And2.o'
	@echo ' '
	
uI.o: uI.cpp uI.h
	@echo 'Compiling uI.o'
	$(CC) -c $(FLAGS) uI.cpp
	@echo 'Successfully compiled uI.o'
	@echo ' '
	
utility.o: utility.cpp utility.h
	@echo 'Compiling utility.o'
	$(CC) -c $(FLAGS) utility.cpp
	@echo 'Successfully compiled utility.o'
	@echo ' '
	
clean:
	@echo 'Deleting $(OBJS)'
	$(RM) $(OBJS)
	@echo ' '
	@echo 'Deleting $(EXE)'
	$(RM) $(EXE)
	@echo ' '
	@echo 'Clean done'
	@echo ' '
