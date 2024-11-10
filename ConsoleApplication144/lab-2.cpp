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
    VideoPlayer video1(120);
    VideoPlayer video2 = video1; // Конструктор копирования вызывается
    VideoPlayer video3(60);
    VideoPlayer video4 = video2 + video3;
    video4.printPlaytime(); 

    int vectorSize = 5; // Задайте нужный размер векторов
    Advert* advert = new Advert();
    Video* video = new Video();
    advert->ShowAdv(); 
    video->ChooseVid();
  

    // Освобождение динамически выделенной памяти
    delete[] AvailableOptions; 
    delete[] AllVid;          
    delete[] LastVid;         
    delete[] AllAdvert;       
    delete[] LastAdvert;      
    delete advert;            
    delete video;             

    return 0;
}

