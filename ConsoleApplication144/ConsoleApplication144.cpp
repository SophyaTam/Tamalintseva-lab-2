#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>

#define N 200
#define M 200

struct {
    char AvailableOptions[N - 1][M - 1];
}MainMenu[N][M];
void AddOptions(char AvailableOptions[N][M]) {
    strncpy(AvailableOptions[0], "1-Детское", M);
    strncpy(AvailableOptions[1], "2-Детективы", M);
    strncpy(AvailableOptions[2], "3-Комедии", M);
    strncpy(AvailableOptions[3], "4-Мелодраммы", M);
    strncpy(AvailableOptions[4], "5-Сериалы", M);
}
struct {
    int EndAll;
}EndWork;
void End() {
    int EndAll = 0;
    puts("Нажмите 7, если хотите полностью завершить сеанс.");
    scanf("%d", &EndAll);

    if (EndAll == 7) {
        puts("Завершение сеанса...");
        exit(0); 
    }
}
int ChooseOptions() {
    int Djanre = 0;
    char AvailableOptions[N][M];
    AddOptions(AvailableOptions);

    for (int i = 0; i < 5; i++) {
        printf("%s\n", AvailableOptions[i]);
    }

    puts("Выберите желаемое направление (1-5): ");

    while (1) {
        scanf("%d", &Djanre);
        if (Djanre >= 1 && Djanre <= 5) {
            break;
        }
        else {
            puts("Неверный ввод! Пожалуйста, введите число от 1 до 5.");
            while (getchar() != '\n');
        }
    }
    return Djanre;
}
struct {
    int Loud;
    char Colour[10];
}Voice;
void VidVoice() {
    int Loud = 0;
    puts("Введите уровень громкости");
    // Используем & для передачи адреса переменной
    scanf("%d", &Loud);
    printf("Уровень громкости видео изменен до %d\n", Loud);
}
struct {
    char *TurnOnTheAdvert;
    char LastAdvert[N][M];
    int AllAdvert[N];
}Advert;
struct {
    char StopAdv;
    char AdvPlayerOn;
}ButtonStopAdv;
int StopAdvs() {
    puts("Если хотите остановить видео, нажмите 1, иначе - 0");
    int StopAdv = 0;
    scanf("%d", &StopAdv); 
    if (StopAdv == 1) {
        puts("Реклама остановлена");
    }
    return StopAdv;
}

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
}
int ChooseAdvert() {
    int Turn;
    puts("Введите 1, если хотите добавить рекламу и 0 - если нет");
    scanf("%d", &Turn);
    return Turn;
}

void NameAd(int AllAdvert[N]) {
    for (int i = 0; i < N; i++) {
        AllAdvert[i] = i + 1; 
    }
}

void LastAdverts(int LastAdvert[N]) {
    for (int i = 0; i < N; i++) {
        LastAdvert[i] = 0; 
    }
}

void ShowAdv() {
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
struct {
    char LastVid[N][M];
    char AllVid[N][M];
}Video;
struct {
    char StopAdv;
    char AdvPlayerOn;
}ButtonStopVid;
int StopVids() {
    puts("Если хотите остановить видео, нажмите 1, иначе - 0");
    int StopVid = 0;
    scanf("%d", &StopVid);
    if (StopVid == 1) {
        puts("Видео остановлена");
    }
    return StopVid;
}

void OnVid() {
    int StopVid = 0;
    int VidPlayerOn = 0;

    while (1) {
        StopVid = StopAdvs();

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
void OpenVid(char AllVid[N][M]) {
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

void LastVids(char LastVid[N][M]) {
    for (int i = 0; i < N; i++) {
        LastVid[i][0] = '\0';
    }
}

void ChooseVid() {
    char AllVid[N][M], LastVid[N][M];
    LastVids(LastVid);
    OpenVid(AllVid); 
    if (AllVid[0][0] == '\0') {
        printf("Нет видео для воспроизведения!\n");
        return;
    }

    int randomIndex;
    int Allow;
    srand(time(NULL));

    do {
        randomIndex = rand() % 4; 
        Allow = 1;

        for (int i = 0; i < N; i++) {
            if (strcmp(AllVid[randomIndex], LastVid[i]) == 0) {
                Allow = 0; 
                break;
            }
        }
    } while (Allow == 0);
    VidVoice();
    printf("Воспроизводится видео: %s........\n", AllVid[randomIndex]); OnVid(); End();
}
struct {
    char VidPlayerOn;
}VideoPlayer;
void BaskPlayer() {
    int dj = 0, VidPlayerOn = 0;
    puts("Если вы хотите выйти из плеера, нажмите 1");
    scanf("%d", &VidPlayerOn); 

    if (VidPlayerOn == 1) {
        ChooseVid(); 
    }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    char AvailableOptions[N - 1][M - 1], AllVid[N][M], LastVid[N][M];
    int Djanre=0,Turn=0, AllAdvert[N], LastAdvert[N], Back=0;
    ShowAdv();
    ChooseVid();
    BaskPlayer();
}

