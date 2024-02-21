#include <iostream>
#include "Car.h"
using namespace std;
int main() {
    Car car1(2024,"Toyota",120);
    car1.accelerate(car1.getSpeed());
    car1.accelerate(car1.getSpeed());
    car1.accelerate(car1.getSpeed());
    car1.accelerate(car1.getSpeed());
    car1.accelerate(car1.getSpeed());
    cout << car1.getSpeed() << endl;
    car1.brake(car1.getSpeed());
    car1.brake(car1.getSpeed());
    car1.brake(car1.getSpeed());
    car1.brake(car1.getSpeed());
    car1.brake(car1.getSpeed());
    cout << car1.getSpeed() << endl;
}