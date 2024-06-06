#include <iostream>
#include <string>
using namespace std;
class HinhHoc
{
    string color;

public:
    HinhHoc() {}
    HinhHoc(string _color)
    {
        this->color = _color;
    }
    void setColor(string _color)
    {
        this->color = _color;
    }
    string getColor()
    {
        return this->color;
    }
    virtual float tinhDienTich() = 0;
};