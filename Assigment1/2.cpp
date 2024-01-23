#include <iostream>
#include <math.h>
#include <string>
using namespace std;
void quadraticEquation(double a,double b, double c) {
    double x1,x2,x;
    if(a == 0) {
        if(b != 0) {
            x = -c / b;
            cout << "x = " << x;
        }else {
            cout << "PT VO SO NGHIEM";
        }
        return;
    }
   
     double denta = b * b - 4 * a *c;
     if(denta < 0) {
        cout << "PT VO NGHIEM";
     } else if(denta == 0) {
        cout << "x1 = x2 = " << -b / (2*a);
     } else {
        x1 = (-b + sqrt(denta)) / (2 * a);
        x2 = (-b - sqrt(denta)) / (2 * a);
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2;
     }
}
int main() {
   double a,b,c;
   cout << "Nhap 3 so a,b,c :";
   cin >> a >> b >> c;
   quadraticEquation(a,b,c);
   return 0;
}