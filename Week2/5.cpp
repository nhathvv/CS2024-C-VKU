#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream inputFile("danhba.csv");
    vector<string> values;
    string temp;
    while (getline(inputFile, temp,','))
    {
        values.push_back(temp);
    }
    for(const auto&line : values) {
        cout << line << endl;
    }
    inputFile.close();
}