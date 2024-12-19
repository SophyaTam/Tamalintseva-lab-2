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
#include "Videoplayer.h"
#include "Exit.h"
#include "Advert.h"
#include "Voice.h"
#include "MainMenu.h"
#define N 200
#define M 200
#ifndef VIDEO_H
#define VIDEO_H
// Класс для выбора видео и его проигрывания
class Video {
protected:
    char** LastVid;
    char** AllVid;
    int N1;
    int M1;
public:
    Video() : N1(N1), M1(M1) {
        LastVid = new char* [N];
        AllVid = new char* [N];
        for (int i = 0; i < N; ++i) {
            LastVid[i] = new char[M];
            AllVid[i] = new char[M];
        }
        LastVids();
    };
    Video(const Video& other) : N1(other.N1), M1(other.M1) { // Конструктор копирования
        LastVid = new char* [N];
        AllVid = new char* [N];
        for (int i = 0; i < N; ++i) {
            LastVid[i] = new char[M];
            AllVid[i] = new char[M];
            strcpy(LastVid[i], other.LastVid[i]);
            strcpy(AllVid[i], other.AllVid[i]);
        }
    }

    Video& operator=(const Video& other) { // Перегрузка оператора присваивания
        if (this != &other) { // Проверка самоприсваивания
            // Освобождение существующей памяти
            for (int i = 0; i < N; ++i) {
                delete[] LastVid[i];
                delete[] AllVid[i];
            }
            delete[] LastVid;
            delete[] AllVid;

            // Выделение новой памяти и копирование данных
            N1 = other.N1;
            M1 = other.M1;
            LastVid = new char* [N];
            AllVid = new char* [N];
            for (int i = 0; i < N; ++i) {
                LastVid[i] = new char[M];
                AllVid[i] = new char[M];
                strcpy(LastVid[i], other.LastVid[i]);
                strcpy(AllVid[i], other.AllVid[i]);
            }
        }
        return *this;
    }

    ~Video() {
        for (int i = 0; i < N; ++i) {
            delete[] LastVid[i];
            delete[] AllVid[i];
        }
        delete[] LastVid;
        delete[] AllVid;
    }; // Деструктор
    // Метод для заполнения массива с названиями видео для просмотра
    void OpenVid() {
        Menu* menu = new MainMenu();
        int Djanre = menu->ChooseOptions();
        std::cout << "Вы выбрали опцию: " << Djanre << std::endl;
        char filename[M];
        snprintf(filename, M, "%d.txt", Djanre);
        FILE* file = fopen(filename, "r");
        if (file == NULL) {
            perror("Ошибка открытия файла");
            return;
        }
        int count = 0;
        while (fgets(AllVid[count], M, file) != NULL && count < N) {
            AllVid[count][strcspn(AllVid[count], "\n")] = '\0';
            count++;
        }
        fclose(file);
    };
    // Метод для заполнения массива с проигранными видео
    void LastVids() {
        for (int i = 0; i < N; i++) {
            LastVid[i][0] = '\0';
        }
    };
    friend int chooseRandomVideo(Video& video); // Объявление дружественной функции
    // Не виртуальная функция, которая вызывает виртуальную функцию
    void CallChooseVid() {
        ChooseVid(); // Вызов виртуальной функции
    }

    virtual void ChooseVid() = 0; // Чисто виртуальная функция
};
//Дружественная функция для выбора случайного видео
int chooseRandomVideo(Video& video) {
    if (video.AllVid == nullptr) return -1;

    int totalVideos = 0;
    for (int i = 0; i < 4; ++i) {
        if (video.AllVid[i][0] != '\0') totalVideos++;
    }

    if (totalVideos == 0) return -1;

    int randomIndex;
    int Allow;
    do {
        randomIndex = rand() % totalVideos;
        Allow = 1;
        for (int i = 0; i < 4; i++) {
            if (strcmp(video.AllVid[randomIndex], video.LastVid[i]) == 0) {
                Allow = 0;
                break;
            }
        }
    } while (Allow == 0);
    return randomIndex;
}
//Структура для приостановки и воспроизведения видео
class ButtonStopVid :public Video {
private:
    char StopVid;
    char VidPlayerOn;
public:
    // Метод для остановки видео через ввод 1
    int StopVids() {
        puts("Если хотите остановить видео, нажмите 1, иначе - 0");
        StopVid = 0;
        scanf("%d", &StopVid);
        if (StopVid == 1) {
            puts("Видео остановлено");
        }
        return StopVid;
    };
    // Метод для продолжения просмотра через ввод 1
    void OnVid() {
        StopVid = 0;
        VidPlayerOn = 0;

        while (1) {
            StopVid = StopVids();

            if (StopVid == 0) {
                puts("Вы выбрали продолжить.");
                break;
            }
            puts("Для дальнейшего просмотра нажмите 1");
            scanf("%d", &VidPlayerOn);
            if (VidPlayerOn == 1) {
                break;
            }
        }
    };
    void ChooseVid() override {
        char VidPlayerOn = 0, totalVideos = 3;
        OpenVid();
        while (1) {
            if (totalVideos == 0) {
                printf("Нет доступных видео для воспроизведения!\n");
                break;
            }
            int randomIndex;
            int Allow;
            do {
                randomIndex = rand() % totalVideos;
                Allow = 1;
                for (int i = 0; i < N; i++) {
                    if (strcmp(AllVid[randomIndex], LastVid[i]) == 0) {
                        Allow = 0;
                        break;
                    }
                }
            } while (Allow == 0);

            for (int i = 0; i < N; i++) {
                if (LastVid[i][0] == '\0') {
                    strcpy(LastVid[i], AllVid[randomIndex]);
                    break;
                }
            }
            printf("Воспроизводится видео: %s........\n", AllVid[randomIndex]);
            Voice voice;
            int loudness = voice.VidVoice(); // Получаем ссылку на Loud
            ButtonStopVid vid;
            vid.OnVid();
            bool endSession = false;
            bool sessionEnded = false;
            EndWork::End(&sessionEnded);
            totalVideos--;
            puts("Если вы хотите выйти из плеера, нажмите 1, иначе - 0");
            scanf("%d", &VidPlayerOn);
            if (VidPlayerOn == 1) {
                break;
            }
        }
        if (VidPlayerOn == 1) {
            ChooseVid();
        }
    }
};
#endif