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

  vector<Vattu> getData(string filename, vector<Vattu> &dsVattu);
  void display(vector<Vattu> &dsVattu);
  vector<Vattu> add(vector<Vattu> &dsVattu);
  vector<Vattu> update(vector<Vattu> &dsVattu);
  vector<Vattu> remove(vector<Vattu> &dsVattu);
  void backup(vector<Vattu> &dsVattu);
  void restore(vector<Vattu> &dsVattu);
};
#endif