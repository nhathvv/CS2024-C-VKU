#include <iostream>
#include <string>
using namespace std;
void distance (int speed, int hours){
    for(int i = 1; i <= hours; i++) {
        cout << i << "   "  << speed * i << endl;
    }
}
int main() {
    int speed, hours;
    cout << "What is the speed of the vehicle in mph? ";
    cin >> speed;
    cout << "How many hours has it traveled? ";
    cin >> hours;
    cout << "Hour Distance Traveled" << endl;
    cout << "--------------------------------" << endl;
    distance(speed,hours);
    return 0;
}