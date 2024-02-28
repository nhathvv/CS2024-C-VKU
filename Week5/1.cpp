#include <iostream>
#include "Retangle.h"
using namespace std;
int main() {
    vector <Retangle> retangles;
    Retangle retangle1(5,6,"blue");
    Retangle retangle2(3,6,"red");
    Retangle retangle3(2,6,"green");
    Retangle retangle4(1,6,"pink");
    Retangle retangle5(4,6,"orange");
    Retangle retangle6(7,6,"blue");
    retangles.push_back(retangle1);
    retangles.push_back(retangle2);
    retangles.push_back(retangle3);
    retangles.push_back(retangle4);
    retangles.push_back(retangle5);
    retangles.push_back(retangle6);
    
    int i = 1;
    for (auto& rect : retangles) {
        cout << i++ << endl;
        rect.displayRetangle();
    }
}