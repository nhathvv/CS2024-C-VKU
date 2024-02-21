#include <iostream>
#include <string>
#include "Employee.h"
Employee::Employee(string name, int idNumber, string department, string position) {
    this->name = name;
    this->idNumber = idNumber;
    this->department = department;
    this->position = position;
}
Employee::Employee(string name, int idNumber) {
    this->name = name;
    this->idNumber = idNumber;
    this->department = "";
    this->position = "";
}
Employee::Employee() {
    this->name = "";
    this->idNumber = 0;
    this->department = "";
    this->position = "";
}

void Employee::setIdNumber(int idNumber){
    this->idNumber = idNumber;
}
void Employee::setName(string name){
    this->name = name;
}
void Employee::setDepartment(string department){
    this->department = department;
}
void Employee::setPosition(string position){
    this->position = position;
}
int Employee::getIdNumber() {
    return idNumber;
}
string Employee::getName() {
    return name;
}
string Employee::getDepartment() {
    return department;
}
string Employee::getPosition() {
    return position;
}