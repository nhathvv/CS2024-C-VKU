#include <iostream>
#include <string>
#include "Retangle.h"

Retangle::Retangle() {
    this->width = 0;
    this->height = 0;
    this->color = "red";
}
Retangle::Retangle(float width, float height,string color) {
    if(width >= 0 && height >= 0) {
        this->width = width;
        this->height = height;
    }
    this->color = color;
}
float Retangle::getArea() {
    return width * height;
}
float Retangle::getPerimeter() {
    return 2 * (width + height);
}
void Retangle::displayRetangle() {
    cout <<"Diện tích: " << getArea() << endl;
    cout <<"Chu vi: " << getPerimeter() << endl;
    cout << "--------------------"<<endl;
}