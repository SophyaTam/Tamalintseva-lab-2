#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>

#define N 200
#define M 200
//����� ��� �������� �������� ���� � ������� ������������ ����� �������� ����������� ��� ��������� ����������� ������� ��������������� �����
//������������ ����� ������ ��������� ������
class MainMenu {
private:
    char AvailableOptions[N][M];
public:
    MainMenu();
    void AddOptions();
    int ChooseOptions();
};
MainMenu::MainMenu() {
    AddOptions(); 
}
void MainMenu::AddOptions() {
    strncpy(AvailableOptions[0], "1-�������", M);
    strncpy(AvailableOptions[1], "2-���������", M);
    strncpy(AvailableOptions[2], "3-�������", M);
    strncpy(AvailableOptions[3], "4-����������", M);
    strncpy(AvailableOptions[4], "5-�������", M);
}
//������� ��� ������ �� ����� ���� ��������� ����������� � ������ ������ �� ���
int MainMenu::ChooseOptions() {
    int Djanre = 0;
    for (int i = 0; i < 5; i++) {
        printf("%s\n", AvailableOptions[i]);
    }
    puts("�������� �������� ����������� (1-5): ");
    while (1) {
        scanf("%d", &Djanre);
        if (Djanre >= 1 && Djanre <= 5) { break; }
        else {
            puts("�������� ����! ����������, ������� ����� �� 1 �� 5.");
            while (getchar() != '\n');
        }
    }
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
//����� ����� ��� ��������� ������ ��������� ����� ���� � ������� ���������������� ����� �� 0 �� 100
class Voice {
private:
    int Loud;
    char Colour[10];
public:
    void VidVoice();
};
//������� ��� ����� ���������� �������� ��������� �����
void Voice:: VidVoice() {
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
//����� ��� ����������� ������������ ������� ����� ������� 0 � 1
class Advert {
private:
    char TurnOnTheAdvert;
    int* AllAdvert;
    int* NamesAdd;
    int* LastAdvert;
public:
    Advert();
    ~Advert();
    int ChooseAdvert();
    void NameAd();
    void LastAdverts();
    void ShowAdv();
};

// ����������� ��������� ButtonStopAdv
class ButtonStopAdv : public Advert { //  ButtonStopAdv ��������� Advert
private:
    char StopAdv;
    char AdvPlayerOn;
public:
    int StopAdvs();
    void OnAdv();
};

// ������� ����������� ������� ��� ��������� ����� ���� 1
int Advert::ChooseAdvert() {
    int Turn;
    puts("������� 1, ���� ������ �������� ������� � 0 - ���� ���: ");
    scanf("%d", &Turn);
    return Turn;
}

// ������� ���������� �������� ������� � ������
void Advert::NameAd() {
    for (int i = 0; i < N; i++) {
        NamesAdd[i] = i + 1; // ���������� ������� � ����������
    }
}

// ������� ���������� ������� � ��� ����������� ��������
void Advert::LastAdverts() {
    for (int i = 0; i < N; i++) {
        LastAdvert[i] = 0; // ������������� �� ��������������� �������
    }
}

// ����������� ������ Advert
Advert::Advert() {
    AllAdvert = new int[N];
    NamesAdd = new int[N];
    LastAdvert = new int[N];
    LastAdverts();
}

// ���������� ������ Advert
Advert::~Advert() {
    delete[] AllAdvert;
    delete[] NamesAdd;
    delete[] LastAdvert;
}

// ������� ��� ������ ��������� ������� � � ���������������
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
        printf("������ �������: #%d........\n", NamesAdd[randomIndex]);
        ButtonStopAdv adv; 
        adv.OnAdv(); 
        for (int i = 0; i < N; i++) {
            if (LastAdvert[i] == 0) { 
                LastAdvert[i] = NamesAdd[randomIndex];
                break;}}}
}

// ������� ��� ��������� ������� ����������� ����� ����� 1
int ButtonStopAdv::StopAdvs() {
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

// ������� ��� ������������� ��������������� ����� ����� ���� 1
void ButtonStopAdv::OnAdv() {
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
// ����� ��� ������ ����� � ��� ������������
class Video {
private:
    char** LastVid;
    char** AllVid;

public:
    Video(); // �����������
    ~Video(); // ����������
    void OpenVid();
    void LastVids();
    void ChooseVid();
};
//��������� ��� ������������ � ��������������� �����
class ButtonStopVid:public Video {
private: 
    char StopVid;
    char VidPlayerOn;
public:
    int StopVids();
    void OnVid();
};
// ����������� ������ Video
Video::Video() {
    LastVid = new char* [N];
    AllVid = new char* [N];
    for (int i = 0; i < N; ++i) {
        LastVid[i] = new char[M]; 
        AllVid[i] = new char[M]; 
    }
    LastVids(); 
}

// ���������� ������ Video
Video::~Video() {
    for (int i = 0; i < N; ++i) {
        delete[] LastVid[i]; 
        delete[] AllVid[i]; 
    }
    delete[] LastVid; 
    delete[] AllVid; 
}
// ������� ��� ��������� ����� ����� ���� 1
int ButtonStopVid::StopVids() {
    puts("���� ������ ���������� �����, ������� 1, ����� - 0");
    StopVid = 0;
    scanf("%d", &StopVid);
    if (StopVid == 1) {
        puts("����� �����������");
    }
    return StopVid;
}

// ������� ��� ����������� ��������� ����� ���� 1
void ButtonStopVid::OnVid() {
    StopVid = 0;
    VidPlayerOn = 0;

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
// ������� ��� ���������� ������� � ���������� ����� ��� ���������
void Video::OpenVid() {
    MainMenu menu;
    int Djanre = menu.ChooseOptions();
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

// ������� ��� ���������� ������� � ������������ �����
void Video::LastVids() {
    for (int i = 0; i < N; i++) {
        LastVid[i][0] = '\0';
    }
}

// ������� ��� ������ ���������� �����
void Video::ChooseVid() {
    char VidPlayerOn = 0, totalVideos = 3;
    OpenVid();
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
        printf("��������������� �����: %s........\n", AllVid[randomIndex]);
        ButtonStopVid vid;
        vid.OnVid();
        EndWork end;
        end.End();
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
//���������� ����� ������������������ ��� ������� ��������� ������
class VideoPlayer {
private:
    char VidPlayerOn;
};