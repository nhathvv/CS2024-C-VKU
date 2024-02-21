#include <iostream>
#include "Employee.h"
using namespace std;
int main() {
    Employee e1("Susan Meyers",47899,"Accounting","Vice President");
    Employee e2("Mark Jones",39119,"IT","Programmer");
    Employee e3("Joy Rogers",81774,"Manufacturing","Engineer");
    cout << "Employee 1:" << endl;
    cout << "Name: " << e1.getName() << endl;
    cout << "ID Number: " << e1.getIdNumber() << endl;
    cout << "Department: " << e1.getDepartment() << endl;
    cout << "Position: " << e1.getPosition() << endl;
    cout << endl;

    cout << "Employee 2:" << endl;
    cout << "Name: " << e2.getName() << endl;
    cout << "ID Number: " << e2.getIdNumber() << endl;
    cout << "Department: " << e2.getDepartment() << endl;
    cout << "Position: " << e2.getPosition() << endl;
    cout << endl;

    cout << "Employee 3:" << endl;
    cout << "Name: " << e3.getName() << endl;
    cout << "ID Number: " << e3.getIdNumber() << endl;
    cout << "Department: " << e3.getDepartment() << endl;
    cout << "Position: " << e3.getPosition() << endl;
    cout << endl;

    return 0;

}