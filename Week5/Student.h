#ifndef sinhvien_h
#define sinhvien_h

#include <iostream>
#include <string>
using namespace std;
class Student {
    string name;
    int *credits;
    float medium_score;
    public:
        Student();
        Student(string name, int credits,float medium_score);
        void setCredits(int credits);
        int getCredits();
        Student(const Student& other);
        bool operator==(const Student& other);
};
#endif