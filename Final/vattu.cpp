#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "vattu.h"
using namespace std;
Vattu::Vattu(){};
Vattu::Vattu(string maVatu, string tenVatu, string donViTinh)
{
  this->maVatu = maVatu;
  this->tenVatu = tenVatu;
  this->donViTinh = donViTinh;
}
void Vattu::setMaVatu(string maVatu)
{
  this->maVatu = maVatu;
}
void Vattu::setTenVatu(string tenVatu)
{
  this->tenVatu = tenVatu;
}
void Vattu::setDonViTinh(string donViTinh)
{
  this->donViTinh = donViTinh;
}

string Vattu::getMaVatu()
{
  return maVatu;
}
string Vattu::getTenVatu()
{
  return tenVatu;
}
string Vattu::getDonViTinh()
{
  return donViTinh;
}
vector<Vattu> Vattu::getData(string filename, vector<Vattu> &dsVattu)
{
  ifstream file(filename);
  if (!file.is_open())
  {
    cout << "File not found!";
    return dsVattu;
  }
  string maVatu, tenVatu, donViTinh;
  while (getline(file, maVatu, ',') &&
         getline(file, tenVatu, ',') &&
         getline(file, donViTinh))
  {
    Vattu vattu(maVatu, tenVatu, donViTinh);
    dsVattu.push_back(vattu);
  }
  file.close();
  return dsVattu;
}
void Vattu::display(vector<Vattu> &dsVattu)
{
  for (auto &vattu : dsVattu)
  {
    cout << "Ma vat tu: " << vattu.getMaVatu() << endl;
    cout << "Ten vat tu: " << vattu.getTenVatu() << endl;
    cout << "Don vi tinh: " << vattu.getDonViTinh() << endl;
    cout << "-------------------" << endl;
  }
}
vector<Vattu> Vattu::add(vector<Vattu> &dsVattu)
{
  string maVatu, tenVatu, donViTinh;
  cin.ignore();
  cout << "Nhap ma vat tu: ";
  getline(cin, maVatu);
  cout << "Nhap ten vat tu: ";
  getline(cin, tenVatu);
  cout << "Nhap don vi tinh: ";
  getline(cin, donViTinh);
  Vattu vattu(maVatu, tenVatu, donViTinh);
  dsVattu.push_back(vattu);
  ofstream file("vattu.csv", ios::app);
  file << maVatu << "," << tenVatu << "," << donViTinh << endl;
  file.close();
  return dsVattu;
}
vector<Vattu> Vattu::update(vector<Vattu> &dsVattu)
{
  string maVatu;
  cin.ignore();
  cout << "Nhap ma vat tu can sua: ";
  getline(cin, maVatu);
  for (auto &vattu : dsVattu)
  {
    if (vattu.getMaVatu() == maVatu)
    {
      string tenVatu, donViTinh;
      cout << "Nhap ten vat tu: ";
      getline(cin, tenVatu);
      cout << "Nhap don vi tinh: ";
      getline(cin, donViTinh);
      vattu.setTenVatu(tenVatu);
      vattu.setDonViTinh(donViTinh);
      ofstream file("vattu.csv");
      for (auto &vattu : dsVattu)
      {
        file << vattu.getMaVatu() << "," << vattu.getTenVatu() << "," << vattu.getDonViTinh() << endl;
      }
      file.close();
      return dsVattu;
    }
  }
  cout << "Khong tim thay ma vat tu!" << endl;
}
vector<Vattu> Vattu::remove(vector<Vattu> &dsVattu)
{
  string maVatu;
  cout << "Nhap ma vat tu can xoa: ";
  cin.ignore();
  getline(cin, maVatu);
  for (auto it = dsVattu.begin(); it != dsVattu.end(); it++)
  {
    if (it->getMaVatu() == maVatu)
    {
      dsVattu.erase(it);
      ofstream file("vattu.csv");
      for (auto &vattu : dsVattu)
      {
        file << vattu.getMaVatu() << "," << vattu.getTenVatu() << "," << vattu.getDonViTinh() << endl;
      }
      file.close();
      return dsVattu;
    }
  }
  cout << "Khong tim thay ma vat tu!" << endl;
}
void Vattu::backup(vector<Vattu> &dsVattu)
{
  ofstream file("vattu_backup.csv");
  for (auto &vattu : dsVattu)
  {
    file << vattu.getMaVatu() << "," << vattu.getTenVatu() << "," << vattu.getDonViTinh() << endl;
  }
  file.close();
}
void Vattu::restore(vector<Vattu> &dsVattu)
{
  dsVattu.clear();
  ifstream file("vattu_backup.csv");
  string maVatu, tenVatu, donViTinh;
  while (getline(file, maVatu, ',') &&
         getline(file, tenVatu, ',') &&
         getline(file, donViTinh))
  {
    Vattu vattu(maVatu, tenVatu, donViTinh);
    dsVattu.push_back(vattu);
    ofstream file("vattu.csv", ios::app);
    file << maVatu << "," << tenVatu << "," << donViTinh << endl;
  }
  file.close();
}