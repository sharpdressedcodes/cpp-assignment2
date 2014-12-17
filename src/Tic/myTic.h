/****************************************************************************
* CPT 323 - Object Oriented Programming in C++
* Study Period 3 2014 Assignment 2 - "MelbourneConnect - RMIT" Ticketing System
* Full Name        : Greg Kappatos
* Student Number   : 3460969
* Course Code      : CPT323
* Program Code     : ?
* Start up code provided by Robert T.McQuillan
****************************************************************************/

#ifndef __MYTIC_H__
#define __MYTIC_H__

#include "../Pass/travelPass.h"
#include "../Pass/twoHoursZone1.h"
#include "../Pass/twoHoursZone1And2.h"
#include "../Pass/allDayZone1.h"
#include "../Pass/allDayZone1And2.h"
#include "../Pass/weekly.h"
#include "../System/dateTime.h"
#include <vector>
using std::vector;
using Pass::TravelPass;

namespace Tic {

    class MyTic {

    protected:

      float credit;
      float limit;
      unsigned int maxPasses;
      vector<Pass::TravelPass*> purchases;
      vector<string> freeDays;

    public:

      static float MAX_LIMIT;
      static unsigned int AMOUNT_DIVISOR;

      MyTic();
      MyTic(int maxPasses_);
      MyTic(float theCredit,
              float theLimit, int maxPasses_,
              vector<string> freeDays = vector<string>());
      virtual ~MyTic() ;
      virtual void input();   // Data input for a MyTic object
      virtual void print();  // Data output for a MyTic object

      virtual float getCredit() const;   //Note the use of const
      virtual float getLimit() const;

      virtual unsigned int getMaxPasses() const;
      virtual vector<string> getFreeDays() const;
      virtual void setMaxPasses(unsigned int newValue);
      virtual void setFreeDays(vector<string> newValue);

      virtual bool isFreeDay(const string& day);
      virtual float getRealAmount(const string& day, const float amount) = 0;
      virtual bool canAfford(const string& day, const float amount);
      virtual bool addCredit(const float amount);
      virtual bool buyPass(Pass::TravelPass* pass, const string& day);
      virtual void clearPurchases();
      virtual unsigned int getPurchaseCount() const;
      virtual vector<Pass::TravelPass*> getPurchases() const;
      virtual float getPurchaseTotal(string day = string()) const;
      virtual float getPurchaseTotalForWeek(const string& endDate) const;
      virtual void removePurchases(const string& day);

      virtual string toString() const = 0;

    };

}

#endif
