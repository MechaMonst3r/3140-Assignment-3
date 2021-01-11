// Name: Lukas Bowden
// Student Number: T00040951
// Date: 2020-10-09
// Description: Driver file that takes in a text file with data
// creates Employee Objects and Date Objects from that data, then stores it in an array.
// It then prompts the user for different interactions with the data store in the array.
#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "Employee.cpp"
#include "Employee.h"
using namespace std;

int main()
{
 //Creating temp variables and arrays to read and break down data in text file 
 Employee empArr[10];
 string tempArr[5] = {""};
 string employee;
 string tempName;
 int tempAge;
 string strTempAge;
 string tempPos;
 string tempDate;
 int tempSal;
 int days;
 int month;
 int year;
 //Variable to act as Index
 int i = 0;

 cout << "C-Brothers Employee Managment System" << "\n";
 cout << "Reading in employees.txt File....." << "\n";

 //Opens the array
 fstream newFile;
 newFile.open("employees.txt", ios :: in);
 if(newFile.is_open())
 {
   string tempStr;
   while(getline(newFile, tempStr))
   {
     //As long as there is a line to read from the file, it stores it in the temp array
     tempArr[i] = tempStr;
     //increases index to change the index of the array
     i++;
   }
 }

 //Closes the file when done
 newFile.close();


 //Gets the string stored in the first array
 employee = tempArr[0];
 //Takes a substring of the Employee strings and extras just the name in the string
 tempName = employee.substr(0, 8);

 //Gets the age number in the employee string
 strTempAge = employee.substr(10, 2);
 //Converts string to an int.
 tempAge = stoi(strTempAge);

 //Gets the position from the Employee string
 tempPos = employee.substr(14, 17);

 //Gets the date from the employee string
 tempDate = employee.substr(33, 8);

 //Gets the month from the tempDate string and converts it to int.
 month = stoi(tempDate.substr(0,1));

 //Gets the day from the tempDate string and converts to int
 days = stoi(tempDate.substr(2, 1));

 //Gets the year from the tempDate string and converts to int.
 year = stoi(tempDate.substr(4, 4));

 //Gets the Salary from the Employee string and converts to double.
 tempSal = stod(employee.substr(43, 4));

 //Uses month, days, and year variable to create a Date object
 Date date1(days, month, year);

 //Uses the temp variables and the Date object to create and Employee object
 Employee emp1(tempName, tempAge, tempPos, date1, tempSal);

 //Stores the Employee object into the first index of an Employee Array
 empArr[0] = emp1;

 //Takes the string in the second index of the temp array and stores it into the employee string.
 employee = tempArr[1];

 //Repeats the process from line 55 to line 91 until 5 Employees, Dates, and 5 indexes in the Employee Array are filled.
 tempName = employee.substr(0, 12);

 strTempAge = employee.substr(14, 2);
 tempAge = stoi(strTempAge);

 tempPos = employee.substr(18, 15);

 tempDate = employee.substr(35, 9);

 month = stoi(tempDate.substr(0,1));

 days = stoi(tempDate.substr(2, 2));

 year = stoi(tempDate.substr(5, 4));

 tempSal = stoi(employee.substr(46, 5));

 Date date2(days, month, year);
 Employee emp2(tempName, tempAge, tempPos, date2, tempSal);
 empArr[1] = emp2;

 employee = tempArr[2];
 tempName = employee.substr(0, 14);

 strTempAge = employee.substr(16, 2);
 tempAge = stoi(strTempAge);

 tempPos = employee.substr(20, 25);

 tempDate = employee.substr(47, 8);

 month = stoi(tempDate.substr(0,1));

 days = stoi(tempDate.substr(2, 1));

 year = stoi(tempDate.substr(4, 4));

 tempSal = stoi(employee.substr(57, 5));

 Date date3(days, month, year);
 Employee emp3(tempName, tempAge, tempPos, date3, tempSal);
 empArr[2] = emp3;


 employee = tempArr[3];
 tempName = employee.substr(0, 15);

 strTempAge = employee.substr(17, 2);
 tempAge = stoi(strTempAge);

 tempPos = employee.substr(21, 9);

 tempDate = employee.substr(32, 9);

 month = stoi(tempDate.substr(0,1));

 days = stoi(tempDate.substr(2, 2));

 year = stoi(tempDate.substr(5, 4));

 tempSal = stoi(employee.substr(43, 4));

 Date date4(days, month, year);
 Employee emp4(tempName, tempAge, tempPos, date4, tempSal);
 empArr[3] = emp4;


 employee = tempArr[4];
 tempName = employee.substr(0, 9);

 strTempAge = employee.substr(11, 2);
 tempAge = stoi(strTempAge);

 tempPos = employee.substr(15, 11);

 tempDate = employee.substr(28, 10);

 month = stoi(tempDate.substr(0,2));

 days = stoi(tempDate.substr(3, 2));

 year = stoi(tempDate.substr(6, 4));
 
 tempSal = stoi(employee.substr(40, 5));

 Date date5(days, month, year);
 Employee emp5(tempName, tempAge, tempPos, date5, tempSal);
 empArr[4] = emp5;

 cout << "Ready!" << "\n";

 //Creating input variables
 int input1;
 char input2;
 string input3;
 int input4;

 //Asking user for input
 cout << "Choose one of the following options: " << "\n";
 cout << "1. Print all employees information." << "\n";
 cout << "2. Print all employees names." << "\n";
 cout << "3. Find employee with the highest salary rate." << "\n";
 cout << "4. Find employee with the lowest salary rate." << "\n";
 cout << "5. Search an employee." << "\n";
 cout << "6. Add a new employee." << "\n";
 cout << "Press 0 to quit." << "\n";
 cout << "Your choice: ";
 cin >> input1;

 //Main while loop to run the interface
 while(input1 != 0)
 {
  
  //Prints everything in empArray and all info
  if(input1 == 1)
  {
   for(int i = 0; i < 10; i++)
   {
     string tempString = empArr[i].getEmployee();
     cout << tempString << "\n" << "\n";
   }
  }
  
  //Prints all names of employee objects in empArray
  if(input1 == 2)
  {
   for(int i = 0; i < 10; i++)
   {
    string tempString2 = empArr[i].getName();
    cout << "Name: " << tempString2 << "\n"; 
   }
  }
  
  //Find the employee with the largest salary
  if(input1 == 3)
  {
   //Stores salary of first employee in empArr
   double largestSal = empArr[0].getSalaryRate();
   //Scans array and checks against first employees salary
   for(int i = 0; i < 10; i++)
   { 
    //If an employees salary is larger then whats stored in the current largesSal variable, it swaps. 
    if(empArr[i].getSalaryRate() > largestSal)
    {
      largestSal = empArr[i].getSalaryRate();
    }
   }

   //Scans through the array one more time and compares salary to the current largest salary then prints the employee out
   for(int j = 0; j < 10; j++)
   {
     if(empArr[j].getSalaryRate() == largestSal)
     {
       cout << empArr[j].getEmployee() << "\n";
     }
   }
  }

  //Finds the employee with the lowest salary
  if(input1 == 4)
  {
   double lowestSal = empArr[0].getSalaryRate();
   for(int i = 0; i < 10; i++)
   {
    if(empArr[i].getSalaryRate() < lowestSal)
    {
      lowestSal = empArr[i].getSalaryRate();
    }
   }

   for(int j = 0; j < 10; j++)
   {
     if(empArr[j].getSalaryRate() == lowestSal)
     {
       cout << empArr[j].getEmployee() << "\n";
     }
   }
  }

  //Scans through the array to compare the search name with employees. If the name is on an object, it prints the employee object.
  if(input1 == 5)
  { 
   bool isFound = false; 
   cout << "Type the employee's name: ";
   cin >> input3;
   
   int tempIndex;
   for(int i = 0; i < 10; i++)
   {
     if(empArr[i].getName() == input3)
     {
       tempIndex = i;
       cout << "Employee found!" << "\n";
       isFound = true;
       break;
     } 
   }

   //If the searched name is found, gives the user options to modify the searched employee
   if(isFound == true)
   {
    cout << empArr[tempIndex].getEmployee() << "\n" << "\n";
    cout << "Would you like to modify this employees information?(Y or N)";
    cin >> input2;

    while(input2 == 'y' || input2 == 'Y')
    {
     cout << "Which field would you like to modify?" << "\n";
     cout << "1. Name" << "\n";
     cout << "2. Age" << "\n";
     cout << "3. Position" << "\n";
     cout << "4. Hired Date" << "\n";
     cout << "5. Salary Rate" << "\n";
     cout << "Your choice: ";
     cin >> input4;

     if(input4 == 1)
     {
       cout << "New name: ";
       cin >> tempName;
       empArr[tempIndex].setName(tempName);
       cout << "The name has been changed.";
     }
     
     if(input4 == 2)
     {
       cout << "New age: ";
       cin >> tempAge;
       empArr[tempIndex].setAge(tempAge);
       cout << "The age has been changed.";
     }

     if(input4 == 3)
     {
       cout << "New position: ";
       cin >> tempPos;
       empArr[tempIndex].setPosition(tempPos);
       cout << "The position has been changed.";
     }

     if(input4 == 4)
     {
       cout << "New Date: ";
       cout << "Enter which day: ";
       cin >> days;
       cout << "Enter which month: ";
       cin >> month;
       cout << "Enter which year: ";
       cin >> year;

       Date tempDate(days, month, year);
       empArr[tempIndex].setHireDate(tempDate);
       cout << "The date has been changed.";
     }

     if(input4 == 5)
     {
       cout << "New salary rate: ";
       cin >> tempSal;
       empArr[tempIndex].setSalaryRate(tempSal);
       cout << "The salary rate has been changed.";
     }

     cout << "Would you like to change another field?(Y or N) ";
     cin >> input2;
    }//End of nested while loop
   }//End of nested if statement
  }//End of if statement

  //Creates a new employee object from scratch
  if(input1 == 6)
  {
   cout << "Enter name of new employee: ";
   cin >> tempName;
   cout << "Enter age of new employee: ";
   cin >> tempAge;
   cout << "Enter position of new employee: ";
   cin >> tempPos;
   cout << "Enter hire date of new employee: " << "\n";
   cout << "Enter which day: ";
   cin >> days;
   cout << "Enter which month: ";
   cin >> month;
   cout << "Enter which year: ";
   cin >> year;
   Date tempDate1(days, month, year);
   cout << "Enter salary rate of new employee: ";
   cin >> tempSal;
   Employee newEmployee(tempName, tempAge, tempPos, tempDate1, tempSal);
   int arrayCounter = 4;
    
   empArr[arrayCounter + 1] = newEmployee;
   arrayCounter++;

   cout << "Employee created." << "\n"; 
  }

  //Reprompts user for another entry
  cout << "Choose one of the following options: " << "\n";
  cout << "1. Print all employees information." << "\n";
  cout << "2. Print all employees names." << "\n";
  cout << "3. Find employee with the highest salary rate." << "\n";
  cout << "4. Find employee with the lowest salary rate." << "\n";
  cout << "5. Search an employee." << "\n";
  cout << "6. Add a new employee." << "\n";
  cout << "Press 0 to quit." << "\n";
  cout << "Your choice: ";
  cin >> input1;
 }//End of main while loop 
 return 0;
}//End of main
