#ifndef retangle_h
#define retangle_h

#include <iostream>
#include <string>
using namespace std;
class Retangle {
    float width;
    float height;
    string color;
    public: 
        Retangle();
        Retangle(float width, float height, string color);
        float getArea();
        float getPerimeter();
        void displayRetangle();
};
#endif