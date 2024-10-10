#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>

#define N 200
#define M 200
//Класс для описания главного меню в котором пользователи будут выбирать направление для просмотра посредством нажатия соответствующей цифры
//Представляет собой список доступных жанров
class MainMenu {
private:
    char AvailableOptions[N][M];
public:
    MainMenu() {
        AddOptions();
    };
    void AddOptions() {
        strncpy(AvailableOptions[0], "1-Детское", M);
        strncpy(AvailableOptions[1], "2-Детективы", M);
        strncpy(AvailableOptions[2], "3-Комедии", M);
        strncpy(AvailableOptions[3], "4-Мелодраммы", M);
        strncpy(AvailableOptions[4], "5-Сериалы", M);
    };
    //Метод для вывода на экран всех доступных направлений и выбора одного из них
    int ChooseOptions() {
        int Djanre = 0;
        for (int i = 0; i < 5; i++) {
            printf("%s\n", AvailableOptions[i]);
        }
        puts("Выберите желаемое направление (1-5): ");
        while (1) {
            scanf("%d", &Djanre);
            if (Djanre >= 1 && Djanre <= 5) { break; }
            else {
                puts("Неверный ввод! Пожалуйста, введите число от 1 до 5.");
                while (getchar() != '\n');
            }
        }
        return Djanre;
    };
};
//Кнопка для полного закрытия программы при нажатии на которую заканчивает работу консольное приложение, а в графическом приложении будет закрывать форму
class EndWork {
private:
    int EndAllElements;
public:
    //Метод завершения программы через ввод в консоль цифры 7
    void End() {
        int EndAll = 0;
        printf("Если хотите завершить работу видеопроигрывателя, нажмите 7");
        scanf("%d", &EndAll);
        if (EndAll == 7) {
            puts("Завершение сеанса...");
            exit(0);
        }
    };
};
//Класс звука для установки уровня громкости через ввод в консоль соответствующего числа от 0 до 100
class Voice {
private:
    int Loud;
    char Colour[10];
public:
    //Метод для ввода численного значения громкости видео
    void VidVoice() {
        int Loud = 0;
        do {
            printf("Введите уровень громкости (от 0 до 100): ");
            if (scanf("%d", &Loud) != 1) {
                printf("Ошибка: введите числовое значение.\n");
                while (getchar() != '\n');
                Loud = -1;
            }
            else if (Loud < 0 || Loud > 100) {
                printf("Ошибка: уровень громкости должен быть в пределах от 0 до 100.\n");
            }
            else {
                printf("Уровень громкости видео изменен до %d\n", Loud);
            }
        } while (Loud < 0 || Loud > 100);
    };
};
//Класс для возможности приостановки рекламы через команды 0 и 1
class Advert {
private:
    char TurnOnTheAdvert;
    int* AllAdvert;
    int* NamesAdd;
    int* LastAdvert;
public:
    Advert() {
        AllAdvert = new int[N];
        NamesAdd = new int[N];
        LastAdvert = new int[N];
        LastAdverts();
    };
    ~Advert() {
        delete[] AllAdvert;
        delete[] NamesAdd;
        delete[] LastAdvert;
    };
    // Метод подключения рекламы для просмотра через ввод 1
    int ChooseAdvert() {
        int Turn;
        puts("Введите 1, если хотите добавить рекламу и 0 - если нет: ");
        scanf("%d", &Turn);
        return Turn;
    };
    // Метод добавления названий рекламы в массив
    void NameAd() {
        for (int i = 0; i < N; i++) {
            NamesAdd[i] = i + 1; // Заполнение массива с названиями
        }
    };
    // Метод заполнения массива с уже проигранной рекламой
    void LastAdverts() {
        for (int i = 0; i < N; i++) {
            LastAdvert[i] = 0; // Инициализация не воспроизводимой рекламы
        }
    };
    void ShowAdv();
};

// Определение подкласса ButtonStopAdv
class ButtonStopAdv : public Advert { //  ButtonStopAdv подклассо Advert
private:
    char StopAdv;
    char AdvPlayerOn;
public:
    // Метод для остановки рекламы посредством ввода цифры 1
    int StopAdvs() {
        int StopAdv = 0;
        do {
            puts("Если хотите остановить видео, нажмите 1, иначе - 0");
            if (scanf("%d", &StopAdv) != 1) {
                printf("Ошибка: введите числовое значение.\n");
                while (getchar() != '\n');
                StopAdv = -1;
            }
            else if (StopAdv < 0 || StopAdv > 1) {
                printf("Ошибка: Если хотите остановить видео, нажмите 1, иначе - 0.\n");
            }
        } while (StopAdv < 0 || StopAdv > 1);
        if (StopAdv == 1) {
            puts("Реклама остановлена");
        }
        return StopAdv;
    };
    // Метод для возобновления воспроизведения видео через ввод 1
    void OnAdv() {
        int StopAdv = 0;
        int AdvPlayerOn = 0;

        while (1) {
            StopAdv = StopAdvs();

            if (StopAdv == 0) {
                puts("Вы выбрали продолжить.");
                break;
            }
            puts("Для дальнейшего просмотра нажмите 1");
            scanf("%d", &AdvPlayerOn);
            if (AdvPlayerOn == 1) {
                break;
            }
        }
    };
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
        ButtonStopAdv adv;
        adv.OnAdv();
        for (int i = 0; i < N; i++) {
            if (LastAdvert[i] == 0) {
                LastAdvert[i] = NamesAdd[randomIndex];
                break;
            }
        }
    }
}
// Класс для выбора видео и его проигрывания
class Video {
private:
    char** LastVid;
    char** AllVid;

public:
    Video() {
        LastVid = new char* [N];
        AllVid = new char* [N];
        for (int i = 0; i < N; ++i) {
            LastVid[i] = new char[M];
            AllVid[i] = new char[M];
        }
        LastVids();
    }; // Конструктор
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
        MainMenu menu;
        int Djanre = menu.ChooseOptions();
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
    void ChooseVid();
};
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
};
// Метод для вывода рандомного видео
void Video::ChooseVid() {
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
        Voice voi;
        voi.VidVoice();
        ButtonStopVid vid;
        vid.OnVid();
        EndWork end;
        end.End();
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
//Формальный класс видеопроигрывателя как объекта курсового проета
class VideoPlayer {
private:
    char VidPlayerOn;
};
