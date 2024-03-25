#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "vatlieu.h"
using namespace std;

vector<Vattu> Vattu::getData(string filename, vector<Vattu> &vattus)
{
  ifstream inputFile(filename);
  if (!inputFile.is_open())
  {
    cout << "Failed to open file for reading." << endl;
    return vector<Vattu>();
  }
  string maVattu, tenVattu, donViTinh;
  while (getline(inputFile, maVattu, ',') &&
         getline(inputFile, tenVattu, ',') &&
         getline(inputFile, donViTinh))
  {
    Vattu vattu(maVattu, tenVattu, donViTinh);
    vattus.push_back(vattu);
  }
  inputFile.close();
  return vattus;
}
// Display
void Vattu::display(vector<Vattu> vattus)
{
  for (auto &vattu : vattus)
  {
    cout << "Ma vat tu: " << vattu.getMaVattu() << endl;
    cout << "Ten vat tu: " << vattu.getTenVattu() << endl;
    cout << "Don vi tinh: " << vattu.getDonViTinh() << endl;
  }
}
// Add
vector<Vattu>Vattu::add(vector<Vattu> &vattus)
{
  string maVattu, tenVattu, donViTinh;
  cout << "Nhap ma vat tu: ";
  getline(cin, maVattu);
  cout << "Nhap ten vat tu: ";
  getline(cin, tenVattu);
  cout << "Nhap don vi tinh: ";
  getline(cin, donViTinh);
  Vattu vattu(maVattu, tenVattu, donViTinh);
  vattus.push_back(vattu);
  cout << "Da them vat tu thanh cong!" << endl;
  ofstream fileOut("vattu.csv", ios::app);
  fileOut << vattu.getMaVattu() << "," << vattu.getTenVattu() << "," << vattu.getDonViTinh() << endl;
  fileOut.close();
  return vattus;
}
// Update
void Vattu::update(vector<Vattu> &vattus)
{
  string maVattu;
  cout << "Nhap ma vat tu can sua: ";
  cin >> maVattu;
  for (auto &vattu : vattus)
  {
    if (vattu.getMaVattu() == maVattu)
    {
      string tenVattu, donViTinh;
      cout << "Nhap ten vat tu: ";
      cin >> tenVattu;
      cout << "Nhap don vi tinh: ";
      cin >> donViTinh;
      vattu.setTenVattu(tenVattu);
      vattu.setDonViTinh(donViTinh);
      cout << "Da sua vat tu thanh cong!" << endl;
      return;
    }
  }
  ofstream fileOut("vattu.csv");
  for (auto &vattu : vattus)
  {
    fileOut << vattu.getMaVattu() << "," << vattu.getTenVattu() << "," << vattu.getDonViTinh() << endl;
  }
  fileOut.close();
}
// Remove
void Vattu::remove(vector<Vattu> &vattus)
{
  string maVattu;
  cout << "Nhap ma vat tu can xoa: ";
  cin >> maVattu;
  for (auto it = vattus.begin(); it != vattus.end(); it++)
  {
    if (it->getMaVattu() == maVattu)
    {
      vattus.erase(it);
      cout << "Da xoa vat tu thanh cong!" << endl;
      return;
    }
  }
  ofstream fileOut("vattu.csv");
  for (auto &vattu : vattus)
  {
    fileOut << vattu.getMaVattu() << "," << vattu.getTenVattu() << "," << vattu.getDonViTinh() << endl;
  }
  fileOut.close();
}
int main()
{
  vector<Vattu> vattus;
  Vattu::remove(vattus);
  return 0;
}