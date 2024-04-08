#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "vattu.h"
#include "phieugiao.h"
#include "chitietphieugiao.h"
using namespace std;
int main()
{
  vector<Vattu> vattus;
  vector<PhieuGiao> phieugiaos;
  vector<ChiTietPhieuGiao> chitietphieugiaos;
  vattus = Vattu::getData("vattu.csv", vattus);
  phieugiaos = PhieuGiao::getData("phieugiao.csv", phieugiaos);
  chitietphieugiaos = ChiTietPhieuGiao::getData("chitietphieugiao.csv", chitietphieugiaos);
  int choice;
  int subChoice;
  while (true)
  {
    cout << "1. Thêm, sửa, xóa, đọc các bảng dữ liệu" << endl;
    cout << "3. Tổng tiền của một phiếu giao" << endl;
    cout << "4. Tổng tiền của các phiếu giao trong khoảng thời gian" << endl;
    cout << "5. Vật tư bán chạy nhất" << endl;
    cout << "6. Tổng tiền của tất cả các phiếu giao trong khoảng thời gian" << endl;
    cout << "7. Sao lưu dư liệu" << endl;
    cout << "8. Phục hồi dữ liệu" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "1. Vật tư" << endl;
      cout << "2. Phiếu giao" << endl;
      cout << "3. Chi tiết phiếu giao" << endl;
      cin >> subChoice;
      switch (subChoice)
      {
      case 1:
        cout << "1. Thêm" << endl;
        cout << "2. Sửa" << endl;
        cout << "3. Xóa" << endl;
        cout << "4. Đọc" << endl;
        cin >> subChoice;
        switch (subChoice)
        {
        case 1:
          Vattu::add(vattus);
          break;
        case 2:
          Vattu::update(vattus);
          break;
        case 3:
          Vattu::remove(vattus);
          break;
        case 4:
          Vattu::display(vattus);
          break;
        default:
          cout << "Invalid choice!" << endl;
        }
        break;
      case 2:
      {
        cout << "1. Thêm" << endl;
        cout << "2. Sửa" << endl;
        cout << "3. Xóa" << endl;
        cout << "4. Đọc" << endl;
        cin >> subChoice;
        switch (subChoice)
        {
        case 1:
          PhieuGiao::add(phieugiaos);
          break;
        case 2:
          PhieuGiao::update(phieugiaos);
          break;
        case 3:
          PhieuGiao::remove(phieugiaos);
          break;
        case 4:
          PhieuGiao::display(phieugiaos);
          break;
        default:
          cout << "Invalid choice!" << endl;
        }
        break;
      case 3:
      {
        cout << "1. Thêm" << endl;
        cout << "2. Sửa" << endl;
        cout << "3. Xóa" << endl;
        cout << "4. Đọc" << endl;
        cin >> subChoice;
        switch (subChoice)
        {
        case 1:
          ChiTietPhieuGiao::add(chitietphieugiaos, vattus, phieugiaos);
          break;
        case 2:
          ChiTietPhieuGiao::update(chitietphieugiaos, vattus, phieugiaos);
          break;
        case 3:
          ChiTietPhieuGiao::remove(chitietphieugiaos, vattus, phieugiaos);
          break;
        case 4:
          ChiTietPhieuGiao::display(chitietphieugiaos);
          break;
        default:
          cout << "Invalid choice!" << endl;
        }
        break;
      }
      }
      }
    case 3:
    {
      ChiTietPhieuGiao::totalAmount(chitietphieugiaos, vattus, phieugiaos);
      break;
    }
    case 4:
    {
      ChiTietPhieuGiao::totalAmountByTime(chitietphieugiaos, vattus, phieugiaos);
      break;
    }
    case 5:
    {
      // ChiTietPhieuGiao::mostSoldSupplies(chitietphieugiaos, vattus, phieugiaos);
      break;
    }
    case 6:
    {
      ChiTietPhieuGiao::totalAmountByTimeRange(chitietphieugiaos, vattus, phieugiaos);
      break;
    }
    case 7:
    {
      cout << "1. Vật tư" << endl;
      cout << "2. Phiếu giao" << endl;
      cout << "3. Chi tiết phiếu giao" << endl;
      cin >> subChoice;
      switch (subChoice)
      {
      case 1:
        Vattu::backup(vattus);
        break;
      case 2:
        PhieuGiao::backup(phieugiaos);
        break;
      case 3:
        ChiTietPhieuGiao::backup(chitietphieugiaos);
        break;
      default:
        cout << "Invalid choice!" << endl;
        break;
      }
      break;
    }
    case 8:
    {
      cout << "1. Vật tư" << endl;
      cout << "2. Phiếu giao" << endl;
      cout << "3. Chi tiết phiếu giao" << endl;
      cin >> subChoice;
      switch (subChoice)
      {
      case 1:
        Vattu::restore(vattus);
        break;
      case 2:
        PhieuGiao::restore(phieugiaos);
        break;
      case 3:
        ChiTietPhieuGiao::restore(chitietphieugiaos);
        break;
      default:
        cout << "Invalid choice!" << endl;
        break;
      }
      break;
    }
    }
  }
}