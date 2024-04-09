#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "chitietphieugiao.h"
#include "vattu.h"
#include "phieugiao.h"
using namespace std;
ChiTietPhieuGiao::ChiTietPhieuGiao(){};
ChiTietPhieuGiao::ChiTietPhieuGiao(string soPhieuGiao, string maVatTu, int soLuongGiao, int donGiaGiao)
{
  this->soPhieuGiao = soPhieuGiao;
  this->maVatTu = maVatTu;
  this->soLuongGiao = soLuongGiao;
  this->donGiaGiao = donGiaGiao;
}
void ChiTietPhieuGiao::setSoPhieuGiao(string soPhieuGiao)
{
  this->soPhieuGiao = soPhieuGiao;
}
void ChiTietPhieuGiao::setMaVatTu(string maVatTu)
{
  this->maVatTu = maVatTu;
}
void ChiTietPhieuGiao::setSoLuongGiao(int soLuongGiao)
{
  this->soLuongGiao = soLuongGiao;
}
void ChiTietPhieuGiao::setDonGiaGiao(int donGiaGiao)
{
  this->donGiaGiao = donGiaGiao;
}
string ChiTietPhieuGiao::getSoPhieuGiao()
{
  return soPhieuGiao;
}
string ChiTietPhieuGiao::getMaVatTu()
{
  return maVatTu;
}
int ChiTietPhieuGiao::getSoLuongGiao()
{
  return soLuongGiao;
}
int ChiTietPhieuGiao::getDonGiaGiao()
{
  return donGiaGiao;
}

vector<ChiTietPhieuGiao> ChiTietPhieuGiao::getData(string filename, vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao)
{
  ifstream file(filename);
  if (!file.is_open())
  {
    cout << "File not found!";
    return dsChiTietPhieuGiao;
  }
  string soPhieuGiao, maVatTu, soLuongGiao, donGiaGiao;
  while (getline(file, soPhieuGiao, ',') &&
         getline(file, maVatTu, ',') &&
         getline(file, soLuongGiao, ',') &&
         getline(file, donGiaGiao))
  {
    ChiTietPhieuGiao chitietphieugiao(soPhieuGiao, maVatTu, stoi(soLuongGiao), stoi(donGiaGiao));
    dsChiTietPhieuGiao.push_back(chitietphieugiao);
  }
  file.close();
  return dsChiTietPhieuGiao;
}

void ChiTietPhieuGiao::display(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao)
{
  for (auto &chitietphieugiao : dsChiTietPhieuGiao)
  {
    cout << "So phieu giao: " << chitietphieugiao.getSoPhieuGiao() << endl;
    cout << "Ma vat tu: " << chitietphieugiao.getMaVatTu() << endl;
    cout << "So luong giao: " << chitietphieugiao.getSoLuongGiao() << endl;
    cout << "Don gia giao: " << chitietphieugiao.getDonGiaGiao() << endl;
    cout << "--------------------------------" << endl;
  }
}
vector<ChiTietPhieuGiao> ChiTietPhieuGiao::add(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu, vector<PhieuGiao> &dsPhieuGiao)
{
  string soPhieuGiao, maVatTu;
  int soLuongGiao, donGiaGiao;
  cin.ignore();
  cout << "Nhap so phieu giao: ";
  getline(cin, soPhieuGiao);
  cout << "Nhap ma vat tu: ";
  getline(cin, maVatTu);
  cout << "Nhap so luong giao: ";
  cin >> soLuongGiao;
  cout << "Nhap don gia giao: ";
  cin >> donGiaGiao;
  bool isVattuExist = false;
  bool isPhieuGiaoExist = false;
  for (auto &vattu : dsVattu)
  {
    if (vattu.getMaVatu() == maVatTu)
    {
      isVattuExist = true;
      break;
    }
  }
  for (auto &phieugiao : dsPhieuGiao)
  {
    if (phieugiao.getSoPhieuGiao() == soPhieuGiao)
    {
      isPhieuGiaoExist = true;
      break;
    }
  }
  if (!isVattuExist)
  {
    cout << "Ma vat tu khong ton tai!" << endl;
    return dsChiTietPhieuGiao;
  }
  if (!isPhieuGiaoExist)
  {
    cout << "So phieu giao khong ton tai!" << endl;
    return dsChiTietPhieuGiao;
  }
  ChiTietPhieuGiao chitietphieugiao(soPhieuGiao, maVatTu, soLuongGiao, donGiaGiao);
  dsChiTietPhieuGiao.push_back(chitietphieugiao);
  ofstream file("chitietphieugiao.csv");
  for (auto &chitietphieugiao : dsChiTietPhieuGiao)
  {
    file << chitietphieugiao.getSoPhieuGiao() << "," << chitietphieugiao.getMaVatTu() << "," << chitietphieugiao.getSoLuongGiao() << "," << chitietphieugiao.getDonGiaGiao() << endl;
  }
  return dsChiTietPhieuGiao;
}
vector<ChiTietPhieuGiao> ChiTietPhieuGiao::update(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu, vector<PhieuGiao> &dsPhieuGiao)
{
  string soPhieuGiao, maVatTu;
  int soLuongGiao, donGiaGiao;
  cin.ignore();
  cout << "Nhap so phieu giao: ";
  getline(cin, soPhieuGiao);
  cout << "Nhap ma vat tu: ";
  getline(cin, maVatTu);
  cout << "Nhap so luong giao: ";
  cin >> soLuongGiao;
  cout << "Nhap don gia giao: ";
  cin >> donGiaGiao;
  bool isVattuExist = false;
  bool isPhieuGiaoExist = false;
  for (auto &vattu : dsVattu)
  {
    if (vattu.getMaVatu() == maVatTu)
    {
      isVattuExist = true;
      break;
    }
  }
  for (auto &phieugiao : dsPhieuGiao)
  {
    if (phieugiao.getSoPhieuGiao() == soPhieuGiao)
    {
      isPhieuGiaoExist = true;
      break;
    }
  }
  if (!isVattuExist)
  {
    cout << "Ma vat tu khong ton tai!" << endl;
    return dsChiTietPhieuGiao;
  }
  if (!isPhieuGiaoExist)
  {
    cout << "So phieu giao khong ton tai!" << endl;
    return dsChiTietPhieuGiao;
  }
  for (auto &chitietphieugiao : dsChiTietPhieuGiao)
  {
    if (chitietphieugiao.getSoPhieuGiao() == soPhieuGiao && chitietphieugiao.getMaVatTu() == maVatTu)
    {
      chitietphieugiao.setSoLuongGiao(soLuongGiao);
      chitietphieugiao.setDonGiaGiao(donGiaGiao);
      break;
    }
  }
  return dsChiTietPhieuGiao;
}
vector<ChiTietPhieuGiao> ChiTietPhieuGiao::remove(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu, vector<PhieuGiao> &dsPhieuGiao)
{
  string soPhieuGiao, maVatTu;
  cin.ignore();
  cout << "Nhap so phieu giao: ";
  getline(cin, soPhieuGiao);
  cout << "Nhap ma vat tu: ";
  getline(cin, maVatTu);
  bool isVattuExist = false;
  bool isPhieuGiaoExist = false;
  for (auto &vattu : dsVattu)
  {
    if (vattu.getMaVatu() == maVatTu)
    {
      isVattuExist = true;
      break;
    }
  }
  for (auto &phieugiao : dsPhieuGiao)
  {
    if (phieugiao.getSoPhieuGiao() == soPhieuGiao)
    {
      isPhieuGiaoExist = true;
      break;
    }
  }
  if (!isVattuExist)
  {
    cout << "Ma vat tu khong ton tai!" << endl;
    return dsChiTietPhieuGiao;
  }
  if (!isPhieuGiaoExist)
  {
    cout << "So phieu giao khong ton tai!" << endl;
    return dsChiTietPhieuGiao;
  }
  for (auto it = dsChiTietPhieuGiao.begin(); it != dsChiTietPhieuGiao.end();it++)
  {
    if (it->getSoPhieuGiao() == soPhieuGiao && it->getMaVatTu() == maVatTu)
    {
      it = dsChiTietPhieuGiao.erase(it);
    }
  }
  ofstream file("chitietphieugiao.csv");
  for (auto &chitietphieugiao : dsChiTietPhieuGiao)
  {
    file << chitietphieugiao.getSoPhieuGiao() << "," << chitietphieugiao.getMaVatTu() << "," << chitietphieugiao.getSoLuongGiao() << "," << chitietphieugiao.getDonGiaGiao() << endl;
  }
  file.close();
  return dsChiTietPhieuGiao;
}

void ChiTietPhieuGiao::backup(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao)
{
  ofstream file("chitietphieugiao_backup.csv");
  for (auto &chitietphieugiao : dsChiTietPhieuGiao)
  {
    file << chitietphieugiao.getSoPhieuGiao() << "," << chitietphieugiao.getMaVatTu() << "," << chitietphieugiao.getSoLuongGiao() << "," << chitietphieugiao.getDonGiaGiao() << endl;
  }
  file.close();
}
void ChiTietPhieuGiao::restore(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao)
{
  ifstream file("chitietphieugiao_backup.csv");
  if (!file.is_open())
  {
    cout << "File not found!";
    return;
  }
  string soPhieuGiao, maVatTu, soLuongGiao, donGiaGiao;
  while (getline(file, soPhieuGiao, ',') &&
         getline(file, maVatTu, ',') &&
         getline(file, soLuongGiao, ',') &&
         getline(file, donGiaGiao))
  {
    ChiTietPhieuGiao chitietphieugiao(soPhieuGiao, maVatTu, stoi(soLuongGiao), stoi(donGiaGiao));
    dsChiTietPhieuGiao.push_back(chitietphieugiao);
    ofstream file("chitietphieugiao.csv", ios::app);
    file << soPhieuGiao << "," << maVatTu << "," << soLuongGiao << "," << donGiaGiao << endl;
  }
  file.close();
}