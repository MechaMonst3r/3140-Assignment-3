// Name: Lukas Bowden
// Student Number: T00040951
// Date: 2020-10-09
// Description: Header file that defines the Employee Class
#include <string>
#include "Date.h"
using namespace std;
#ifndef EMPLOYEE_DEF
#define EMPLOYEE_DEF

class Employee
{
 private:
   string name;
   int age;
   string position;
   Date hired_date;
   double salary_rate;

 public:
    Employee();
    Employee(string name1, int age1, string position1, Date date1, double salary1);
    Employee(Employee& employee1);
    ~Employee();
    int getHiredDays();
    int getWorkingDays();
    double getAccumulatedSalary();
    string getName();
    int getAge();
    string getPosition();
    Date getHireDate();
    double getSalaryRate();
    void setName(string name1);
    void setAge(int age1);
    void setPosition(string position1);
    void setHireDate(Date date1);
    void setSalaryRate(double salary1);
    string getEmployee();
};

#endif