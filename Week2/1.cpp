#include <iostream>
#include <fstream>
using namespace std;
const int ARRAY_MAX = 50;
int readFile(string namefile, int &n, int numbers[]) {
    ifstream fileInput(namefile);
    if(fileInput.fail()) {
        cout << "Failed to open this file " << endl;
        return -1;
    }
    int i = 0;
    while (!fileInput.eof())
    {
        fileInput >> numbers[i];
        ++i;
    }
    n = i;
    fileInput.close();
    return 0;
}
void in(int numbers[],int n) {
    for(int i = 0; i < n; i++) {
        cout << numbers[i] << " ";
    }
}
int max(int numbers[], int n) {
    int max = numbers[0];
    for(int i = 1; i < n; i++) {
        if(max < numbers[i]) {
            max = numbers[i];
        }
    }
    return max;
}
void writeFile(int max, string filename) {
    ofstream fileOut(filename);
    fileOut << max << std::endl;
    fileOut.close();
}
int main() {
    int n;
    int numbers[ARRAY_MAX];
    readFile("input.txt",n,numbers);
    in(numbers,n);
    max(numbers,n);
    writeFile(max(numbers,n),"output.txt");
}