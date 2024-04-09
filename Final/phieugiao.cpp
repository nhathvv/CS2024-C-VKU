#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "phieugiao.h"
using namespace std;
PhieuGiao::PhieuGiao(){};
PhieuGiao::PhieuGiao(string soPhieuGiao, string ngayGiao, string noiGiao, string maKH)
{
  this->soPhieuGiao = soPhieuGiao;
  this->ngayGiao = ngayGiao;
  this->noiGiao = noiGiao;
  this->maKH = maKH;
}
void PhieuGiao::setSoPhieuGiao(string soPhieuGiao)
{
  this->soPhieuGiao = soPhieuGiao;
}
void PhieuGiao::setNgayGiao(string ngayGiao)
{
  this->ngayGiao = ngayGiao;
}
void PhieuGiao::setNoiGiao(string noiGiao)
{
  this->noiGiao = noiGiao;
}
void PhieuGiao::setMaKH(string maKH)
{
  this->maKH = maKH;
}

string PhieuGiao::getSoPhieuGiao()
{
  return soPhieuGiao;
}
string PhieuGiao::getNgayGiao()
{
  return ngayGiao;
}
string PhieuGiao::getNoiGiao()
{
  return noiGiao;
}
string PhieuGiao::getMaKH()
{
  return maKH;
}

vector<PhieuGiao> PhieuGiao::getData(string filename, vector<PhieuGiao> &dsPhieuGiao)
{
  ifstream file(filename);
  if (!file.is_open())
  {
    cout << "File not found!";
    return dsPhieuGiao;
  }
  string soPhieuGiao, ngayGiao, noiGiao, maKH;
  while (getline(file, soPhieuGiao, ',') && getline(file, ngayGiao, ',') && getline(file, noiGiao, ',') && getline(file, maKH, '\n'))
  {
    PhieuGiao phieugiao(soPhieuGiao, ngayGiao, noiGiao, maKH);
    dsPhieuGiao.push_back(phieugiao);
  }
  file.close();
  return dsPhieuGiao;
}
void PhieuGiao::display(vector<PhieuGiao> &dsPhieuGiao)
{
  for (auto &phieugiao : dsPhieuGiao)
  {
    cout << "So phieu giao: " << phieugiao.getSoPhieuGiao() << endl;
    cout << "Ngay giao: " << phieugiao.getNgayGiao() << endl;
    cout << "Noi giao: " << phieugiao.getNoiGiao() << endl;
    cout << "Ma khach hang: " << phieugiao.getMaKH() << endl;
    cout << "-------------------" << endl;
  }
}
vector<PhieuGiao> PhieuGiao::add(vector<PhieuGiao> &dsPhieuGiao)
{
  string soPhieuGiao, ngayGiao, noiGiao, maKH;
  cin.ignore();
  cout << "Nhap so phieu giao: ";
  getline(cin, soPhieuGiao);
  cout << "Nhap ngay giao: ";
  getline(cin, ngayGiao);
  cout << "Nhap noi giao: ";
  getline(cin, noiGiao);
  cout << "Nhap ma khach hang: ";
  getline(cin, maKH);
  PhieuGiao phieugiao(soPhieuGiao, ngayGiao, noiGiao, maKH);
  dsPhieuGiao.push_back(phieugiao);
  ofstream file("phieugiao.csv", ios::app);
  file << soPhieuGiao << "," << ngayGiao << "," << noiGiao << "," << maKH << endl;
  file.close();
  return dsPhieuGiao;
}
vector<PhieuGiao> PhieuGiao::update(vector<PhieuGiao> &dsPhieuGiao)
{
  string soPhieuGiao, ngayGiao, noiGiao, maKH;
  cin.ignore();
  cout << "Nhap so phieu giao can sua: ";
  getline(cin, soPhieuGiao);
  for (auto &phieugiao : dsPhieuGiao)
  {
    if (phieugiao.getSoPhieuGiao() == soPhieuGiao)
    {
      cout << "Nhap ngay giao: ";
      getline(cin, ngayGiao);
      cout << "Nhap noi giao: ";
      getline(cin, noiGiao);
      cout << "Nhap ma khach hang: ";
      getline(cin, maKH);
      phieugiao.setNgayGiao(ngayGiao);
      phieugiao.setNoiGiao(noiGiao);
      phieugiao.setMaKH(maKH);
      ofstream file("phieugiao.csv");
      for (auto &phieugiao : dsPhieuGiao)
      {
        file << phieugiao.getSoPhieuGiao() << "," << phieugiao.getNgayGiao() << "," << phieugiao.getNoiGiao() << "," << phieugiao.getMaKH() << endl;
      }
      file.close();
    }
  }
  return dsPhieuGiao;
}
vector<PhieuGiao> PhieuGiao::remove(vector<PhieuGiao> &dsPhieuGiao)
{
  string soPhieuGiao;
  cin.ignore();
  cout << "Nhap so phieu giao can xoa: ";
  getline(cin, soPhieuGiao);
  for (auto it = dsPhieuGiao.begin(); it != dsPhieuGiao.end();)
  {
    if (it->getSoPhieuGiao() == soPhieuGiao)
    {
      it = dsPhieuGiao.erase(it);
      ofstream file("phieugiao.csv");
      for (auto &phieugiao : dsPhieuGiao)
      {
        file << phieugiao.getSoPhieuGiao() << "," << phieugiao.getNgayGiao() << "," << phieugiao.getNoiGiao() << "," << phieugiao.getMaKH() << endl;
      }
    }
    else
    {
      it++;
    }
  }
  return dsPhieuGiao;
}
void PhieuGiao::backup(vector<PhieuGiao> &dsPhieuGiao)
{
  ofstream file("phieugiao.backup.csv");
  for (auto &phieugiao : dsPhieuGiao)
  {
    file << phieugiao.getSoPhieuGiao() << "," << phieugiao.getNgayGiao() << "," << phieugiao.getNoiGiao() << "," << phieugiao.getMaKH() << endl;
  }
  file.close();
}
void PhieuGiao::restore(vector<PhieuGiao> &dsPhieuGiao)
{
  ifstream file("phieugiao.backup.csv");
  if (!file.is_open())
  {
    cout << "File not found!";
    return;
  }
  string soPhieuGiao, ngayGiao, noiGiao, maKH;
  while (getline(file, soPhieuGiao, ',') && getline(file, ngayGiao, ',') && getline(file, noiGiao, ',') && getline(file, maKH, '\n'))
  {
    PhieuGiao phieugiao(soPhieuGiao, ngayGiao, noiGiao, maKH);
    dsPhieuGiao.push_back(phieugiao);
    ofstream file("phieugiao.csv", ios::app);
    file << soPhieuGiao << "," << ngayGiao << "," << noiGiao << "," << maKH << endl;
  }
  file.close();
}