#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "Videoplayer.h"
#include "Exit.h"
#include "Advert.h"
#include "Video.h"
#include "Voice.h"
#include "MainMenu.h"
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
    MainMenu menu;
    std::string filename; // Строка для имени файла
    std::cout << "Введите имя файла для поиска опции: ";
    std::getline(std::cin, filename); // Считываем имя файла
    menu.SearchOption(filename); // Пример поиска опции

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

