#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "chitietphieugiao.h"
#include "vattu.h"
#include "phieugiao.h"
using namespace std;

bool compareSecond(const std::pair<string, int> &a, const std::pair<string, int> &b) {
    return a.second > b.second;
}
void ChiTietPhieuGiao::topNVattuByPrice(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu)
{
  int n;
  cout << "Nhap so luong vat tu co gia cao nhat: ";
  cin >> n;
  vector<pair<string, int> > mostExpensiveItems;
  for (auto &vattu : dsVattu)
  {
    int totalAmount = 0;
    for (auto &chitietphieugiao : dsChiTietPhieuGiao)
    {
      if (chitietphieugiao.getMaVatTu() == vattu.getMaVatu())
      {
        totalAmount = chitietphieugiao.getDonGiaGiao();
      }
    }
    mostExpensiveItems.push_back(make_pair(vattu.getMaVatu(), totalAmount));
  }
  sort(mostExpensiveItems.begin(), mostExpensiveItems.end(), compareSecond);

  for (int i = 0; i < n; i++)
  {
    cout << "Ma vat tu: " << mostExpensiveItems[i].first << endl;
    cout << "Don gia: " << mostExpensiveItems[i].second << endl;
    cout << "--------------------------------" << endl;
  }
}

void ChiTietPhieuGiao::totalAmount(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu, vector<PhieuGiao> &dsPhieuGiao)
{
  string soPhieuGiao;
  cout << "Nhap so phieu giao: ";
  cin >> soPhieuGiao;
  bool isPhieuGiaoExist = false;
  for (auto &phieugiao : dsPhieuGiao)
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
  for (auto &chitietphieugiao : dsChiTietPhieuGiao)
  {
    if (chitietphieugiao.getSoPhieuGiao() == soPhieuGiao)
    {
      for (auto &vattu : dsVattu)
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

void ChiTietPhieuGiao::totalAmountByTime(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu, vector<PhieuGiao> &dsPhieuGiao)
{
  string startTime, endTime;
  cout << "Nhap thoi gian bat dau: ";
  cin >> startTime;
  cout << "Nhap thoi gian ket thuc: ";
  cin >> endTime;
  for (auto &phieugiao : dsPhieuGiao)
  {
    if (phieugiao.getNgayGiao() >= startTime && phieugiao.getNgayGiao() <= endTime)
    {
      cout << "So phieu giao: " << phieugiao.getSoPhieuGiao() << endl;
      cout << "Ngay giao: " << phieugiao.getNgayGiao() << endl;
      cout << "Noi giao: " << phieugiao.getNoiGiao() << endl;
      int totalAmount = 0;
      for (auto &chitietphieugiao : dsChiTietPhieuGiao)
      {
        if (chitietphieugiao.getSoPhieuGiao() == phieugiao.getSoPhieuGiao())
        {
          for (auto &vattu : dsVattu)
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

void ChiTietPhieuGiao::topNVattuBySL(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu)
{
  int n;
  cout << "Nhap so luong vat tu ban chay nhat: ";
  cin >> n;
  vector<pair<string, int> > mostSoldItems;
  for (auto &vattu : dsVattu)
  {
    int totalAmount = 0;
    for (auto &chitietphieugiao : dsChiTietPhieuGiao)
    {
      if (chitietphieugiao.getMaVatTu() == vattu.getMaVatu())
      {
        totalAmount += chitietphieugiao.getSoLuongGiao();
      }
    }
    mostSoldItems.push_back(make_pair(vattu.getMaVatu(), totalAmount));
  }
  sort(mostSoldItems.begin(), mostSoldItems.end(), compareSecond);

  for (int i = 0; i < n; i++)
  {
    cout << "Ma vat tu: " << mostSoldItems[i].first << endl;
    cout << "So luong: " << mostSoldItems[i].second << endl;
    cout << "--------------------------------" << endl;
  }
}

void ChiTietPhieuGiao::totalAmountByTimeRange(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu, vector<PhieuGiao> &dsPhieuGiao)
{
  string startTime, endTime;
  cout << "Nhap thoi gian bat dau: ";
  cin >> startTime;
  cout << "Nhap thoi gian ket thuc: ";
  cin >> endTime;
  int totalAmount = 0;
  for (auto &phieugiao : dsPhieuGiao)
  {
    if (phieugiao.getNgayGiao() >= startTime && phieugiao.getNgayGiao() <= endTime)
    {
      for (auto &chitietphieugiao : dsChiTietPhieuGiao)
      {
        if (chitietphieugiao.getSoPhieuGiao() == phieugiao.getSoPhieuGiao())
        {
          for (auto &vattu : dsVattu)
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

