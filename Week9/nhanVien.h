#include <iostream>
#include <string>
using namespace std;

class NhanVien {
  string tenNhanVien;
  float luong;
  float phuCap;
  int *thamNienCongTac;
  public:
    NhanVien();
    NhanVien(string tenNhanVien, float luong, float phuCap, int thamNienCongTac);
    NhanVien(NhanVien &nhanVien);

    void setTenNhanVien(string tenNhanVien);
    void setLuong(float luong);
    void setPhuCap(float phuCap);
    void setThamNienCongTac(int thamNienCongTac);

    string getTenNhanVien();
    float getLuong();
    float getPhuCap();
    int getThamNienCongTac();

    bool operator==(const NhanVien& other);

};