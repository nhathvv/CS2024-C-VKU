#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "chitietphieugiao.h"
#include "vattu.h"
#include "phieugiao.h"
using namespace std;
typedef pair<string, int> StringIntPair;
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
vector<ChiTietPhieuGiao> ChiTietPhieuGiao::getData(string filename, vector<ChiTietPhieuGiao> &chitietphieugiaos)
{
  ifstream file(filename);
  if (!file.is_open())
  {
    cout << "File not found!";
    return chitietphieugiaos;
  }
  string soPhieuGiao, maVatTu, soLuongGiao, donGiaGiao;
  while (getline(file, soPhieuGiao, ',') &&
         getline(file, maVatTu, ',') &&
         getline(file, soLuongGiao, ',') &&
         getline(file, donGiaGiao))
  {
    ChiTietPhieuGiao chitietphieugiao(soPhieuGiao, maVatTu, stoi(soLuongGiao), stoi(donGiaGiao));
    chitietphieugiaos.push_back(chitietphieugiao);
  }
  file.close();
  return chitietphieugiaos;
}
void ChiTietPhieuGiao::display(vector<ChiTietPhieuGiao> &chitietphieugiaos)
{
  for (auto &chitietphieugiao : chitietphieugiaos)
  {
    cout << "So phieu giao: " << chitietphieugiao.getSoPhieuGiao() << endl;
    cout << "Ma vat tu: " << chitietphieugiao.getMaVatTu() << endl;
    cout << "So luong giao: " << chitietphieugiao.getSoLuongGiao() << endl;
    cout << "Don gia giao: " << chitietphieugiao.getDonGiaGiao() << endl;
    cout << "--------------------------------" << endl;
  }
}
vector<ChiTietPhieuGiao> ChiTietPhieuGiao::add(vector<ChiTietPhieuGiao> &chitietphieugiaos, vector<Vattu> &vattus, vector<PhieuGiao> &phieugiaos)
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
  for (auto &vattu : vattus)
  {
    if (vattu.getMaVatu() == maVatTu)
    {
      isVattuExist = true;
      break;
    }
  }
  for (auto &phieugiao : phieugiaos)
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
    return chitietphieugiaos;
  }
  if (!isPhieuGiaoExist)
  {
    cout << "So phieu giao khong ton tai!" << endl;
    return chitietphieugiaos;
  }
  ChiTietPhieuGiao chitietphieugiao(soPhieuGiao, maVatTu, soLuongGiao, donGiaGiao);
  chitietphieugiaos.push_back(chitietphieugiao);
  ofstream file("chitietphieugiao.csv");
  for (auto &chitietphieugiao : chitietphieugiaos)
  {
    file << chitietphieugiao.getSoPhieuGiao() << "," << chitietphieugiao.getMaVatTu() << "," << chitietphieugiao.getSoLuongGiao() << "," << chitietphieugiao.getDonGiaGiao() << endl;
  }
  return chitietphieugiaos;
}
vector<ChiTietPhieuGiao> ChiTietPhieuGiao::update(vector<ChiTietPhieuGiao> &chitietphieugiaos, vector<Vattu> &vattus, vector<PhieuGiao> &phieugiaos)
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
  for (auto &vattu : vattus)
  {
    if (vattu.getMaVatu() == maVatTu)
    {
      isVattuExist = true;
      break;
    }
  }
  for (auto &phieugiao : phieugiaos)
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
    return chitietphieugiaos;
  }
  if (!isPhieuGiaoExist)
  {
    cout << "So phieu giao khong ton tai!" << endl;
    return chitietphieugiaos;
  }
  for (auto &chitietphieugiao : chitietphieugiaos)
  {
    if (chitietphieugiao.getSoPhieuGiao() == soPhieuGiao && chitietphieugiao.getMaVatTu() == maVatTu)
    {
      chitietphieugiao.setSoLuongGiao(soLuongGiao);
      chitietphieugiao.setDonGiaGiao(donGiaGiao);
      break;
    }
  }
  return chitietphieugiaos;
}
vector<ChiTietPhieuGiao> ChiTietPhieuGiao::remove(vector<ChiTietPhieuGiao> &chitietphieugiaos, vector<Vattu> &vattus, vector<PhieuGiao> &phieugiaos)
{
  string soPhieuGiao, maVatTu;
  cin.ignore();
  cout << "Nhap so phieu giao: ";
  getline(cin, soPhieuGiao);
  cout << "Nhap ma vat tu: ";
  getline(cin, maVatTu);
  bool isVattuExist = false;
  bool isPhieuGiaoExist = false;
  for (auto &vattu : vattus)
  {
    if (vattu.getMaVatu() == maVatTu)
    {
      isVattuExist = true;
      break;
    }
  }
  for (auto &phieugiao : phieugiaos)
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
    return chitietphieugiaos;
  }
  if (!isPhieuGiaoExist)
  {
    cout << "So phieu giao khong ton tai!" << endl;
    return chitietphieugiaos;
  }
  for (auto it = chitietphieugiaos.begin(); it != chitietphieugiaos.end();)
  {
    if (it->getSoPhieuGiao() == soPhieuGiao && it->getMaVatTu() == maVatTu)
    {
      it = chitietphieugiaos.erase(it);
    }
    else
    {
      ++it;
    }
  }
  ofstream file("chitietphieugiao.csv");
  for (auto &chitietphieugiao : chitietphieugiaos)
  {
    file << chitietphieugiao.getSoPhieuGiao() << "," << chitietphieugiao.getMaVatTu() << "," << chitietphieugiao.getSoLuongGiao() << "," << chitietphieugiao.getDonGiaGiao() << endl;
  }
  file.close();
  return chitietphieugiaos;
}
void ChiTietPhieuGiao::totalAmount(vector<ChiTietPhieuGiao> &chitietphieugiaos, vector<Vattu> &vattus, vector<PhieuGiao> &phieugiaos)
{
  string soPhieuGiao;
  cout << "Nhap so phieu giao: ";
  cin >> soPhieuGiao;
  bool isPhieuGiaoExist = false;
  for (auto &phieugiao : phieugiaos)
  {
    if (phieugiao.getSoPhieuGiao() == soPhieuGiao)
    {
      isPhieuGiaoExist = true;
      break;
    }
  }
  if (!isPhieuGiaoExist)
  {
    cout << "So phieu giao khong ton tai!" << endl;
    return;
  }
  int totalAmount = 0;
  for (auto &chitietphieugiao : chitietphieugiaos)
  {
    if (chitietphieugiao.getSoPhieuGiao() == soPhieuGiao)
    {
      for (auto &vattu : vattus)
      {
        if (vattu.getMaVatu() == chitietphieugiao.getMaVatTu())
        {
          totalAmount += chitietphieugiao.getSoLuongGiao() * chitietphieugiao.getDonGiaGiao();
          break;
        }
      }
    }
  }
  cout << "Tong so tien cua phieu giao " << soPhieuGiao << " la: " << totalAmount << endl;
}
void ChiTietPhieuGiao::totalAmountByTime(vector<ChiTietPhieuGiao> &chitietphieugiaos, vector<Vattu> &vattus, vector<PhieuGiao> &phieugiaos)
{
  string startTime, endTime;
  cout << "Nhap thoi gian bat dau: ";
  cin >> startTime;
  cout << "Nhap thoi gian ket thuc: ";
  cin >> endTime;
  for (auto &phieugiao : phieugiaos)
  {
    if (phieugiao.getNgayGiao() >= startTime && phieugiao.getNgayGiao() <= endTime)
    {
      cout << "So phieu giao: " << phieugiao.getSoPhieuGiao() << endl;
      cout << "Ngay giao: " << phieugiao.getNgayGiao() << endl;
      cout << "Noi giao: " << phieugiao.getNoiGiao() << endl;
      int totalAmount = 0;
      for (auto &chitietphieugiao : chitietphieugiaos)
      {
        if (chitietphieugiao.getSoPhieuGiao() == phieugiao.getSoPhieuGiao())
        {
          for (auto &vattu : vattus)
          {
            if (vattu.getMaVatu() == chitietphieugiao.getMaVatTu())
            {
              totalAmount += chitietphieugiao.getSoLuongGiao() * chitietphieugiao.getDonGiaGiao();
              break;
            }
          }
        }
      }
      cout << "Tong so tien: " << totalAmount << endl;
      cout << "--------------------------------" << endl;
    }
  }
}
void ChiTietPhieuGiao::totalAmountByTimeRange(vector<ChiTietPhieuGiao> &chitietphieugiaos, vector<Vattu> &vattus, vector<PhieuGiao> &phieugiaos)
{
  string startTime, endTime;
  cout << "Nhap thoi gian bat dau: ";
  cin >> startTime;
  cout << "Nhap thoi gian ket thuc: ";
  cin >> endTime;
  int totalAmount = 0;
  for (auto &phieugiao : phieugiaos)
  {
    if (phieugiao.getNgayGiao() >= startTime && phieugiao.getNgayGiao() <= endTime)
    {
      for (auto &chitietphieugiao : chitietphieugiaos)
      {
        if (chitietphieugiao.getSoPhieuGiao() == phieugiao.getSoPhieuGiao())
        {
          for (auto &vattu : vattus)
          {
            if (vattu.getMaVatu() == chitietphieugiao.getMaVatTu())
            {
              totalAmount += chitietphieugiao.getSoLuongGiao() * chitietphieugiao.getDonGiaGiao();
              break;
            }
          }
        }
      }
    }
  }
  cout << "Tong so tien: " << totalAmount << endl;
}
void ChiTietPhieuGiao::backup(vector<ChiTietPhieuGiao> &chitietphieugiaos)
{
  ofstream file("chitietphieugiao_backup.csv");
  for (auto &chitietphieugiao : chitietphieugiaos)
  {
    file << chitietphieugiao.getSoPhieuGiao() << "," << chitietphieugiao.getMaVatTu() << "," << chitietphieugiao.getSoLuongGiao() << "," << chitietphieugiao.getDonGiaGiao() << endl;
  }
  file.close();
}
void ChiTietPhieuGiao::restore(vector<ChiTietPhieuGiao> &chitietphieugiaos)
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
    chitietphieugiaos.push_back(chitietphieugiao);
    ofstream file("chitietphieugiao.csv", ios::app);
    file << soPhieuGiao << "," << maVatTu << "," << soLuongGiao << "," << donGiaGiao << endl;
  }
  file.close();
}