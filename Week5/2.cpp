#include <iostream>
#include "Product.h"
using namespace std;
int main() {
   vector <Product> products;
   Product product1("Oppo",500,1);
   Product product2("Apple",1500,5);
   Product product3("Samsung",2500,1);
   products.push_back(product1);
   products.push_back(product2);
   products.push_back(product3);
   
    for (auto& item : products) {
        item.displayProduct();
    }
}