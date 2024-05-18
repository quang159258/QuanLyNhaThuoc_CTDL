#include<iostream>
#include<string>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"mywindows.h"
#include"DSLK.h"
#include"Function.h"
using namespace std;
int main()
{
    DSQueueThuoc DSQueuethuoc;
    QueueHDNhap QueueHDnhap;
    QueueHDXuat QueueHDxuat;
    init(DSQueuethuoc);
    init(QueueHDnhap);
    init(QueueHDxuat);
    Menu(DSQueuethuoc, QueueHDnhap, QueueHDxuat);
    return 0;
}