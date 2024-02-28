#include <iostream>
#include <string>
#include "Student.h"

int main() {
    Student sv1("Nhat", 60, 8.0);
    Student sv2("Hon", 59, 8.0);

    if (sv1 == sv2) {
       cout << "Equivalent" << endl;
    } else {
       cout << "No equivalent" << endl;
    }

}