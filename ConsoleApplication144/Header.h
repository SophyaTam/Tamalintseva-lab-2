#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>

#define N 200
#define M 200
//Структура для описания главного меню в котором пользователи будут выбирать направление для просмотра
//Представляет собой список доступных жанров
class MainMenu {
private:
    char AvailableOptions[N][M];
public:
    void AddOptions();
    int ChooseOptions();
};
void MainMenu:: AddOptions() {
        strncpy(AvailableOptions[0], "1-Детское", M);
        strncpy(AvailableOptions[1], "2-Детективы", M);
        strncpy(AvailableOptions[2], "3-Комедии", M);
        strncpy(AvailableOptions[3], "4-Мелодраммы", M);
        strncpy(AvailableOptions[4], "5-Сериалы", M);
}
//Функция для вывода на экран всех доступных направлений и выбора одного из них
int MainMenu:: ChooseOptions() {
    int Djanre = 0;
    char AvailableOptions[N][M];
    for (int i = 0; i < N; i++) {
        std::cout << AvailableOptions[i] << std::endl; 
    }
    puts("Выберите желаемое направление (1-5): ");
    while (1) {
        scanf("%d", &Djanre);
        if (Djanre >= 1 && Djanre <= 5) {break;}
        else {
            puts("Неверный ввод! Пожалуйста, введите число от 1 до 5.");
            while (getchar() != '\n');
        }}
    return Djanre;
}
//Кнопка для полного закрытия программы при нажатии на которую заканчивает работу консольное приложение, а в графическом приложении будет закрывать форму
class EndWork {
    private:
        int EndAllElements;
    public:
        void End();
};
//Функция завершения программы через ввод в консоль цифры 7
void EndWork:: End() {
    int EndAll = 0;
    printf("Если хотите завершить работу видеопроигрывателя, нажмите 7");
    scanf("%d", &EndAll);
    if (EndAll == 7) {
        puts("Завершение сеанса...");
        exit(0);
    }
}
//Функция звука для установки уровня громкости через ввод в консоль
class Voice {
private:
    int Loud;
    char Colour[10];
public:
    void VidVoice();
};
//Функция для ввода численного значения громкости видео
void Voice:: VidVoice() {
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
}
//Функция для выбора подключения и отключения рекламы через команды 0 и 1 и выбор этой рекламы на этапе консоли через числовые значения
class Advert {
private:
    char* TurnOnTheAdvert;
    char LastAdvert[N][M];
    int AllAdvert[N];
public:
    int ChooseAdvert();
    void NameAd(int LastAdvert[N]);
    void LastAdverts(int LastAdvert[N]);
    void ShowAdv();
};
//Функция подключения рекламы для просмотра через ввод  1
int Advert:: ChooseAdvert() {
    int Turn;
    puts("Введите 1, если хотите добавить рекламу и 0 - если нет");
    scanf("%d", &Turn);
    return Turn;
}
//Функция добавления названий рекламы в массив
void Advert:: NameAd(int AllAdvert[N]) {
    for (int i = 0; i < N; i++) {
        AllAdvert[i] = i + 1;
    }
}
//Функция заполнения массива с уже проигранной рекламой
void Advert:: LastAdverts(int LastAdvert[N]) {
    for (int i = 0; i < N; i++) {
        LastAdvert[i] = 0;
    }
}
//Функция для выбора рандомной рекламы и её воспроизведения
void Advert:: ShowAdv() {
    int TurnOn = 0, NamesAdd[N], LastAdvert[N];

    TurnOn = ChooseAdvert();
    NameAd(NamesAdd);
    LastAdverts(LastAdvert);

    if (TurnOn == 1) {
        srand(time(NULL));
        int randomIndex;
        int Allow;

        do {
            randomIndex = rand() % N;
            Allow = 1;
            for (int i = 0; i < N; i++) {
                if (NamesAdd[randomIndex] == LastAdvert[i]) {
                    Allow = 0;
                    break;
                }
            }
        } while (Allow == 0);
        printf("Играет реклама: #%d........\n", NamesAdd[randomIndex]); OnAdv();
        for (int i = 0; i < N; i++) {
            if (LastAdvert[i] == 0) {
                LastAdvert[i] = NamesAdd[randomIndex];
                break;
            }
        }
    }
}
//Структура для возможности приостановки рекламы через команды 0 и 1
class ButtonStopAdv{
private:
    char StopAdv;
    char AdvPlayerOn;
public:
    int StopAdvs();
    void OnAdv();
};
//Функция для остановки рекламы посредством ввода цифры 1
int ButtonStopAdv:: StopAdvs() {
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
}
//Функция для  возобновления воспроизведения видео через  ввод  1
void ButtonStopAdv:: OnAdv() {
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
}
//Структура для выбора видео и его проигрывания, на этапе консоли идет выбор названия видео из файла 
class Video {
private:
    char LastVid[N][M];
    char AllVid[N][M];
public:
    void OpenVid(char AllVid[N][M]);
    void LastVids(char LastVid[N][M]);
    void ChooseVid();

};
//Функция для заполнения массива с названиями видео для просмотра
void Video:: OpenVid(char AllVid[N][M]) {
    int Djanre = ChooseOptions();
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
}
//Функция для заполнения массива с проигранными видео
void Video:: LastVids(char LastVid[N][M]) {
    for (int i = 0; i < N; i++) {
        LastVid[i][0] = '\0';
    }
}
//Функция для вывода рандомного видео
void Video:: ChooseVid() {
    char AllVid[N][M], LastVid[N][M], VidPlayerOn = 0, totalVideos = 3;
    OpenVid(AllVid);
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

            // Проверяем, не было ли это видео уже воспроизведено
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
        VidVoice();
        printf("Воспроизводится видео: %s........\n", AllVid[randomIndex]);
        OnVid();
        End();
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
//Структура для приостановки и воспроизведения видео
class ButtonStopVid {
private:
    char StopAdv;
    char AdvPlayerOn;
public:
    int StopVids();
    void OnVid();
}ButtonStopVid;
//Функция для остановки видео через ввод 1
int ButtonStopVid:: StopVids() {
    puts("Если хотите остановить видео, нажмите 1, иначе - 0");
    int StopVid = 0;
    scanf("%d", &StopVid);
    if (StopVid == 1) {
        puts("Видео остановлено");
    }
    return StopVid;
}
//Функция для продолжения просмотра  через ввод 1
void ButtonStopVid:: OnVid() {
    int StopVid = 0;
    int VidPlayerOn = 0;

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
}
//Структура включения/выключения видеоплеера
class VideoPlayer {
private:
    char VidPlayerOn;
};