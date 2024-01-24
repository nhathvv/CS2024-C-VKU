#include <iostream>
#include <fstream>
using namespace std;
const int ARRAY_MAX = 50;
int readFile(string namefile,int numbers[],int &n) {
    ifstream fileInput(namefile);
    if(fileInput.fail()) {
        std::cout << "Failed to open this file " << std::endl;
        return -1;
    }
    int i = 0;
    while (!fileInput.eof())
    {
        fileInput >> numbers[i];
        i++;
    }
    n = i;
    fileInput.close();
    return 0;
}
bool isEven(int n) {
   if(n % 2 == 0) {
        return true;
   }
   return false;
}
void writeFile(string filename, int numbers[], int n) {
    ofstream fileOut(filename);
    for(int i = 0 ; i < n; i++) {
        if(isEven(numbers[i])) {
            fileOut <<  numbers[i] << endl;
        }
    }
    fileOut.close();
}
int main() {
    int numbers[ARRAY_MAX];
    int n;
    readFile("input3.txt",numbers,n);
    writeFile("output3.txt",numbers,n);
    return 0;
}