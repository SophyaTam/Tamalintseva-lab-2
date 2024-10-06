#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>

#define N 200
#define M 200
//��������� ��� �������� �������� ���� � ������� ������������ ����� �������� ����������� ��� ���������
//������������ ����� ������ ��������� ������
class MainMenu {
private:
    char AvailableOptions[N][M];
public:
    void AddOptions();
    int ChooseOptions();
};
void MainMenu:: AddOptions() {
        strncpy(AvailableOptions[0], "1-�������", M);
        strncpy(AvailableOptions[1], "2-���������", M);
        strncpy(AvailableOptions[2], "3-�������", M);
        strncpy(AvailableOptions[3], "4-����������", M);
        strncpy(AvailableOptions[4], "5-�������", M);
}
//������� ��� ������ �� ����� ���� ��������� ����������� � ������ ������ �� ���
int MainMenu:: ChooseOptions() {
    int Djanre = 0;
    char AvailableOptions[N][M];
    for (int i = 0; i < N; i++) {
        std::cout << AvailableOptions[i] << std::endl; 
    }
    puts("�������� �������� ����������� (1-5): ");
    while (1) {
        scanf("%d", &Djanre);
        if (Djanre >= 1 && Djanre <= 5) {break;}
        else {
            puts("�������� ����! ����������, ������� ����� �� 1 �� 5.");
            while (getchar() != '\n');
        }}
    return Djanre;
}
//������ ��� ������� �������� ��������� ��� ������� �� ������� ����������� ������ ���������� ����������, � � ����������� ���������� ����� ��������� �����
class EndWork {
    private:
        int EndAllElements;
    public:
        void End();
};
//������� ���������� ��������� ����� ���� � ������� ����� 7
void EndWork:: End() {
    int EndAll = 0;
    printf("���� ������ ��������� ������ ������������������, ������� 7");
    scanf("%d", &EndAll);
    if (EndAll == 7) {
        puts("���������� ������...");
        exit(0);
    }
}
//������� ����� ��� ��������� ������ ��������� ����� ���� � �������
struct {
    int Loud;
    char Colour[10];
}Voice;
//������� ��� ����� ���������� �������� ��������� �����
void VidVoice() {
    int Loud = 0;
    do {
        printf("������� ������� ��������� (�� 0 �� 100): ");
        if (scanf("%d", &Loud) != 1) {
            printf("������: ������� �������� ��������.\n");
            while (getchar() != '\n');
            Loud = -1;
        }
        else if (Loud < 0 || Loud > 100) {
            printf("������: ������� ��������� ������ ���� � �������� �� 0 �� 100.\n");
        }
        else {
            printf("������� ��������� ����� ������� �� %d\n", Loud);
        }
    } while (Loud < 0 || Loud > 100);
}
//������� ��� ������ ����������� � ���������� ������� ����� ������� 0 � 1 � ����� ���� ������� �� ����� ������� ����� �������� ��������
struct {
    char* TurnOnTheAdvert;
    char LastAdvert[N][M];
    int AllAdvert[N];
}Advert;
//��������� ��� ����������� ������������ ������� ����� ������� 0 � 1
struct {
    char StopAdv;
    char AdvPlayerOn;
}ButtonStopAdv;
//������� ��� ��������� ������� ����������� ����� ����� 1
int StopAdvs() {
    int StopAdv = 0;
    do {
        puts("���� ������ ���������� �����, ������� 1, ����� - 0");
        if (scanf("%d", &StopAdv) != 1) {
            printf("������: ������� �������� ��������.\n");
            while (getchar() != '\n');
            StopAdv = -1;
        }
        else if (StopAdv < 0 || StopAdv > 1) {
            printf("������: ���� ������ ���������� �����, ������� 1, ����� - 0.\n");
        }
    } while (StopAdv < 0 || StopAdv > 1);
    if (StopAdv == 1) {
        puts("������� �����������");
    }
    return StopAdv;
}
//������� ���  ������������� ��������������� ����� �����  ����  1
void OnAdv() {
    int StopAdv = 0;
    int AdvPlayerOn = 0;

    while (1) {
        StopAdv = StopAdvs();

        if (StopAdv == 0) {
            puts("�� ������� ����������.");
            break;
        }
        puts("��� ����������� ��������� ������� 1");
        scanf("%d", &AdvPlayerOn);
        if (AdvPlayerOn == 1) {
            break;
        }
    }
}
//������� ����������� ������� ��� ��������� ����� ����  1
int ChooseAdvert() {
    int Turn;
    puts("������� 1, ���� ������ �������� ������� � 0 - ���� ���");
    scanf("%d", &Turn);
    return Turn;
}
//������� ���������� �������� ������� � ������
void NameAd(int AllAdvert[N]) {
    for (int i = 0; i < N; i++) {
        AllAdvert[i] = i + 1;
    }
}
//������� ���������� ������� � ��� ����������� ��������
void LastAdverts(int LastAdvert[N]) {
    for (int i = 0; i < N; i++) {
        LastAdvert[i] = 0;
    }
}
//������� ��� ������ ��������� ������� � � ���������������
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
        printf("������ �������: #%d........\n", NamesAdd[randomIndex]); OnAdv();
        for (int i = 0; i < N; i++) {
            if (LastAdvert[i] == 0) {
                LastAdvert[i] = NamesAdd[randomIndex];
                break;
            }
        }
    }
}
//��������� ��� ������ ����� � ��� ������������, �� ����� ������� ���� ����� �������� ����� �� ����� 
struct {
    char LastVid[N][M];
    char AllVid[N][M];
}Video;
//��������� ��� ������������ � ��������������� �����
struct {
    char StopAdv;
    char AdvPlayerOn;
}ButtonStopVid;
//������� ��� ��������� ����� ����� ���� 1
int StopVids() {
    puts("���� ������ ���������� �����, ������� 1, ����� - 0");
    int StopVid = 0;
    scanf("%d", &StopVid);
    if (StopVid == 1) {
        puts("����� �����������");
    }
    return StopVid;
}
//������� ��� ����������� ���������  ����� ���� 1
void OnVid() {
    int StopVid = 0;
    int VidPlayerOn = 0;

    while (1) {
        StopVid = StopVids();

        if (StopVid == 0) {
            puts("�� ������� ����������.");
            break;
        }
        puts("��� ����������� ��������� ������� 1");
        scanf("%d", &VidPlayerOn);
        if (VidPlayerOn == 1) {
            break;
        }
    }
}
//������� ��� ���������� ������� � ���������� ����� ��� ���������
void OpenVid(char AllVid[N][M]) {
    int Djanre = ChooseOptions();

    char filename[M];
    snprintf(filename, M, "%d.txt", Djanre);

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("������ �������� �����");
        return;
    }
    int count = 0;
    while (fgets(AllVid[count], M, file) != NULL && count < N) {
        AllVid[count][strcspn(AllVid[count], "\n")] = '\0';
        count++;
    }

    fclose(file);
}
//������� ��� ���������� ������� � ������������ �����
void LastVids(char LastVid[N][M]) {
    for (int i = 0; i < N; i++) {
        LastVid[i][0] = '\0';
    }
}
//������� ��� ������ ���������� �����
void ChooseVid() {
    char AllVid[N][M], LastVid[N][M], VidPlayerOn = 0, totalVideos = 3;
    OpenVid(AllVid);
    while (1) {
        if (totalVideos == 0) {
            printf("��� ��������� ����� ��� ���������������!\n");
            break;
        }

        int randomIndex;
        int Allow;

        do {
            randomIndex = rand() % totalVideos;
            Allow = 1;

            // ���������, �� ���� �� ��� ����� ��� ��������������
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
        printf("��������������� �����: %s........\n", AllVid[randomIndex]);
        OnVid();
        End();
        totalVideos--;
        puts("���� �� ������ ����� �� ������, ������� 1, ����� - 0");
        scanf("%d", &VidPlayerOn);
        if (VidPlayerOn == 1) {
            break;
        }
    }
    if (VidPlayerOn == 1) {
        ChooseVid();
    }
}
//��������� ���������/���������� �����������
struct {
    char VidPlayerOn;
}VideoPlayer;