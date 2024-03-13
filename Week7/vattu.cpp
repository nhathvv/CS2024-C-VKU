#include <iostream>
#include <string>
#include "vatlieu.h"
using namespace std;
Vattu::Vattu(){};
Vattu::Vattu(string maVattu, string tenVattu, string donViTinh) {
    this->maVattu = maVattu;
    this->tenVattu = tenVattu;
    this->donViTinh = donViTinh;
}
void Vattu::setMaVattu(string maVattu) {
    this->maVattu = maVattu;
}
void Vattu::setTenVattu(string tenVattu) {
    this->tenVattu = tenVattu;
}
void Vattu::setDonViTinh(string donViTinh) {
    this->donViTinh = donViTinh;
}
string Vattu::getMaVattu() {
    return maVattu;
}
string Vattu::getTenVattu() {
    return tenVattu;
}
string Vattu::getDonViTinh() {
    return donViTinh;
}