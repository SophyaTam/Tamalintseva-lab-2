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

    // Динамическое выделение объектов классов Advert и Video
    Advert* advert = new Advert();
    Video* video = new Video();

    advert->ShowAdv(); // Показываем рекламу
    video->ChooseVid(); // Вызываем метод для выбора видео

    // Освобождение динамически выделенной памяти
    delete[] AvailableOptions; // Освобождаем память для массива AvailableOptions
    delete[] AllVid;          // Освобождаем память для массива AllVid
    delete[] LastVid;         // Освобождаем память для массива LastVid
    delete[] AllAdvert;       // Освобождаем память для массива AllAdvert
    delete[] LastAdvert;      // Освобождаем память для массива LastAdvert
    delete advert;            // Освобождаем память для объекта Advert
    delete video;             // Освобождаем память для объекта Video

    return 0;
}

