#include <iostream>
#include <string>
#include "Car.h"
Car::Car(int yearModel, string make, int speed) {
    this->yearModel = yearModel;
    this->make = make;
    this->speed = speed;
}
int Car::getYearModel() {
    return yearModel;
}
string Car::getMake() {
    return make;
}
int Car::getSpeed() {
    return speed;
}
void Car::setYearModel(int yearModel) {
    this->yearModel = yearModel;
}
void Car::setMake(string make) {
    this->make = make;
}
void Car::setSpeed(int speed) {
    this->speed = speed;
}
int Car::accelerate(int speed) {
    this->speed = speed + 5;
}
int Car::brake(int speed) {
    this->speed = speed - 5;
}