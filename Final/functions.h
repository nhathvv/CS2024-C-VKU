#include <iostream>
#include <string>
#include <vector>
#include "chitietphieugiao.h"
#include "vattu.h"
#include "phieugiao.h"
void topNVattuBySL(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu);
void totalAmount(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu, vector<PhieuGiao> &dsPhieuGiao);
void totalAmountByTime(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu, vector<PhieuGiao> &dsPhieuGiao);
void topNVattuByPrice(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu);
void totalAmountByTimeRange(vector<ChiTietPhieuGiao> &dsChiTietPhieuGiao, vector<Vattu> &dsVattu, vector<PhieuGiao> &dsPhieuGiao);
