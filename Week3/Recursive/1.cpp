// Problem 1. Recursive Conversion
#include <iostream>
using namespace std;
void sign(int n)
{
    if(n == 0) {
        return;
    }
    cout << "No Parking\n";
    sign(--n);
}
int main() {
    int n;
    cin >> n;
    sign(n);
}