// Problem 3. Recursive Multiplication
#include <iostream>
using namespace std;
int multiplication(int x, int y) {
    if(x == 0 || y == 0) {
        return 0;
    }
    x--;
    return y + multiplication(x,y);
}
int main() {
    int x,y;
    cin >> x >> y;
    cout << multiplication(x,y);
    return 0;
}