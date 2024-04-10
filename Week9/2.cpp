#include <iostream>
#include <string>
template <typename T>
T sum(T a, T b, T c) {
    return a + b + c;
}
int total(int n) {
    if (n < 0) {
        throw "n must be greater than 0";
    }
    if (n == 0) {
        return 0;
    }
    return n + total(n - 1);
}
int main() {
    std::cout << sum(1, 2, 3) << std::endl;
    std::cout << sum(1.1, 2.2, 3.3) << std::endl;
    std::cout << sum(std::string("Hello"), std::string(" "), std::string("World")) << std::endl;
    std::cout << total(10) << std::endl;
    return 0;
}