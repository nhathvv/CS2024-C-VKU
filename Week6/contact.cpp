#include <iostream>
#include <string>
#include "contact.h"
using namespace std;
Contact::Contact(){};
Contact::Contact(int id, string name, string phoneNumber,string gmail, string address) {
    this->id = id;
    this->name = name;
    this->phoneNumber = phoneNumber;
    this->gmail = gmail;
    this->address = address;
}
void Contact::setId(int id) {
    this->id = id;
}
void Contact::setName(string name) {
    this->name = name;
}
void Contact::setPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}
void Contact::setGmail(string gmail) {
    this->gmail = gmail;
}
void Contact::setAddress(string address) {
    this->address = address;
}

int Contact::getId() {
    return id;
}
string Contact::getName() {
    return name;
}
string Contact::getPhoneNumber() {
    return phoneNumber;
}
string Contact::getGmail() {
    return gmail;
}
string Contact::getAddress() {
    return address;
}