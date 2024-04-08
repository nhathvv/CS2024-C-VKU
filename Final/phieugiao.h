#ifndef phieugiao_h
#define phieugiao_h
#include <iostream>
#include <string>
using namespace std;
class PhieuGiao
{
  string soPhieuGiao;
  string ngayGiao;
  string noiGiao;
  string maKH;

public:
  PhieuGiao();
  PhieuGiao(string soPhieuGiao, string ngayGiao, string noiGiao, string maKH);
  void setSoPhieuGiao(string soPhieuGiao);
  void setNgayGiao(string ngayGiao);
  void setNoiGiao(string noiGiao);
  void setMaKH(string maKH);

  string getSoPhieuGiao();
  string getNgayGiao();
  string getNoiGiao();
  string getMaKH();

  static vector<PhieuGiao> getData(string filename, vector<PhieuGiao> &phieugiaos);
  static void display(vector<PhieuGiao> &phieugiaos);
  static vector<PhieuGiao> add(vector<PhieuGiao> &phieugiaos);
  static vector<PhieuGiao> update(vector<PhieuGiao> &phieugiaos);
  static vector<PhieuGiao> remove(vector<PhieuGiao> &phieugiaos);
  static void backup(vector<PhieuGiao> &phieugiaos);
  static void restore(vector<PhieuGiao> &phieugiaos);
};
#endif