#include <iostream>
#include <string>
#include "Product.h"

Product::Product() {
    this->name = "";
    this->price = new float(0);
    this->quantity = quantity;
}
Product::Product(string name, float price,int quantity) {
    this->name = name;
    this->price = new float(price);
    this->quantity = quantity;
}
void Product::setPrice(float price) {
    *this->price = price;
}
float Product::getPrice() {
    return *price;
}
void Product::displayProduct() {
    cout << name << endl;
    cout << getPrice() << endl;
    cout << quantity << endl;
    cout << "--------------" << endl;
}