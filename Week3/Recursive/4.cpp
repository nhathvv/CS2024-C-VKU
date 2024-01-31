// Problem 4. Sum of Numbers
#include <iostream>
using namespace std;
int sum(int n) {
    if(n == 0) {
        return -1;
    }
    if(n == 1) {
        return 1;
    }
    return n + sum(--n);
}
int main() {
    int n;
    cin >> n;
    cout << sum(n);
}