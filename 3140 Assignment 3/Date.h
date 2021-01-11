// Name: Lukas Bowden
// Student Number: T00040951
// Date: 2020-10-09
// Description: Header file that defines the Date Class
#include <string>
using namespace std;
#ifndef DATE_DEF
#define DATE_DEF

class Date
{
  private:
     int day;
     int month;
     int year;

  public:
     Date();
     Date(int day1, int month1, int year1);
     Date(Date &date1);
     ~Date();
     int getDay();
     int getMonth();
     int getYear();
     void setDay(int day1);
     void setMonth(int month1);
     void setYear(int year1);
     string getDate();
};

#endif
