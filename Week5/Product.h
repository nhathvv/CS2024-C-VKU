#ifndef product_h
#define product_h
#include <iostream>
#include <string>
using namespace std;
class Product {
    string name;
    float *price;
    int quantity;
    public:
        Product();
        Product(string name, float price, int quantity);
        void setPrice(float frice);
        float getPrice();
        void displayProduct();
};
#endif
