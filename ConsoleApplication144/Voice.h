#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <limits>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#ifndef VOICE_H
#define VOICE_H

//Класс звука для установки уровня громкости через ввод в консоль соответствующего числа от 0 до 100
class Voice {
private:
    static int Loud; // Статическое поле для громкости

public:
    // Метод для ввода численного значения громкости видео
    static int VidVoice() { // Статический метод
        do {
            std::cout << "Введите уровень громкости (от 0 до 100): ";
            if (std::cin >> Loud && Loud >= 0 && Loud <= 100) {
                std::cout << "Уровень громкости видео изменен до " << Loud << std::endl;
                return Loud;
            }
            else {
                std::cout << "Ошибка: уровень громкости должен быть в пределах от 0 до 100. Попробуйте ещё раз.\n";
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
        } while (true);
    }

    static int getLoud() { return Loud; }
};
int Voice::Loud = 0;
#endif
