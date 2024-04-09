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

  vector<PhieuGiao> getData(string filename, vector<PhieuGiao> &dsPhieuGiao);
  void display(vector<PhieuGiao> &dsPhieuGiao);
  vector<PhieuGiao> add(vector<PhieuGiao> &dsPhieuGiao);
  vector<PhieuGiao> update(vector<PhieuGiao> &dsPhieuGiao);
  vector<PhieuGiao> remove(vector<PhieuGiao> &dsPhieuGiao);
  void backup(vector<PhieuGiao> &dsPhieuGiao);
  void restore(vector<PhieuGiao> &dsPhieuGiao);
};
#endif