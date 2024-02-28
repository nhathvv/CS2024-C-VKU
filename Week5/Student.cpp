#include <iostream>
#include <string>
#include "Student.h"
using namespace std;
Student::Student() {
    this->name = "";
    this->credits = new int(0);
    this->medium_score = 0;
}
Student::Student(string name,int credits,float medium_score) {
    this->name = name;
    this->credits = new int(credits);
    this->medium_score = medium_score;
}
void Student::setCredits(int credits) {
    *this->credits = credits;
}
int Student::getCredits() {
    return *credits;
}
Student::Student(const Student& other) {
    this->name = other.name;
    *this->credits = *other.credits;
    this->medium_score = other.medium_score;
}

bool Student::operator==(const Student& other){
    return (*other.credits == *credits) && (other.medium_score == medium_score);
}

