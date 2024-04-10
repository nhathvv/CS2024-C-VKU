#include <iostream>
#include <string>
#include "nhanVien.h"
using namespace std;

NhanVien::NhanVien() {
    this->tenNhanVien = "";
    this->luong = 0;
    this->phuCap = 0;
    this->thamNienCongTac = new int(0);
}
NhanVien::NhanVien(string tenNhanVien, float luong, float phuCap, int thamNienCongTac) {
    this->tenNhanVien = tenNhanVien;
    this->luong = luong;
    this->phuCap = phuCap;
    this->thamNienCongTac = new int(thamNienCongTac);
}
NhanVien::NhanVien(NhanVien &nhanVien) {
    this->tenNhanVien = nhanVien.tenNhanVien;
    this->luong = nhanVien.luong;
    this->phuCap = nhanVien.phuCap;
    this->thamNienCongTac = new int(*nhanVien.thamNienCongTac);
}
void NhanVien::setTenNhanVien(string tenNhanVien) {
    this->tenNhanVien = tenNhanVien;
}
string NhanVien::getTenNhanVien() {
    return tenNhanVien;
}
void NhanVien::setLuong(float luong) {
    this->luong = luong;
}
float NhanVien::getLuong() {
    return luong;
}
void NhanVien::setPhuCap(float phuCap) {
    this->phuCap = phuCap;
}
float NhanVien::getPhuCap() {
    return phuCap;
}
void NhanVien::setThamNienCongTac(int thamNienCongTac) {
    *this->thamNienCongTac = thamNienCongTac;
}
int NhanVien::getThamNienCongTac() {
    return *thamNienCongTac;
}

bool NhanVien::operator==(const NhanVien& other) {
    return this->luong == other.luong && this->phuCap == other.phuCap && *this->thamNienCongTac == *other.thamNienCongTac;
}
