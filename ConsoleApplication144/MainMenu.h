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
#ifndef MainMenu_H
#define MainMenu_H
//Класс для описания главного меню в котором пользователи будут выбирать направление для просмотра посредством нажатия соответствующей цифры
//Представляет собой список доступных жанров
// Базовый класс для опций меню
class MenuOption {
public:
    virtual std::string GetName() const = 0; // Чисто виртуальная функция для получения имени опции
    virtual ~MenuOption() {} // Виртуальный деструктор
};
// Производные классы для различных типов опций
class MelodramaOption : public MenuOption {
public:
    std::string GetName() const override {
        return "Мелодраммы";
    }
};
class ChildOption : public MenuOption {
public:
    std::string GetName() const override {
        return "Детское";
    }
};
class DetectiveOption : public MenuOption {
public:
    std::string GetName() const override {
        return "Детективы";
    }
};
class ComedyOption : public MenuOption {
public:
    std::string GetName() const override {
        return "Комедии";
    }
};
class SeriesOption : public MenuOption {
public:
    std::string GetName() const override {
        return "Сериалы";
    }
};
// Контейнер для хранения опций меню
class MenuOptionsContainer {
private:
    std::vector<std::unique_ptr<MenuOption>> options;

public:
    void AddOption(std::unique_ptr<MenuOption> option) {
        options.push_back(std::move(option));
    }

    const std::vector<std::unique_ptr<MenuOption>>& GetOptions() const {
        return options;
    }

    size_t Size() const {
        return options.size();
    }

    // Метод для сортировки опций по имени
    void SortOptions() {
        std::sort(options.begin(), options.end(),
            [](const std::unique_ptr<MenuOption>& a, const std::unique_ptr<MenuOption>& b) {
                return a->GetName() < b->GetName();
            });
    }

    // Метод для поиска опции по имени
    MenuOption* FindOption(const std::string& name) const {
        auto it = std::find_if(options.begin(), options.end(),
            [&name](const std::unique_ptr<MenuOption>& option) {
                return option->GetName() == name;
            });
        return (it != options.end()) ? it->get() : nullptr; // Возвращаем указатель на найденный объект или nullptr
    }
};
class Menu {
public:
    virtual void AddOptions() = 0; // Чисто виртуальная функция для добавления опций
    virtual int ChooseOptions() = 0; // Чисто виртуальная функция для выбора опции
    virtual ~Menu() {} // Виртуальный деструктор
};
class MainMenu : public Menu {
private:
    MenuOptionsContainer AvailableOptions; // Используем контейнер для опций

public:
    MainMenu() {
        AddOptions();
        AvailableOptions.SortOptions(); // Сортируем опции при инициализации
    }

    void AddOptions() override {
        AvailableOptions.AddOption(std::make_unique<ChildOption>());
        AvailableOptions.AddOption(std::make_unique<DetectiveOption>());
        AvailableOptions.AddOption(std::make_unique<ComedyOption>());
        AvailableOptions.AddOption(std::make_unique<MelodramaOption>());
        AvailableOptions.AddOption(std::make_unique<SeriesOption>());
    }

    int ChooseOptions() override {
        int Djanre = 0;
        const auto& options = AvailableOptions.GetOptions();
        for (size_t i = 0; i < options.size(); ++i) {
            std::cout << i + 1 << ". " << options[i]->GetName() << std::endl;
        }
        std::cout << "Выберите желаемое направление (1-" << options.size() << "): ";
        while (true) {
            if (!(std::cin >> Djanre) || Djanre < 1 || Djanre > options.size()) {
                std::cout << "Неверный ввод! Пожалуйста, введите число от 1 до " << options.size() << "." << std::endl;
                std::cin.clear();
                std::cin.ignore(256, '\n');
            }
            else {
                break;
            }
        }
        return Djanre;
    }

    //Метод для поиска опции по имени
    void SearchOption(const std::string& name) {
        MenuOption* option = AvailableOptions.FindOption(name);
        if (option) {
            std::cout << "Опция '" << name << "' найдена! Она содержит: " << std::endl;
            const char* filename = nullptr; // Указатель на имя файла

            // Присваиваем имя файла в зависимости от опции
            if (name == "Детское") filename = "1.txt";
            else if (name == "Детективы") filename = "2.txt";
            else if (name == "Комедии") filename = "3.txt";
            else if (name == "Мелодрамы") filename = "4.txt";
            else if (name == "Сериалы") filename = "5.txt";

            // Проверяем, был ли выбран файл
            if (filename) {
                FILE* file = fopen(filename, "r");
                if (file == NULL) {
                    perror("Ошибка открытия файла");
                    return;
                }

                char point[30];
                while (fgets(point, M, file) != NULL) {
                    point[strcspn(point, "\n")] = '\0'; // Удаляем символ новой строки
                    std::cout << point << std::endl; // Выводим содержимое строки
                }
                fclose(file);
            }
        }
        else {
            std::cout << "Опция '" << name << "' не найдена." << std::endl;
        }
    }
};
#endif