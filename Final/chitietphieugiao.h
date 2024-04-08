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
  static vector<ChiTietPhieuGiao> getData(string filename, vector<ChiTietPhieuGiao> &chitietphieugiaos);
  static void display(vector<ChiTietPhieuGiao> &chitietphieugiaos);
  static vector<ChiTietPhieuGiao> add(vector<ChiTietPhieuGiao> &chitietphieugiaos, vector<Vattu> &vattus, vector<PhieuGiao> &phieugiaos);
  static vector<ChiTietPhieuGiao> update(vector<ChiTietPhieuGiao> &chitietphieugiaos, vector<Vattu> &vattus, vector<PhieuGiao> &phieugiaos);
  static vector<ChiTietPhieuGiao> remove(vector<ChiTietPhieuGiao> &chitietphieugiaos, vector<Vattu> &vattus, vector<PhieuGiao> &phieugiaos);
  static void totalAmount(vector<ChiTietPhieuGiao> &chitietphieugiaos, vector<Vattu> &vattus, vector<PhieuGiao> &phieugiaos);
  static void totalAmountByTime(vector<ChiTietPhieuGiao> &chitietphieugiaos, vector<Vattu> &vattus, vector<PhieuGiao> &phieugiaos);
  static void totalAmountByTimeRange(vector<ChiTietPhieuGiao> &chitietphieugiaos, vector<Vattu> &vattus, vector<PhieuGiao> &phieugiaos);
  static void backup(vector<ChiTietPhieuGiao> &chitietphieugiaos);
  static void restore(vector<ChiTietPhieuGiao> &chitietphieugiaos);
};
#endif