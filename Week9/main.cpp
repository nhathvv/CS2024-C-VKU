#include <iostream>
#include <string>
#include "nhanVien.h"
using namespace std;
int main() {
    NhanVien nhanVien1("Nguyen Van A", 1000, 100, 5);
    NhanVien nhanVien2("Nguyen Van B", 1000, 120, 5);
    NhanVien nhanVien3(nhanVien1);
    cout << "Nhan vien 1: " << nhanVien1.getTenNhanVien() << " " << nhanVien1.getLuong() << " " << nhanVien1.getPhuCap() << " " << nhanVien1.getThamNienCongTac() << endl;
    cout << "Nhan vien 2: " << nhanVien2.getTenNhanVien() << " " << nhanVien2.getLuong() << " " << nhanVien2.getPhuCap() << " " << nhanVien2.getThamNienCongTac() << endl;
    cout << "Nhan vien 3: " << nhanVien3.getTenNhanVien() << " " << nhanVien3.getLuong() << " " << nhanVien3.getPhuCap() << " " << nhanVien3.getThamNienCongTac() << endl;
    cout << "Nhan vien 1 == Nhan vien 2: " << (nhanVien1 == nhanVien2) << endl;
    cout << "Nhan vien 1 == Nhan vien 3: " << (nhanVien1 == nhanVien3) << endl;
    return 0;
}