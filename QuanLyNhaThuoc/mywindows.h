#pragma once // tránh đụng độ thư viện khi gọi chồng file lên nhau
#include <conio.h>
#include "windows.h"
using namespace std;
//======= lấy tọa độ x của con trỏ hiện tại =============
#define KEY_NONE -1

// Chỉnh tiêu đề cmd
// BOOL WINAPI SetConsoleTitle(_In_ LPCTSTR lpConsoleTitle);
int whereX() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.X;
    return -1;
}

//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.Y;
    return -1;
}

COORD GetXY() {
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleScreenBufferInfo(Handle, &cbsi)) {
        return cbsi.dwCursorPosition;
    } else {
        // The function failed. Call GetLastError() for details.
        COORD invalid = {0, 0};
        return invalid;
    }
}

//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(short int x, short int y) {
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

//============= đặt màu cho chữ =========
void textcolor(int x) {
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}

WORD GetConsoleTextAttribute(HANDLE Handle) {
    CONSOLE_SCREEN_BUFFER_INFO con_info;
    GetConsoleScreenBufferInfo(Handle, &con_info);
    return con_info.wAttributes;
}

void SetBackGroundRange(int color, int x, int y, int width, int height) {
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD BackupPos = GetXY();
    short BackupColor = GetConsoleTextAttribute(Handle);
    gotoXY(x, y);
    textcolor(color);
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++)
            cout << " ";
        gotoXY(x, y++);
    }
    gotoXY(BackupPos.X, BackupPos.Y);
    textcolor(BackupColor);
}

//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}

//======= trả về mã phím người dùng bấm =========
int inputKey() {
    if (_kbhit()) // true
    {
        int key = _getch();

        if (key == 224) {
            key = _getch();
            return key + 1000;
        }

        return key;
    } else {
        return KEY_NONE;
    }
    return KEY_NONE;
}

void resizeConsole(int width, int height) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void BufferSize(SHORT width, SHORT height) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;

    SetConsoleScreenBufferSize(hStdout, NewSize);
}

void colortext(int x, int y, char a, int color) {
    gotoXY(x, y);
    textcolor(color);
    std::cout << a;
    textcolor(7);
}

void clreol() {
    COORD coord;
    DWORD written;
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    coord.X = info.dwCursorPosition.X;
    coord.Y = info.dwCursorPosition.Y;
    FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ',
                               info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
    gotoXY(info.dwCursorPosition.X, info.dwCursorPosition.Y);
}

void SetCenterConsole() {
    HWND ConsoleWindow;
    RECT rectConsole;

    ConsoleWindow = GetForegroundWindow();      // get handle
    GetWindowRect(ConsoleWindow, &rectConsole); // get Console Rect

    // Getting the desktop hadle and rectangule
    HWND hwndScreen;
    RECT rectScreen;

    hwndScreen = GetDesktopWindow();        // get HANDLE Desktop
    GetWindowRect(hwndScreen, &rectScreen); // get Desktop Rect

    // caculate the window console to center of the screen
    int ConsolePosX;
    int ConsolePosY;
    // Center PosX = (DesktopWitdh) / 2 - (ConsoleWidth / 2)
    ConsolePosX = ((rectScreen.right - rectScreen.left) / 2 - (rectConsole.right - rectConsole.left) / 2);
    // Center PosX = (DesktopHeight) / 2 - (ConsoleHeight / 2)
    ConsolePosY = ((rectScreen.bottom - rectScreen.top) / 2 - (rectConsole.bottom - rectConsole.top) / 2);
    SetWindowPos(ConsoleWindow, NULL, ConsolePosX, ConsolePosY, 0, 0, SWP_SHOWWINDOW || SWP_NOSIZE);
}