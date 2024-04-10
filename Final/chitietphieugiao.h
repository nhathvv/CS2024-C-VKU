#ifndef chitietphieugiao_h
#define chitietphieugiao_h

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "vattu.h"
#include "phieugiao.h"
class ChiTietPhieuGiao
{
  string soPhieuGiao;
  string maVatTu;
  int soLuongGiao;
  int donGiaGiao;

public:
  ChiTietPhieuGiao();
  ChiTietPhieuGiao(string soPhieuGiao, string maVatTu, int soLuongGiao, int donGiaGiao);

  void setSoPhieuGiao(string soPhieuGiao);
  void setMaVatTu(string maVatTu);
  void setSoLuongGiao(int soLuongGiao);
  void setDonGiaGiao(int donGiaGiao);

  string getSoPhieuGiao();
  string getMaVatTu();
  int getSoLuongGiao();
  int getDonGiaGiao();

 vector<ChiTietPhieuGiao> getData(string filename, vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao);
 void display(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao);
 vector<ChiTietPhieuGiao> add(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu, vector<PhieuGiao> &dsPhieuGiao);
 vector<ChiTietPhieuGiao> update(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu, vector<PhieuGiao> &dsPhieuGiao);
 vector<ChiTietPhieuGiao> remove(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu, vector<PhieuGiao> &dsPhieuGiao);
  void backup(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao);
  void restore(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao);
};
#endif