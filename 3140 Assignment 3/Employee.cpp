// Name: Lukas Bowden
// Student Number: T00040951
// Date: 2020-10-09
// Description: Implementation file for the Employee class
#include <iostream>
#include <string>
#include "Date.h"
#include "Date.cpp"
#include "Employee.h"
using namespace std;

//Default constructor
Employee :: Employee()
{
  name = "Nothing";
  age = 0;
  position = "Nothing";
  salary_rate = 0;
}

//Paramerter constructor
Employee :: Employee(string name1, int age1, string position1, Date hired, double salary1)
{
 name = name1;
 age = age1;
 position = position1;
 hired_date.setDay(hired.getDay());
 hired_date.setMonth(hired.getMonth());
 hired_date.setYear(hired.getYear());
 salary_rate = salary1;
}

//Copy constructor
Employee :: Employee(Employee& employee1)
{
 name = employee1.getName();
 age = employee1.getAge();
 position = employee1.getPosition();
 hired_date = employee1.getHireDate();
 salary_rate = employee1.getSalaryRate();
}

//Destructor
Employee :: ~Employee()
{
}

//Calculates how many days a person has been hired on
int Employee :: getHiredDays()
{
 Date tempDate;
 int totalYears = tempDate.getYear() - hired_date.getYear();
 int totalLeapYear = totalYears%4;
 int totalMonths = ((totalYears - 1) * 12) + hired_date.getMonth();
 int totalDays = (totalMonths/2 * 30) + (totalMonths/2 * 31) + totalLeapYear;

 return totalDays;
}

//Calculates how many days the employee has actually worked since theyve been hired
int Employee :: getWorkingDays()
{
 int yearsInDaysWorked = getHiredDays()/365;
 int numWeekendsInYear = 52;
 int totalDaysNotWorked = yearsInDaysWorked * numWeekendsInYear;
 int total = getHiredDays() - totalDaysNotWorked;

 return total;
}

//Gets the total amount of salary thats been earned since an employee has been hired
double Employee:: getAccumulatedSalary()
{
 double salInDay = salary_rate * 8;
 double totalSal = getWorkingDays() * salInDay;

 return totalSal;
}

//Getters
string Employee :: getName()
{
 return name;
}

int Employee :: getAge()
{
 return age;
}

string Employee :: getPosition()
{
 return position;
}

Date Employee :: getHireDate()
{
 return hired_date;
}

//Setters
double Employee :: getSalaryRate()
{
 return salary_rate;
}

void Employee :: setName(string name1)
{
 name = name1;
}

void Employee :: setAge(int age1)
{
 age = age1;
}

void Employee :: setPosition(string position1)
{
 position = position1;
}

void Employee :: setHireDate(Date date1)
{
 hired_date.setDay(date1.getDay());
 hired_date.setMonth(date1.getMonth());
 hired_date.setYear(date1.getYear());
}

void Employee :: setSalaryRate(double salary1)
{
 salary_rate = salary1;
}

//Returns all employee information
string Employee :: getEmployee()
{
  string strAge = to_string(age);
  string strDate = hired_date.getDate();
  string strSal = to_string(salary_rate);
  string strDaysHired = to_string(getHiredDays());
  string strDaysWorked = to_string(getWorkingDays());
  string strAccumSalary = to_string(getAccumulatedSalary());

  string employee = "Name: " + name + "\n" +  "Age: " + strAge + "\n" + "Position: " + position + "\n" + "Hired Date: " + strDate + "\n" + "Salary Rate: $" 
                     + strSal + "/hour" + "\n" + "Days Hired: " + strDaysHired + "\n" + "Days Working: " + strDaysWorked + "\n" + "Accumulated Salary: $" + strAccumSalary;

  return employee;                    
}    

