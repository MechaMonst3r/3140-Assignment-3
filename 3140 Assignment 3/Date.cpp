// Name: Lukas Bowden
// Student Number: T00040951
// Date: 2020-10-09
// Description: Implementation file for the Date class
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

//Default constructor
Date :: Date()
{
 day = 9;
 month = 10;
 year = 2020;
}

//Paramerterized constructor
Date :: Date (int day1, int month1, int year1)
{
  day = day1;
  month = month1;
  year = year1;  
}

//Copy constructor
Date :: Date (Date &date1)
{
  day = date1.getDay();
  month = date1.getMonth();
  year = date1.getYear();
}

//Destructor
Date :: ~Date()
{
}

//Getters
int Date :: getDay()
{
  return day;   
}

int Date :: getMonth()
{
  return month;
}

int Date :: getYear()
{
  return year;
}

//Setters
void Date :: setDay(int day1)
{
  day = day1;
}

void Date :: setMonth(int month1)
{
 month = month1;
}

void Date :: setYear(int year1)
{
  year = year1;
}

//Returns the date
string Date :: getDate()
{
 string strDay = to_string(day);
 string strMonth = to_string(month);
 string strYear = to_string(year);
 string date = strDay + "-" +  strMonth + "-" + strYear;
 return date;
}