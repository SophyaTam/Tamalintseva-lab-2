#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include "Header.h"
#define N 200
#define M 200
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    char AvailableOptions[N - 1][M - 1], AllVid[N][M], LastVid[N][M];
    int Djanre=0,Turn=0, AllAdvert[N], LastAdvert[N], Back=0;
    ShowAdv();
    ChooseVid();
}

