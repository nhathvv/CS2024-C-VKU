#include <iostream>
#include <fstream>
using namespace std;

int readFile(string filename) {
    ifstream fileInput(filename);
    if(fileInput.fail()) {
        std::cout << "Failed to open this file " << std::endl;
        return -1;
    }
    while (!fileInput.eof()) 
    {
        /* code */
        char temp[255];
        fileInput.getline(temp,255);
        string line = temp;
        cout << line << endl;
    }   
    return 0;
}
int main() {
    readFile("input2.txt");
}