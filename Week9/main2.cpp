#include <iostream>
#include <string>
#include "HinhChuNhat.h"
using namespace std;
int main()
{
    HinhChuNhat hinhChuNhat1("Red", 5.5, 10);
    cout << "Hinh chu nhat 1: " << hinhChuNhat1.getColor() << " " << hinhChuNhat1.getChieuDai() << " " << hinhChuNhat1.getChieuRong() << " " << hinhChuNhat1.tinhDienTich() << endl;
    return 0;
}