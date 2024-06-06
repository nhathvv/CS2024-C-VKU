#include <iostream>
#include <string>
#include "hinhHoc.h"
using namespace std;
class HinhChuNhat : public HinhHoc
{
    float chieuDai, chieuRong;

public:
    HinhChuNhat() : HinhHoc()
    {
        this->chieuDai = 0;
        this->chieuRong = 0;
    }
    HinhChuNhat(string _color, float _chieuDai, float _chieuRong) : HinhHoc(_color)
    {
        this->chieuDai = _chieuDai;
        this->chieuRong = _chieuRong;
    }
    void setChieuDai(float _chieuDai)
    {
        this->chieuDai = _chieuDai;
    }
    void setChieuRong(float _chieuRong)
    {
        this->chieuRong = _chieuRong;
    }
    float getChieuDai()
    {
        return this->chieuDai;
    }
    float getChieuRong()
    {
        return this->chieuRong;
    }
    float tinhDienTich()
    {
        if (chieuDai > 0 && chieuRong > 0)
        {
            return this->chieuDai * this->chieuRong;
        }
        else
        {
            return 0;
        }
    }
};