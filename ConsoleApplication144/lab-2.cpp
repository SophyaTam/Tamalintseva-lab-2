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

   // Память для массива видео
    char(*AvailableOptions)[M] = new char[N][M];
    char(*AllVid)[M] = new char[N][M];
    char(*LastVid)[M] = new char[N][M];
    int* AllAdvert = new int[N];
    int* LastAdvert = new int[N];

    int Djanre = 0, Turn = 0, Back = 0;

    Advert* advert = new Advert();
    advert->ShowAdv(); 
    ButtonStopVid player;
    player.ChooseVid();
  

    // Освобождение динамически выделенной памяти
    delete[] AvailableOptions; 
    delete[] AllVid;          
    delete[] LastVid;         
    delete[] AllAdvert;       
    delete[] LastAdvert;      
    delete advert;                        

    return 0;
}

