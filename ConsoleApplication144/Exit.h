#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <limits>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#define N 200
#define M 200
#ifndef EXIT_H
#define EXIT_H
//Кнопка для полного закрытия программы при нажатии на которую заканчивает работу консольное приложение, а в графическом приложении будет закрывать форму
class EndWork {
public:
    // Статический метод завершения программы через ввод в консоль цифры 7
    static void End(bool* endSession) { // Статический метод, принимает указатель на булеву переменную
        int EndAll = 0;
        puts("Если хотите завершить работу видеопроигрывателя, нажмите 7: ");
        try {
            if (scanf("%d", &EndAll) != 1) {
                throw std::runtime_error("Ошибка ввода: Необходимо ввести целое число.");
            }

            if (EndAll == 7) {
                puts("Завершение сеанса...");
                exit(0);
                *endSession = true;//  происходит возврат значения через указатель.
            }
            else {
                puts("Работа видеопроигрывателя продолжается.");
            }
        }
        catch (const std::runtime_error& error) {
            std::cerr << "Ошибка: " << error.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Произошла неизвестная ошибка: " << e.what() << std::endl;
        }
    }
};
#endif
