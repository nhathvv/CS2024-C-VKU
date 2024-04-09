#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "vattu.h"
#include "phieugiao.h"
#include "chitietphieugiao.h"
#include "functions.h"
using namespace std;
int main()
{
  vector<Vattu> dsVattu;
  vector<PhieuGiao> dsPhieuGiao;
  vector<ChiTietPhieuGiao> dsChiTietPhieuGiao;
  Vattu vattus;
  PhieuGiao phieugiaos;
  ChiTietPhieuGiao chitietphieugiaos;
  dsVattu = vattus.getData("vattu.csv", dsVattu);
  dsPhieuGiao = phieugiaos.getData("phieugiao.csv", dsPhieuGiao);
  dsChiTietPhieuGiao = chitietphieugiaos.getData("chitietphieugiao.csv", dsChiTietPhieuGiao);
  int choice;
  int subChoice;
  while (true)
  {
    cout << "1. Thêm, sửa, xóa, đọc các bảng dữ liệu" << endl;
    cout << "2. N vật tư có giá cao nhất" << endl;
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
        cout << "1. Thêm vật tư" << endl;
        cout << "2. Sửa vật tư" << endl;
        cout << "3. Xóa vật tư" << endl;
        cout << "4. Hiển thị vật tư" << endl;
        cin >> subChoice;
        switch (subChoice)
        {
        case 1:
          vattus.add(dsVattu);
          break;
        case 2:
          vattus.update(dsVattu);
          break;
        case 3:
          vattus.remove(dsVattu);
          break;
        case 4:
          vattus.display(dsVattu);
          break;
        default:
          cout << "Invalid choice!" << endl;
        }
        break;
      case 2:
      {
        cout << "1. Thêm phiếu giao" << endl;
        cout << "2. Sửa phiếu giao" << endl;
        cout << "3. Xóa phiếu giao" << endl;
        cout << "4. Đọc phiếu giao" << endl;
        cin >> subChoice;
        switch (subChoice)
        {
        case 1:
          phieugiaos.add(dsPhieuGiao);
          break;
        case 2:
          phieugiaos.update(dsPhieuGiao);
          break;
        case 3:
          phieugiaos.remove(dsPhieuGiao);
          break;
        case 4:
          phieugiaos.display(dsPhieuGiao);
          break;
        default:
          cout << "Invalid choice!" << endl;
        }
        break;
      case 3:
      {
        cout << "1. Thêm chi tiết phiếu giao" << endl;
        cout << "2. Sửa chi tiết phiếu giao" << endl;
        cout << "3. Xóa chi tiết phiếu giao" << endl;
        cout << "4. Hiển thị" << endl;
        cin >> subChoice;
        switch (subChoice)
        {
        case 1:
          chitietphieugiaos.add(dsChiTietPhieuGiao, dsVattu, dsPhieuGiao);
          break;
        case 2:
          chitietphieugiaos.update(dsChiTietPhieuGiao, dsVattu, dsPhieuGiao);
          break;
        case 3:
          chitietphieugiaos.remove(dsChiTietPhieuGiao, dsVattu, dsPhieuGiao);
          break;
        case 4:
          chitietphieugiaos.display(dsChiTietPhieuGiao);
          break;
        default:
          cout << "Invalid choice!" << endl;
        }
        break;
      }
      }
      }
      break;
    case 2:
    {
     topNVattuByPrice(dsChiTietPhieuGiao, dsVattu);
      break;
    }
    case 3:
    {
     totalAmount(dsChiTietPhieuGiao, dsVattu, dsPhieuGiao);
      break;
    }
    case 4:
    {
     totalAmountByTime(dsChiTietPhieuGiao, dsVattu, dsPhieuGiao);
      break;
    }
    case 5:
    {
     topNVattuBySL(dsChiTietPhieuGiao, dsVattu);
      break;
    }
    case 6:
    {
     totalAmountByTimeRange(dsChiTietPhieuGiao, dsVattu, dsPhieuGiao);
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
        vattus.backup(dsVattu);
        break;
      case 2:
        phieugiaos.backup(dsPhieuGiao);
        break;
      case 3:
        chitietphieugiaos.backup(dsChiTietPhieuGiao);
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
        vattus.restore(dsVattu);
        break;
      case 2:
        phieugiaos.restore(dsPhieuGiao);
        break;
      case 3:
        chitietphieugiaos.restore(dsChiTietPhieuGiao);
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