#ifndef vattu_h
#define vattu_h
#include <iostream>
#include <string>
using namespace std;
class Vattu
{
  string maVatu;
  string tenVatu;
  string donViTinh;

public:
  Vattu();
  Vattu(string maVatu, string tenVatu, string donViTinh);
  void setMaVatu(string maVatu);
  void setTenVatu(string tenVatu);
  void setDonViTinh(string donViTinh);

  string getMaVatu();
  string getTenVatu();
  string getDonViTinh();

  static vector<Vattu> getData(string filename, vector<Vattu> &vattus);
  static void display(vector<Vattu> &vattus);
  static vector<Vattu> add(vector<Vattu> &vattus);
  static vector<Vattu> update(vector<Vattu> &vattus);
  static vector<Vattu> remove(vector<Vattu> &vattus);
  // Build data backup and restore features
  static void backup(vector<Vattu> &vattus);
  static void restore(vector<Vattu> &vattus);
};
#endif