#pragma once
#pragma warning( disable : 4996 )
#include<time.h>
#include"DSLK.h"
#include"mywindows.h"
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;
void Menu(DSQueueThuoc &DSQueuethuoc,QueueHDNhap &QueueHDnhap,QueueHDXuat &QueueHDxuat);
void init(DSQueueThuoc &t);
void init(QueueThuoc &t);
void init(QueueHDNhap &t);
void init(QueueHDXuat &t);
ThuocNode *CreateNode(Thuoc data);
HDNhapNode *CreateNode(HoaDonNhap data);
HDXuatNode *CreateNode(HoaDonXuat data);
void DeleteNode(QueueThuoc *&p);
void DeleteNode(ThuocNode *&p);
void DeleteNode(HDNhapNode *&p);
void DeleteNode(HDXuatNode *&p);
void DeleteMidList(DSQueueThuoc& t, QueueThuoc*& q);
void Xuat(Thuoc data);
void Xuat(HoaDonNhap data);
void Xuat(HoaDonXuat data);
void XuatTatCa(DSQueueThuoc t);
void XuatTatCa(QueueHDNhap t);
void XuatTatCa(QueueHDXuat t);
Thuoc ConvertFromHDNhap(HoaDonNhap b);
void Pop(QueueThuoc &t);
void Pop(QueueThuoc &t,int &soluong);
void Push(QueueThuoc &t,ThuocNode *p);
void Push(DSQueueThuoc &thuoc,QueueHDNhap &t,HDNhapNode *p);
void Push(DSQueueThuoc &thuoc,QueueHDXuat &t,HDXuatNode *p);
void AddQueueThuoc(DSQueueThuoc &DS,ThuocNode *p);
tm GetLocalTime();
tm SetStructTM(int year, int month, int day);
int compare_tm(struct tm tm1, struct tm tm2);
int TinhNgayChenhLech(struct tm tm1, struct tm tm2);
void PrintStructTM(tm t);
void TimThuocTheoTen(DSQueueThuoc t,string ten);
void TimThuocTheoMaThuoc(DSQueueThuoc t,string mathuoc);
Thuoc TimThuocTheoMaThuoc_Thuoc(DSQueueThuoc t, string mathuoc);
int KiemTraMaThuocTonTai(DSQueueThuoc t,string mathuoc);
int TongSoLuongTheoMaThuoc(DSQueueThuoc t,string mathuoc);
bool SoSanhGiamDan(Thuoc a,Thuoc b);
void XoaThuocHetHan(DSQueueThuoc &t);
void ThongkeThuocHSDDuoi30(DSQueueThuoc t);
void TimThuocHSDDuoi6Thang(DSQueueThuoc t);
void TimThuocCoSoLuongHon100_SapXepGiamDan(DSQueueThuoc t);
int GetMinSoLuongBan(unordered_map<string,int>ThongKe);
int GetMaxSoLuongBan(unordered_map<string,int>ThongKe);
void ThongKeThuocBan(QueueHDXuat t,int choice);
void DocFileThuoc(DSQueueThuoc& DS);
void DocFileHDNhap(DSQueueThuoc& thuoc, QueueHDNhap& t);
void DocFileHDXuat(DSQueueThuoc& thuoc, QueueHDXuat& t);
void NhapThuoc(DSQueueThuoc& t);
void NhapHDNhap(DSQueueThuoc& thuoc, QueueHDNhap& t);
void NhapHDXuat(DSQueueThuoc& thuoc, QueueHDXuat& t);

void Menu(DSQueueThuoc &DSQueuethuoc,QueueHDNhap &QueueHDnhap,QueueHDXuat &QueueHDxuat)
{
    int choice(1);
    string tmp;
    while (choice != false)
    {
        int n(1), m(2);
        system("cls");
        textcolor(12);
        printf("\n\t\t\t\tMENU NHAP XUAT THUOC\n");
        textcolor(7);
        printf("\t\t1.Them Hoa Don\n\t\t2.Tim kiem Thuoc\n\t\t3.Xuat Hoa Don\n\t\t4.Thong ke Thuoc\n\t\t5.Xoa Thuoc da het han\n\t\t0.Thoat chuong trinh\n");
        textcolor(12);
        textcolor(7);
        printf("\tNhap lua chon cua ban: ");
        cin >> choice;
        switch (choice)
        {
        case 1:
        while (n != false)
            {
                system("cls");
                textcolor(12);
                cout << "\n\t\t\t\tMENU NHAP XUAT THUOC\n";
                textcolor(7);
                cout << "\t\t1.Nhap Hoa Don Nhap\n\t\t2.Nhap Hoa Don Xuat\n\t\t3.Tao danh sach Thuoc\n\t\t0.Quay lai\n\tNhap lua chon cua ban: ";
                cin >> n;
                switch (n)
                {
                case 1:
                    textcolor(12);
                    cout << "\t\tNHAP HOA DON NHAP\n";
                    textcolor(7);
                    cout << "\tTHU CONG - 1 / FILE - 0: ";
                    cin >> m;
                    while (m != 0 && m != 1)
                    {
                        cout << "\tTHU CONG - 1 / FILE - 0: ";
                        cin >> m;
                    }
                    if (m == 0)
                        DocFileHDNhap(DSQueuethuoc, QueueHDnhap);
                    else
                        NhapHDNhap(DSQueuethuoc, QueueHDnhap);
                    break;
                case 2:
                    textcolor(12);
                    cout << "\t\tNHAP HOA DON XUAT\n";
                    textcolor(7);
                    cout << "\tTHU CONG - 1 / FILE - 0: ";
                    cin >> m;
                    while (m != 0 && m != 1)
                    {
                        cout << "\tTHU CONG - 1 / FILE - 0: ";
                        cin >> m;
                    }
                    if (m == 0)
                        DocFileHDXuat(DSQueuethuoc, QueueHDxuat);
                    else
                        NhapHDXuat(DSQueuethuoc, QueueHDxuat);
                    break;
                case 3:
                    textcolor(12);
                    cout << "\t\tNHAP THUOC\n";
                    textcolor(7);
                    cout << "\tTHU CONG - 1 / FILE - 0: ";
                    cin >> m;
                    while (m != 0 && m != 1)
                    {
                        cout << "\tTHU CONG - 1 / FILE - 0: ";
                        cin >> m;
                    }
                    if (m == 0)
                        DocFileThuoc(DSQueuethuoc);
                    else
                        NhapThuoc(DSQueuethuoc);
                    break;
                default:
                    textcolor(12);
                    if (n == 0)
                        printf("Nhan phim bat ky de quay lai");
                    else
                        printf("Khong co lua chon nay, nhan phim bat ky de nhap lai");
                    textcolor(7);
                    getch();
                    break;
                }
            }
            break;
        case 2:
            while (n != false)
            {
                system("cls");
                textcolor(12);
                cout << "\n\t\t\t\tMENU NHAP XUAT THUOC\n";
                textcolor(7);
                cout << "\t\t1.Theo Ten\n\t\t2.Theo Ma thuoc\n\t\t0.Quay lai\n\tNhap lua chon cua ban: ";
                cin >> n;
                switch (n)
                {
                case 1:
                    cout<<"Nhap ten thuoc: ";
                    cin.ignore();
                    getline(cin,tmp);
                    TimThuocTheoTen(DSQueuethuoc,tmp);
                    _getch();
                    break;
                case 2:
                    cout<<"Nhap ma thuoc: ";
                    cin.ignore();
                    getline(cin,tmp);
                    TimThuocTheoMaThuoc(DSQueuethuoc,tmp);
                    _getch();
                    break;
                default:
                    textcolor(12);
                    if (n == 0)
                        printf("Nhan phim bat ky de quay lai");
                    else
                        printf("Khong co lua chon nay, nhan phim bat ky de nhap lai");
                    textcolor(7);
                    _getch();
                    break;
                }
            }
            break;
        case 3:
            while (n != false)
            {
                system("cls");
                textcolor(12);
                cout << "\n\t\t\t\tMENU NHAP XUAT THUOC\n";
                textcolor(7);
                cout << "\t\t1.Xuat Hoa Don Nhap\n\t\t2.Xuat Hoa Don Xuat\n\t\t3.Xuat danh sach thuoc\n\t\t0.Quay lai\n\tNhap lua chon cua ban: ";
                cin >> n;
                switch (n)
                {
                case 1:
                    XuatTatCa(QueueHDnhap);
                    _getch();
                    break;
                case 2:
                    XuatTatCa(QueueHDxuat);
                    _getch();
                    break;
                case 3:
                    XuatTatCa(DSQueuethuoc);
                    _getch();
                    break;
                default:
                    textcolor(12);
                    if (n == 0)
                        printf("Nhan phim bat ky de quay lai");
                    else
                        printf("Khong co lua chon nay, nhan phim bat ky de nhap lai");
                    textcolor(7);
                    getch();
                    break;
                }
            }
            break;
        case 4:
            while (n != false)
            {
                system("cls");
                textcolor(12);
                cout << "\n\t\t\t\tMENU NHAP XUAT THUOC\n";
                textcolor(7);
                cout << "\t\t1.Thong ke thuoc ban NHIEU/IT nhat\n\t\t2.Thuoc co HSD < 6 thang\n\t\t3.Thuoc ton so luong > 100\n\t\t4.Thuoc co HSD < 30 ngay\n\t\t0.Quay lai\n\tNhap lua chon cua ban: ";
                cin >> n;
                switch (n)
                {
                case 1:
                    textcolor(12);
                    cout << "\t\tTHONG KE THUOC BAN\n";
                    textcolor(7);
                    cout << "\tNHIEU NHAT - 1 / IT NHAT - 0: ";
                    cin >> m;
                    while (m != 0 && m != 1)
                    {
                        cout << "\tNHIEU NHAT - 1 / IT NHAT - 0: ";
                        cin >> m;
                    }
                    if (m == 0)
                        ThongKeThuocBan(QueueHDxuat,0);
                    else
                        ThongKeThuocBan(QueueHDxuat,1);
                    _getch();
                    break;
                case 2:
                    TimThuocHSDDuoi6Thang(DSQueuethuoc);
                    _getch();
                    break;
                case 3:
                    TimThuocCoSoLuongHon100_SapXepGiamDan(DSQueuethuoc);
                    _getch();
                    break;
                case 4:
                    ThongkeThuocHSDDuoi30(DSQueuethuoc);
                    _getch();
                    break;
                default:
                    textcolor(12);
                    if (n == 0)
                        printf("Nhan phim bat ky de quay lai");
                    else
                        printf("Khong co lua chon nay, nhan phim bat ky de nhap lai");
                    textcolor(7);
                    getch();
                    break;
                }
            }
            break;
        case 5:
            XoaThuocHetHan(DSQueuethuoc);
            break;
        default:
            textcolor(12);
            if (choice == 0)
                printf("Nhan phim bat ky de thoat khoi chuong trinh");
            else
                printf("Khong co lua chon nay, nhan phim bat ky de nhap lai");
            textcolor(7);
            getch();
            break;
        }
    };
}
void init(DSQueueThuoc &t)
{
    t.head=t.tail=NULL;
}
void init(QueueThuoc &t)
{
    t.head=t.tail=NULL;
    t.Next=NULL;
}
void init(QueueHDNhap &t)
{
    t.head=t.tail=NULL;
}
void init(QueueHDXuat &t)
{
    t.head=t.tail=NULL;
}
tm SetStructTM(int year, int month, int day)
{
    tm a;
    a.tm_year=year-1900;
    a.tm_mon=month-1;
    a.tm_mday=day;
    a.tm_hour = 0;
    a.tm_min = 0;
    a.tm_sec = 0;
    a.tm_isdst = -1;
    return a;
}

tm GetLocalTime()
{
    time_t current_time;
    time(&current_time);
    tm a;
    a = *localtime(&current_time);
    a.tm_hour = 0;
    a.tm_min = 0;
    a.tm_sec = 0;
    a.tm_isdst = -1;
    return a;
}
int compare_tm(struct tm tm1, struct tm tm2)
{
    if (tm1.tm_year < tm2.tm_year) return -1;
    if (tm1.tm_year > tm2.tm_year) return 1;

    if (tm1.tm_mon < tm2.tm_mon) return -1;
    if (tm1.tm_mon > tm2.tm_mon) return 1;

    if (tm1.tm_mday < tm2.tm_mday) return -1;
    if (tm1.tm_mday > tm2.tm_mday) return 1;
    return 0;
}
int TinhNgayChenhLech(struct tm tm1, struct tm tm2)
{
    time_t time1 = mktime(&tm1);
    time_t time2 = mktime(&tm2);

    // Tính chênh lệch giữa hai thời gian
    double diff_seconds = difftime(time1, time2);

    // Chuyển đổi chênh lệch thời gian từ giây sang số ngày
    int diff_days = diff_seconds / (60 * 60 * 24);

    return diff_days;
}
ThuocNode *CreateNode(Thuoc data)
{
    ThuocNode *p=new ThuocNode();
    if(!p)
    {
        return NULL;
    }
    p->data=data;
    p->Next=NULL;
    return p;
}
HDNhapNode *CreateNode(HoaDonNhap data)
{
    HDNhapNode *p=new HDNhapNode();
    p->Next=NULL;
    if(!p)
    {
        return NULL;
    }
    p->data=data;
    p->Next=NULL;
    return p;
}
HDXuatNode *CreateNode(HoaDonXuat data)
{
    HDXuatNode *p=new HDXuatNode();
    p->Next = NULL;
    if(!p)
    {
        return NULL;
    }
    p->data=data;
    p->Next=NULL;
    return p;
}
void DeleteNode(QueueThuoc *&p)
{
    if(!p)
        return;
    p->Next=NULL;
    delete p;
}
void DeleteNode(ThuocNode *&p)
{
    if(!p)
        return;
    p->Next=NULL;
    delete p;
}
void DeleteNode(HDNhapNode *&p)
{
    if(!p)
        return;
    p->Next=NULL;
    delete p;
}
void DeleteNode(HDXuatNode *&p)
{
    if(!p)
        return;
    p->Next=NULL;
    delete p;
}
void DeleteMidList(DSQueueThuoc& t, QueueThuoc*& q)
{
    if (t.head == NULL || q == NULL || q == t.tail)
        return;
    else
    {
        if (q->Next == t.tail)
        {
            QueueThuoc* p = t.tail;
            QueueThuoc* current = t.head;
            while (current->Next != t.tail)
                current = current->Next;
            t.tail = current;
            t.tail->Next = NULL;
            delete p;
        }
        else
        {
            QueueThuoc* p = q->Next;
            q->Next = p->Next;
            p->Next = NULL;
            delete p;
        }
    }
}
void Pop(QueueThuoc &t)
{
    ThuocNode *p=NULL;
    if(t.head!=NULL)
    {
        p=t.head;
        t.head=t.head->Next;
        p->Next=NULL;
    }
    if (t.head == NULL)
    {
        t.tail = NULL;
    }
    delete p;
}
void Pop(QueueThuoc &t,int &soluong)
//soluong: số lượng định xuất
{
    while(soluong>0 &&t.head!=NULL)
    {
        ThuocNode *tmp=t.head;
        if(soluong>=tmp->data.soluong)
        //SL >= Node đầu => Xóa Thuốc đã hết SL ==> XOA NODE ĐẦU
        //Nếu SL xuất vẫn dư
        {
            soluong-=tmp->data.soluong;
            t.head=t.head->Next;
            delete tmp;
        }
        else
        {
            //Cập nhật còn lại sau khi xuất
            tmp->data.soluong-=soluong;
            soluong=0;
        }
    }
    if (t.head == NULL)
    {
        t.tail = NULL;
    }
}
int KiemTraMaThuocTonTai(DSQueueThuoc t,string mathuoc)
{
    QueueThuoc *current=t.head;
    while(current!=NULL)
    {
        if(current->head->data.mathuoc==mathuoc)
            return 1;
        current=current->Next;
    }
    return 0;
}
int TongSoLuongTheoMaThuoc(DSQueueThuoc t,string mathuoc)
{
    int n=0;
    QueueThuoc *current=t.head;
    while(current!=NULL)
    {
        if(current->head != NULL&&current->head->data.mathuoc==mathuoc)
            {
                ThuocNode *p=current->head;
                while(p!=NULL)
                {
                    n+=p->data.soluong;
                    p=p->Next;
                }
            }
        current=current->Next;
    }
    return n;
}
Thuoc ConvertFromHDNhap(HoaDonNhap b)
{
    Thuoc a;
    a.mathuoc=b.mathuoc;
    a.tenthuoc=b.tenthuoc;
    a.thanhphan=b.thanhphan;
    a.congdung=b.congdung;
    a.ghichu=b.ghichu;
    a.soluong=b.soluong;
    a.NgaySX=b.NgaySX;
    a.NgayHH=b.NgayHH;
    return a;
}
void Push(QueueThuoc &t,ThuocNode *p)
{
    if(p)
    {
        if(t.head==NULL)
            t.head=t.tail=p;
        else
        {
            t.tail->Next=p;
            t.tail=p;
        }
    }
}
void Push(DSQueueThuoc &thuoc,QueueHDNhap &t,HDNhapNode *p)
{
    if(p)
    {
        if(t.head==NULL)
            t.head=t.tail=p;
        else
        {
            t.tail->Next=p;
            t.tail=p;
        }
        // Thuốc chưa tồn tại: Công dụng, thành phần từ HD Nhập thành Đối Thuốc
        Thuoc a=ConvertFromHDNhap(p->data);
        ThuocNode *tmp=CreateNode(a);
        AddQueueThuoc(thuoc,tmp);
    }
}
void Push(DSQueueThuoc& thuoc, QueueHDXuat& t, HDXuatNode* p)
{
    //Hàm thêm HD Xuất
    if (p)
    {
        int SoLuong = TongSoLuongTheoMaThuoc(thuoc, p->data.mathuoc);
        //Nếu Tong SL < Sl định xuất
        if (SoLuong < p->data.soluong)
        {
            textcolor(12);
            cout << "\tKHONG DU SO LUONG DE XUAT";
            textcolor(7);
            _getch();
            return;
        }
        else
        {
            if (t.head == NULL)
            {
                t.head = t.tail = p;
            }
            else
            {
                t.tail->Next = p;
                t.tail = p;
            }
            QueueThuoc* pre = NULL;
            QueueThuoc* current = thuoc.head;
            while (current != NULL)
            {
                if (current->head->data.mathuoc == p->data.mathuoc)
                {
                    int temp = p->data.soluong;
                    Pop(*current, p->data.soluong);
                    //Sau khi xóa thuốc
                    //Hết thuốc
                    if (current->head == NULL)
                    {
                        DeleteMidList(thuoc, pre);
                        current = pre->Next;
                    }
                    if (p->data.soluong > 0) continue;
                    else
                    {
                        p->data.soluong = temp;
                        break;
                    }
                }
                pre = current;
                current = current->Next;
            }
        }

    }
}
void AddQueueThuoc(DSQueueThuoc &DS,ThuocNode *p)
//Hoa don NHAP => THêm thuốc
//ĐỌc file Thuốc => THêm thuốc
{
    if(!p)
        return;
    else
    {
        if(KiemTraMaThuocTonTai(DS,p->data.mathuoc) == 0)
        {
            // Nếu chưa tồn tại thuốc:
            //Tạo mới 1 Node trong DS Thuốc/ Node = Queue
            QueueThuoc *current=new QueueThuoc;
            init(*current);
            Push(*current,p);
            //Thêm vào Queue, thuốc mà mình vừa tạo
            //Thêm Queue vào DSLK Thuốc
            if(DS.head==NULL)
                DS.head=DS.tail=current;
            else
            {
                DS.tail->Next=current;
                DS.tail=current;
            }

        }
        else
        //Đã tồn tại thuốc
        {
            QueueThuoc *current=DS.head;
            while(current!=NULL)
            {
                if(current->head->data.mathuoc==p->data.mathuoc)//Kiếm Queue có cùng mã thuốc
                    {
                        if(compare_tm(current->tail->data.NgaySX,p->data.NgaySX)!=0 || compare_tm(current->tail->data.NgayHH,p->data.NgayHH)!=0)
                            Push(*current,p);
                            //Cùng 1 mã thuốc những khác thời gian
                            //Thêm vào Cuối Queue
                        else
                        {
                            //Cùng Ngày SX/ Ngày HH
                            current->tail->data.soluong+=p->data.soluong;
                        }
                        break;
                    }
                current=current->Next;
            }
        }

    }
}
void PrintStructTM(tm t)
{
    cout<<t.tm_mday<<"/"<<t.tm_mon+1<<"/"<<t.tm_year+1900;
}
void Xuat(Thuoc data)
{
    cout << "\nMa thuoc: " << data.mathuoc;
    cout << "\nTen thuoc: " << data.tenthuoc;
    cout << "\nThanh phan: " << data.thanhphan;
    cout << "\nCong dung: " << data.congdung;
    cout << "\nGhi chu: " << data.ghichu;
    cout << "\nSo luong: " << data.soluong;
    cout << "\nNgay san xuat: ";
    PrintStructTM(data.NgaySX);
    cout << "\nNgay het han: ";
    PrintStructTM(data.NgayHH);

}
void Xuat(HoaDonNhap data)
{
    cout << "\nMa hoa don nhap: " << data.maHDNhap;
    cout << "\nNgay nhap: ";
    PrintStructTM(data.NgayNhap);
    cout << "\nDien giai: " << data.diengiai;
    cout << "\nSo lo: " << data.solo;
    cout << "\nMa thuoc: " << data.mathuoc;
    cout << "\nSo luong: " << data.soluong;
    cout << "\nNgay san xuat: ";
    PrintStructTM(data.NgaySX);
    cout << "\nNgay het han: ";
    PrintStructTM(data.NgayHH);
    cout << "\nCong ty san xuat: " << data.Congty;

}
void Xuat(HoaDonXuat data)
{
    cout << "\nMa hoa don nhap: " << data.maHDXuat;
    cout << "\nNgay nhap: ";
    PrintStructTM(data.NgayXuat);
    cout << "\nDien giai: " << data.diengiai;
    cout << "\nMa thuoc: " << data.mathuoc;
    cout << "\nSo lo: " << data.solo;
    cout << "\nSo luong: " << data.soluong;
    cout << "\nNguoi mua:" << data.NguoiMua;
}
void XuatTatCa(DSQueueThuoc t)
{
    QueueThuoc* current = t.head;
    int index = 1;
    cout << "\nDanh sach thuoc:";
    while (current != NULL)
    {
        cout << "\nThuoc thu " << index << ":";
        ThuocNode* temp = current->head;
        while (temp!=NULL)
        {
            Xuat(temp->data);
            temp = temp->Next;
        }
        current = current->Next;
        cout << "\n-----------------------------------------------------------";
        index++;
    }
}
void XuatTatCa(QueueHDNhap t)
{
    HDNhapNode* current = t.head;
    int index = 1;
    cout << "\nDanh sach hoa don nhap:";
    while (current != NULL)
    {
        cout << "\nHoa don nhap thu " << index << ":";
        Xuat(current->data);
        current = current->Next;
        cout << "\n-----------------------------------------------------------";
        index++;
    }
}
void XuatTatCa(QueueHDXuat t)
{
    HDXuatNode* current = t.head;
    int index = 1;
    cout << "\nDanh sach hoa don xuat:";
    while (current != NULL)
    {
        cout << "\nHoa don xuat thu " << index << ":";
        Xuat(current->data);
        current = current->Next;
        cout << "\n-----------------------------------------------------------";
        index++;
    }
}
void TimThuocTheoTen(DSQueueThuoc t,string ten)
{
    QueueThuoc *current=t.head;
    while(current!=NULL)
    {
        ThuocNode* p = current->head;
        while (p != NULL)
        {
            if (p->data.tenthuoc == ten)
                Xuat(p->data);
            p = p->Next;
        }

        current=current->Next;
    }
}
void TimThuocTheoMaThuoc(DSQueueThuoc t,string mathuoc)
{
    QueueThuoc *current=t.head;
     while(current!=NULL)
    {
         ThuocNode* p = current->head;
         while (p != NULL)
         {
             if (p->data.mathuoc == mathuoc)
                 Xuat(p->data);
             p = p->Next;
         }
        current=current->Next;
    }
}
Thuoc TimThuocTheoMaThuoc_Thuoc(DSQueueThuoc t, string mathuoc)
{
    QueueThuoc* current = t.head;
    Thuoc thuoc;
    while (current != NULL)
    {
        ThuocNode* p = current->head;
        while (p != NULL)
        {
            if (p->data.mathuoc == mathuoc)
                thuoc = p->data;
            p = p->Next;
        }
        current = current->Next;
    }
    return thuoc;
}
void XoaThuocHetHan(DSQueueThuoc &t)
{
    //Time HT
    tm localtime=GetLocalTime();
    QueueThuoc* pre = NULL;
    QueueThuoc *current=t.head;
    while(current!=NULL)
    {
        if (compare_tm(localtime, current->head->data.NgayHH) >= 0)
        {
                //Hàm compare_tm, nếu nhỏ hơn: -1, == là 0, lớn hơn là 1
                //Hiện tại > Ngày HH => Nghĩa là thuốc đã hết hạn
                //Pop: xóa đầu Queue thuốc
                //
            Pop(*current);
            if (current->head == NULL)
            {
                DeleteMidList(t, pre);
                current = pre->Next;
            }
        }
        pre = current;
        current=current->Next;
    }
}
void ThongkeThuocHSDDuoi30(DSQueueThuoc t)
{
    QueueThuoc *current=t.head;
    //Time HT
    tm localtime=GetLocalTime();
    while(current!=NULL)
    {
        ThuocNode *p=current->head;
        while(p!=NULL)
        {
            int songaychenhlech=TinhNgayChenhLech(p->data.NgayHH, localtime);
            if(songaychenhlech>=0 && songaychenhlech<30)
                Xuat(p->data);
            else break;
            p=p->Next;
        }

        current=current->Next;
    }
}
void TimThuocHSDDuoi6Thang(DSQueueThuoc t)
{
    QueueThuoc *current=t.head;
    // Lấy thời gian Hiện tại, Dd/mm/yyyy
    tm localtime=GetLocalTime();
    while(current!=NULL)
    {
        ThuocNode *p=current->head;
        while(p!=NULL)
        {
            int songaychenhlech=TinhNgayChenhLech(p->data.NgayHH, localtime);
            //Tính số ngày chênh lệch của mỗi loại thuốc với HTai
            // <6 thang
            if(songaychenhlech>=0 && songaychenhlech<180)
                Xuat(p->data);
            p=p->Next;
        }
        current=current->Next;
    }
}
bool SoSanhGiamDan(Thuoc a,Thuoc b)
{
    return a.soluong > b.soluong;
}
void TimThuocCoSoLuongHon100_SapXepGiamDan(DSQueueThuoc t)
{
    QueueThuoc *current=t.head;
    // vector = mảng 1 chiều kiểu Thuốc
    vector<Thuoc> DanhSachThuocLonHon100;
    while(current!=NULL)
    {
        int TongSoLuong=TongSoLuongTheoMaThuoc(t,current->head->data.mathuoc);
        //TÌm tổng sl thuốc hiện có
        if(TongSoLuong>100)
        {
            Thuoc temp=current->head->data;
            temp.soluong=TongSoLuong;
            //thêm vào mảng
            DanhSachThuocLonHon100.push_back(temp);
        }
        current=current->Next;
    }
    //Sau khi thêm tất cả thuốc vào mảng
    //Sắp xếp/ Dùng thư viện thuật toán
    sort(DanhSachThuocLonHon100.begin(),DanhSachThuocLonHon100.end(),SoSanhGiamDan);
    //Đã sắp xếp
    for(Thuoc item:DanhSachThuocLonHon100)
    //foreach( duyệt từng thành phần với 1 biến tạm THUỘC MẢNG LỚN)
    {
        //In theo 0->n-1
        Xuat(item);
    }
    /*for (int i = 0; i < DanhSachThuocLonHon100.size(); i++)
    {
        Xuat(DanhSachThuocLonHon100[i]);
    }*/
}
int GetMaxSoLuongBan(unordered_map<string,int>ThongKe)
{
    //Tìm số lượng lớn nhất
    int R=0;
    int size=ThongKe.size();
    for(pair<string,int>x:ThongKe)
    {
        R=R<x.second?x.second:R;
    }
    return R;
}
int GetMinSoLuongBan(unordered_map<string,int>ThongKe)
{
    //Tìm số lượng nhỏ nhất
    int R=INT_MAX;
    int size=ThongKe.size();
    for(pair<string,int>x:ThongKe)
    {
        R=R>x.second?x.second:R;
    }
    return R;
}
void ThongKeThuocBan(QueueHDXuat t,int choice) //0 là ÍT nhất, 1 là NHIỀU nhất
{
    //Ngày 1 xuất thuốc A, số lượng 7
    //ngày 3 Xuất thuốc A số lượng 8
    // THUỐC A, bán dc 15++ (nếu còn HDon)
    // Map<key,value>
    //Map["Thuoc abc"]=value;
    HDXuatNode *current=t.head;
    unordered_map<string,int>ThongKe;
    while(current!=NULL)
    {
        if(ThongKe.find(current->data.mathuoc)==ThongKe.end())//nếu không có thì trỏ về end
        //Trong mảng 2d, chưa có Thuốc đó thì gán SL vào
        {
            ThongKe[current->data.mathuoc]=current->data.soluong;
        }
        //Nếu tồn tại rồi, CỘNG SỐ LƯỢNG
        else ThongKe[current->data.mathuoc]+=current->data.soluong;
        current=current->Next;
    }
    int temp;
    if(choice==1)
    {
        temp=GetMaxSoLuongBan(ThongKe);
    }
    else
    {
        temp=GetMinSoLuongBan(ThongKe);
    }
    //Duyệt mảng => Kiếm thuốc có SL bán == temp;
    for(pair<string,int>x:ThongKe)
    {
        if(x.second==temp)
        {
            cout << "Ma thuoc: " << x.first << ", So luong ban: " << x.second << endl;
        }
    }
}
void DocFileThuoc(DSQueueThuoc &DS)//Ý 2
{
    //Dùng C++
    fstream File;
    File.open("DSThuoc.txt");
    string str;
    Thuoc thuoc;
    int index = 1;
    if (File.is_open()) {
        while (getline(File, str))
        {
            //Chia lấy dư
            if (index % 9 == 0)
            {
                // 9 % 9 sẽ dư 0
                index = 1;
                continue;
            }
            int pos = str.find(":");
            switch (index)
            {
            case 1:
            {
                thuoc.mathuoc = str.substr(pos + 1);
                break;
            }
            case 2:
            {
                thuoc.tenthuoc= str.substr(pos + 1);
                break;
            }
            case 3:
            {
                //substr: lấy phần nhỏ chuỗi
                thuoc.thanhphan = str.substr(pos + 1);
                break;
            }
            case 4:
            {
                thuoc.congdung = str.substr(pos + 1);
                break;
            }
            case 5:
            {
                thuoc.ghichu = str.substr(pos + 1);
                break;
            }
            case 6:
            {
                thuoc.soluong = stoi(str.substr(pos + 1));
                break;
            }
            case 7:
            {
                int FirstDashPos = str.find("-");
                int SecondDashPos = str.find("-", FirstDashPos + 1);
                thuoc.NgaySX = SetStructTM(stoi(str.substr(SecondDashPos + 1)), stoi(str.substr(FirstDashPos + 1, SecondDashPos - 1)), stoi(str.substr(pos + 1, FirstDashPos - 1)));
                break;
            }
            case 8:
            {
                //Giá trị cần đọc cuối
                int FirstDashPos = str.find("-");
                int SecondDashPos = str.find("-", FirstDashPos + 1);
                //struct tm trong ctime
                thuoc.NgayHH = SetStructTM(stoi(str.substr(SecondDashPos + 1)), stoi(str.substr(FirstDashPos + 1, SecondDashPos - 1)), stoi(str.substr(pos + 1, FirstDashPos - 1)));
                //Tạo thuốc mới
                ThuocNode* temp = CreateNode(thuoc);
                //Thêm vào Queue thuốc
                AddQueueThuoc(DS, temp);
                break;
            }
            default:
                break;
            }
            index++;
        }
        File.close();
    }
    else
    {
        cout << "\nLoi mo file";
        _getch();
    }
}
void DocFileHDNhap(DSQueueThuoc& thuoc, QueueHDNhap& t)//ham moi
{
    fstream File;
    File.open("HoaDonNhap.txt");
    string str;
    HoaDonNhap HD;
    int index = 1;
    if (File.is_open()) {
        while (getline(File, str))
        {
            if (index % 14 == 0)
            {
                index = 1;
                continue;
            }
            int pos = str.find(":");
            switch (index)
            {
            case 1:
            {
                HD.maHDNhap = str.substr(pos + 1);
                break;
            }
            case 2:
            {
                int FirstDashPos = str.find("-");
                int SecondDashPos = str.find("-", FirstDashPos + 1);
                HD.NgayNhap = SetStructTM(stoi(str.substr(SecondDashPos + 1)), stoi(str.substr(FirstDashPos + 1, SecondDashPos - 1)), stoi(str.substr(pos + 1, FirstDashPos - 1)));
                break;
            }
            case 3:
            {
                HD.diengiai = str.substr(pos + 1);
                break;
            }
            case 4:
            {
                HD.mathuoc = str.substr(pos + 1);
                break;
            }
            case 5:
            {
                HD.solo = str.substr(pos + 1);
                break;
            }
            case 6:
            {
                HD.tenthuoc = str.substr(pos + 1);
                break;
            }
            case 7:
            {
                HD.thanhphan = str.substr(pos + 1);
                break;
            }
            case 8:
            {
                HD.congdung = str.substr(pos + 1);
                break;
            }
            case 9:
            {
                HD.ghichu = str.substr(pos + 1);
                break;
            }
            case 10:
            {
                HD.soluong = stoi(str.substr(pos + 1));
                break;
            }
            case 11:
            {
                int FirstDashPos = str.find("-");
                int SecondDashPos = str.find("-", FirstDashPos + 1);
                HD.NgaySX = SetStructTM(stoi(str.substr(SecondDashPos + 1)), stoi(str.substr(FirstDashPos + 1, SecondDashPos - 1)), stoi(str.substr(pos + 1, FirstDashPos - 1)));
                break;
            }
            case 12:
            {
                int FirstDashPos = str.find("-");
                int SecondDashPos = str.find("-", FirstDashPos + 1);
                HD.NgayHH = SetStructTM(stoi(str.substr(SecondDashPos + 1)), stoi(str.substr(FirstDashPos + 1, SecondDashPos - 1)), stoi(str.substr(pos + 1, FirstDashPos - 1)));

                break;
            }
            case 13:
            {
                HD.Congty = str.substr(pos + 1);
                HDNhapNode* HDN = CreateNode(HD);
                Push(thuoc, t, HDN);
                break;
            }
            default:
                break;
            }
            index++;
        }
        File.close();
    }
    else
    {
        cout << "\nLoi mo file";
        _getch();
    }
}
void DocFileHDXuat(DSQueueThuoc &thuoc,QueueHDXuat& t)//ham moi
{
    fstream File;
    File.open("HoaDonXuat.txt");
    string str;
    HoaDonXuat HD;
    int index = 1;
    if (File.is_open()) {
        while (getline(File, str))
        {
            if (index % 8 == 0)
            {
                index = 1;
                continue;
            }
            int pos = str.find(":");
            switch (index)
            {
            case 1:
            {
                HD.maHDXuat = str.substr(pos + 1);
                break;
            }
            case 2:
            {
                int FirstDashPos = str.find("-");
                int SecondDashPos = str.find("-", FirstDashPos + 1);
                HD.NgayXuat = SetStructTM(stoi(str.substr(SecondDashPos + 1)), stoi(str.substr(FirstDashPos + 1, SecondDashPos - 1)), stoi(str.substr(pos + 1, FirstDashPos - 1)));
                break;
            }
            case 3:
            {
                HD.diengiai = str.substr(pos + 1);
                break;
            }
            case 4:
            {
                HD.mathuoc = str.substr(pos + 1);
                break;
            }
            case 5:
            {
                HD.solo = str.substr(pos + 1);
                break;
            }
            case 6:
            {
                HD.soluong = stoi(str.substr(pos + 1));
                break;
            }
            case 7:
            {
                HD.NguoiMua = str.substr(pos + 1);
                HDXuatNode *HDX = CreateNode(HD);
                Push(thuoc,t,HDX);
                break;
            }
            default:
                break;
            }
            index++;
        }
        File.close();
    }
    else
    {
        cout << "\nLoi mo file";
        _getch();
    }
}

void NhapThuoc(DSQueueThuoc& t)
{
    Thuoc thuoc;
    textcolor(12);
    cout << "Nhap thong tin thuoc:\n";
    textcolor(7);
    cin.ignore();
    cout << "Nhap ma thuoc: ";
    getline(cin, thuoc.mathuoc);
    cout << "Nhap ten thuoc: ";
    getline(cin, thuoc.tenthuoc);
    cout << "Nhap thanh phan: ";
    getline(cin, thuoc.thanhphan);
    cout << "Nhap cong dung: ";
    getline(cin, thuoc.congdung);
    cout << "Nhap ghi chu: ";
    getline(cin, thuoc.ghichu);
    cout << "Nhap so luong: ";
    cin >> thuoc.soluong;
    int y, m, d;
    cout << "Nhap ngay SX: DD MM YYYY: ";
    cin >> d >> m >> y;
    thuoc.NgaySX = SetStructTM(y, m, d);
    cout << "Nhap ngay HH: DD MM YYYY: ";
    cin >> d >> m >> y;
    thuoc.NgayHH = SetStructTM(y, m, d);
    ThuocNode* p = CreateNode(thuoc);
    AddQueueThuoc(t, p);
}
void NhapHDNhap(DSQueueThuoc& thuoc, QueueHDNhap& t)
{
    HoaDonNhap HD;
    int y, m, d;
    textcolor(12);
    cout << "Nhap thong tin hoa don nhap:\n";
    textcolor(7);
    cin.ignore();
    cout << "Nhap ma hoa don: ";
    getline(cin, HD.maHDNhap);
    cout << "Nhap ma thuoc: ";
    getline(cin, HD.mathuoc);
    if (KiemTraMaThuocTonTai(thuoc, HD.mathuoc) == 0)
    {
        Loop:
        textcolor(12);
        cout << "MA THUOC KHONG TON TAI\n";
        int m = 0;
        cout << "\tTAO MOI - 1 / NHAP LAI - 0: ";
        cin >> m;
        while (m != 0 && m != 1)
        {
            cout << "\tTAO MOI - 1 / NHAP LAI - 0: ";
            cin >> m;
        }
        textcolor(7);
        if (m == 0)
        {
            cin.ignore();
            cout << "Nhap ma thuoc: ";
            getline(cin, HD.mathuoc);
            if (KiemTraMaThuocTonTai(thuoc, HD.mathuoc) == 0)
                goto Loop;
            Thuoc p=TimThuocTheoMaThuoc_Thuoc(thuoc,HD.mathuoc);
            HD.congdung = p.congdung;
            HD.ghichu = p.ghichu;
            HD.thanhphan = p.thanhphan;
            HD.tenthuoc = p.tenthuoc;
        }
        else
        {
            textcolor(12);
            cout << "Nhap thong tin thuoc:\n";
            textcolor(7);
            cin.ignore();
            cout << "Nhap ten thuoc: ";
            getline(cin, HD.tenthuoc);
            cout << "Nhap thanh phan: ";
            getline(cin, HD.thanhphan);
            cout << "Nhap cong dung: ";
            getline(cin, HD.congdung);
            cout << "Nhap ghi chu: ";
            getline(cin, HD.ghichu);
        }

    }
    Thuoc p = TimThuocTheoMaThuoc_Thuoc(thuoc, HD.mathuoc);
    HD.congdung = p.congdung;
    HD.ghichu = p.ghichu;
    HD.thanhphan = p.thanhphan;
    HD.tenthuoc = p.tenthuoc;
    cout << "Nhap so luong: ";
    cin >> HD.soluong;
    cout << "Nhap ngay SX: DD MM YYYY: ";
    cin >> d >> m >> y;
    HD.NgaySX = SetStructTM(y, m, d);
    cout << "Nhap ngay HH: DD MM YYYY: ";
    cin >> d >> m >> y;
    HD.NgayHH = SetStructTM(y, m, d);
    HD.NgayNhap = GetLocalTime();
    cin.ignore();
    cout << "Nhap dien giai: ";
    getline(cin, HD.diengiai);
    cout << "Nhap CongTySX: ";
    getline(cin,HD.Congty);
    cout << "Nhap so lo: ";
    getline(cin, HD.solo);
    HDNhapNode* node = CreateNode(HD);
    Push(thuoc, t, node);

}
void NhapHDXuat(DSQueueThuoc& thuoc, QueueHDXuat& t)
{
    HoaDonXuat HD;
    int y, m, d;
    textcolor(12);
    cout << "Nhap thong tin hoa don xuat:\n";
    textcolor(7);
    cin.ignore();
    cout << "Nhap ma hoa don: ";
    getline(cin, HD.maHDXuat);
    cout << "Nhap ma thuoc: ";
    getline(cin, HD.mathuoc);
    if (KiemTraMaThuocTonTai(thuoc, HD.mathuoc) == 0)
    {
        textcolor(12);
        cout << "\tTHUOC KHONG TON TAI\n";
        textcolor(7);
        _getch();
        return;
    }
    HD.NgayXuat = GetLocalTime();
    cout << "Nhap so lo: ";
    getline(cin, HD.solo);
    cout << "Nhap dien giai: ";
    getline(cin, HD.diengiai);
    cout << "Nhap nguoi mua: ";
    getline(cin, HD.NguoiMua);
    cout << "Nhap so luong: ";
    cin >> HD.soluong;
    HDXuatNode* p = CreateNode(HD);
    Push(thuoc, t, p);
}