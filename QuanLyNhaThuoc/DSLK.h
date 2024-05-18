#pragma once
#include<string>
using namespace std;
struct Thuoc
{
    string mathuoc;
    string tenthuoc;
    string thanhphan;
    string congdung;
    string ghichu;
    int soluong;
    tm NgaySX;
    tm NgayHH;
};
struct ThuocNode
{
    Thuoc data;
    ThuocNode *Next;
};
struct HoaDonNhap
{
    string maHDNhap;
    tm NgayNhap;
    string diengiai;
    string mathuoc;
    string solo;
    string tenthuoc;
    string thanhphan;
    string congdung;
    string ghichu;
    int soluong;
    tm NgaySX;
    tm NgayHH;
    string Congty;
};
struct HDNhapNode
{
    HoaDonNhap data;
    HDNhapNode* Next;
};
struct HoaDonXuat
{
    string maHDXuat;
    tm NgayXuat;
    string diengiai;
    string mathuoc;
    string solo;
    int soluong;
    string NguoiMua;
};
struct HDXuatNode
{
    HoaDonXuat data;
    HDXuatNode* Next;
};

struct QueueThuoc
{
    ThuocNode* head,*tail;
    QueueThuoc *Next;
};

struct QueueHDNhap
{
    HDNhapNode* head,*tail;
};

struct QueueHDXuat
{
    HDXuatNode* head,*tail;
};
struct DSQueueThuoc
{
    QueueThuoc *head,*tail;
};
//1 DS Thuốc  (DSLK - Mỗi Node là 1 Queue Thuốc) - MỖI QUEUE THUỐC LÀ 1 MÃ THUỐC DUY NHẤT
// 1 Queue Thuốc sẽ có nhiều Node Thuốc ( theo FIFO ) 
//2 DS Hóa Đơn ( DSLK - Queue // không có FIFO )