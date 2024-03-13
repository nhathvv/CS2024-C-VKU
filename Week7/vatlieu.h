#ifndef vattu_h
#define vattu_h

#include <iostream>
#include <string>
using namespace std;
class Vattu {
    string maVattu;
    string tenVattu;
    string donViTinh;
    public:
        Vattu();
        Vattu(string maVattu, string tenVattu, string donViTinh);

        void setMaVattu(string maVattu);
        void setTenVattu(string tenVattu);
        void setDonViTinh(string donViTinh);

        string getMaVattu();
        string getTenVattu();
        string getDonViTinh();
};
class PhieuGiaoHang {
    string soPhieuGiao;
    string ngayGiao;
    string noiGiao;
    string maKH;
    public:
        PhieuGiaoHang();
        PhieuGiaoHang(string soPhieuGiao,string ngayGiao, string noiGiao,string maKH);
        void setSoPhieuGiao(string soPhieuGiao);
        void setNgayGiao(string ngayGiao);
        void setNoiGiao(string noiGiao);
        void setMaKH(string maKH);

        string getSoPhieuGiao();
        string getNgayGiao();
        string getNoiGiao();
        string getMaKH();
};
class chiTietPhieuGiao {
    string soPhieuGiao;
    string maVatTu;
    string soLuongGiao;
    string donViGiao;
    public:
        chiTietPhieuGiao();
        chiTietPhieuGiao(string soPhieuGiao,string maVatTu,string soLuongGiao,string donViGiao);

        void setSoPhieuGiao(string soPhieuGiao);
        void setMaVatTu(string maVatTu);
        void setSoLuongGiao(string soLuongGiao);
        void setDonViGiao(string donViGiao);

        string getSoPhieuGiao();
        string getMaVatTu();
        string getSoluongGiao();
        string getDonViGiao();
};
#endif