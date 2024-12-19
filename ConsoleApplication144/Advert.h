#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <limits>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#ifndef ADVERT_H
#define ADVERT_H

//Класс для возможности приостановки рекламы через команды 0 и 1
class Advert {
protected:
    char TurnOnTheAdvert;
    std::vector<int> AllAdvert;
    std::vector<int> NamesAdd;
    std::vector<int> LastAdvert;
    int size;

public:
    // Конструктор с параметрами
    Advert(int size) : AllAdvert(size), NamesAdd(size), LastAdvert(size), size(size) {
        LastAdverts();
    }

    // Конструктор по умолчанию
    Advert() : Advert(N) {}

    // Копирующий конструктор
    Advert(const Advert& other)
        : TurnOnTheAdvert(other.TurnOnTheAdvert),
        AllAdvert(other.AllAdvert),
        NamesAdd(other.NamesAdd),
        LastAdvert(other.LastAdvert),
        size(other.size) {
    }

    // Перегрузка оператора присваивания
    Advert& operator=(const Advert& other) {
        if (this != &other) {
            TurnOnTheAdvert = other.TurnOnTheAdvert;
            AllAdvert = other.AllAdvert;
            NamesAdd = other.NamesAdd;
            LastAdvert = other.LastAdvert;
            size = other.size;
        }
        return *this;
    }

    // Деструктор
    virtual ~Advert() = default;

    // Метод подключения рекламы для просмотра через ввод 1
    virtual int ChooseAdvert() {
        int Turn;
        std::cout << "Введите 1, если хотите добавить рекламу и 0 - если нет: ";
        std::cin >> Turn;
        return Turn;
    }

    void CallChooseAdvert() {
        int choice = ChooseAdvert();
        if (choice == 1) {
            std::cout << "Реклама была добавлена через базовый класс." << std::endl;
        }
        else {
            std::cout << "Реклама не была добавлена через базовый класс." << std::endl;
        }
    }

    void NameAd() {
        for (int i = 0; i < size; i++) {
            NamesAdd[i] = i + 1;
        }
    }

    void LastAdverts() {
        for (int i = 0; i < size; i++) {
            LastAdvert[i] = 0;
        }
    }

    virtual void ShowAdv();
};

class ButtonStopAdv : public Advert {
public:
    ButtonStopAdv(int size) : Advert(size) {}

    int ChooseAdvert() override {
        int baseChoice = Advert::ChooseAdvert();
        if (baseChoice == 1) {
            std::cout << "Реклама была добавлена через производный класс." << std::endl;
        }
        else {
            std::cout << "Реклама не была добавлена через производный класс." << std::endl;
        }
        return baseChoice;
    }

    void StopAdvs(int& StopAdv) {
        do {
            puts("Если хотите остановить видео, нажмите 1, иначе - 0");
            if (scanf("%d", &StopAdv) != 1) {
                printf("Ошибка: введите числовое значение.\n");
                while (getchar() != '\n');
                StopAdv = -1;
            }
            else if (StopAdv < 0 || StopAdv > 1) {
                printf("Ошибка: Если хотите остановить рекламу, нажмите 1, иначе - 0.\n");
            }
        } while (StopAdv < 0 || StopAdv > 1);

        if (StopAdv == 1) {
            puts("Реклама остановлена");
        }
    }

    void OnAdv() {
        int StopAdv = 0;
        while (true) {
            StopAdvs(StopAdv);

            if (StopAdv == 0) {
                puts("Вы выбрали продолжить.");
                break;
            }
            puts("Для дальнейшего просмотра нажмите 1");
            int AdvPlayerOn;
            scanf("%d", &AdvPlayerOn);
            if (AdvPlayerOn == 1) {
                break;
            }
        }
    }
};

// Метод для выбора рандомной рекламы и её воспроизведения
void Advert::ShowAdv() {
    int TurnOn = ChooseAdvert();
    NameAd();
    LastAdverts();
    if (TurnOn == 1) {
        srand(static_cast<unsigned int>(time(NULL)));
        int randomIndex;
        bool Allow;
        do {
            randomIndex = rand() % N;
            Allow = true;
            for (int i = 0; i < N; i++) {
                if (NamesAdd[randomIndex] == LastAdvert[i]) {
                    Allow = false;
                    break;
                }
            }
        } while (!Allow);
        printf("Играет реклама: #%d........\n", NamesAdd[randomIndex]);
        ButtonStopAdv adv(1);
        adv.OnAdv();
        for (int i = 0; i < N; i++) {
            if (LastAdvert[i] == 0) {
                LastAdvert[i] = NamesAdd[randomIndex];
                break;
            }
        }
    }
}
#endif