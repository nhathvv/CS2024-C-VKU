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
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}
int ucln(int numbers[], int n) {
    if (n == 0) {
        return -1;
    }
    int result = numbers[0];

    for (int i = 1; i < n; i++) {
        result = gcd(result, numbers[i]);
    }

    return result;
}
int lcm(int a, int b) {
    return (a / gcd(a,b) ) * b; 
}
int bcnn(int numbers[], int n) {
    if (n == 0) {
        return -1;
    }
    int result = numbers[0];

    for (int i = 1; i < n; i++) {
        result = lcm(result, numbers[i]);
    }

    return result;
}
void writeFileUCLN(string filename,int numbers[], int n) {
    ofstream fileOut(filename);
    fileOut << ucln(numbers,n) << endl;
    fileOut.close();
}
void writeFileBCNN(string filename,int numbers[], int n) {
    ofstream fileOut(filename);
    fileOut << bcnn(numbers,n) << endl;
    fileOut.close();
}

int main() {
    int numbers[ARRAY_MAX];
    int n;
    readFile("input4.txt",numbers,n);
    writeFileUCLN("UCLN.txt",numbers,n);
    writeFileBCNN("BCNN.txt",numbers,n);
    return 0;
}