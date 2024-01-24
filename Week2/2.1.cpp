#include <iostream>
#include <fstream>
using namespace std;

vector<string> readFile(string filename) {
    ifstream fileInput(filename);
    vector<string> lines;
    if(fileInput.fail()) {
        std::cout << "Failed to open this file " << std::endl;
        // return;
    }
    while (!fileInput.eof()) 
    {
        /* code */
        char temp[255];
        fileInput.getline(temp,255);
        string line = temp;
        lines.push_back(line);
    }   
    return lines;
}
void displayInfo(vector<string> lines) {
    for(string line:lines) {
        cout << line << endl;
    }
}
int main() {
    readFile("input2.1.txt");
    displayInfo(readFile("input2.1.txt"));
    return 0;
}