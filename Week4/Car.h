#ifndef car_h
#define car_h

#include <iostream>
#include <string>
using namespace std;
class Car {
    int yearModel;
    string make;
    int speed;
    public:
        Car(int yearModel, string make, int speed);
        void setYearModel(int yearModel);
        void setMake(string make);
        void setSpeed(int speed);
        string getMake();
        int getYearModel();
        int getSpeed();
        int accelerate(int speed);
        int brake(int speed);
};
#endif