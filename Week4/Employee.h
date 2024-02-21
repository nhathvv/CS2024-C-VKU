#ifndef employeemanagement_employ_h
#define employeemanagement_employ_h

#include <iostream>
#include <string>
using namespace std;
class Employee {
    string name; 
    int idNumber;
    string department;
    string position;
    public :
       Employee(string name, int idNumber, string department, string position);
       Employee(string name, int idNumber);
       Employee();
       string getName();
       int getIdNumber();
       string getDepartment();
       string getPosition();
       void setName(string name);
       void setIdNumber(int idNumber);
       void setDepartment(string department);
       void setPosition(string position);
};
#endif