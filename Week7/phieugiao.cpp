#include <iostream>
#include <string>
#include "vatlieu.h"
using namespace std;
PhieuGiaoHang::PhieuGiaoHang(){};
PhieuGiaoHang::PhieuGiaoHang(string soPhieuGiao,string ngayGiao, string noiGiao,string maKH) {
    this->soPhieuGiao = soPhieuGiao;
    this->ngayGiao = ngayGiao;
    this->noiGiao = noiGiao;
    this->maKH = maKH;
}
void PhieuGiaoHang::setSoPhieuGiao(string soPhieuGiao) {
    this->soPhieuGiao = soPhieuGiao;
}
void PhieuGiaoHang::setNgayGiao(string ngayGiao) {
    this->ngayGiao = ngayGiao;
}
void PhieuGiaoHang::setNoiGiao(string noiGiao) {
    this->noiGiao = noiGiao;
}
void PhieuGiaoHang::setMaKH(string maKH) {
    this->maKH = maKH;
}
string PhieuGiaoHang::getSoPhieuGiao() {
    return soPhieuGiao;
}
string PhieuGiaoHang::getNgayGiao() {
    return ngayGiao;
}

string PhieuGiaoHang::getNoiGiao() {
    return noiGiao;
}