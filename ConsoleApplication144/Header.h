#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <limits>
#include <iostream>
#include <vector>
#include <string>
#define N 200
#define M 200
//Класс для описания главного меню в котором пользователи будут выбирать направление для просмотра посредством нажатия соответствующей цифры
//Представляет собой список доступных жанров
class MainMenu {
private:
    std::vector<std::string> AvailableOptions;

public:
    MainMenu() {
        AddOptions();
    }

    void AddOptions() {
        AvailableOptions.push_back("Детское");
        AvailableOptions.push_back("Детективы");
        AvailableOptions.push_back("Комедии");
        AvailableOptions.push_back("Мелодраммы");
        AvailableOptions.push_back("Сериалы");
    }

    int ChooseOptions() {
        int Djanre = 0;
        for (size_t i = 0; i < AvailableOptions.size(); ++i) {
            std::cout << i + 1 << ". " << AvailableOptions[i] << std::endl; 
        }
        std::cout << "Выберите желаемое направление (1-" << AvailableOptions.size() << "): ";
        while (true) {
            if (!(std::cin >> Djanre) || Djanre < 1 || Djanre > AvailableOptions.size()) {
                std::cout << "Неверный ввод! Пожалуйста, введите число от 1 до " << AvailableOptions.size() << "." << std::endl;
                std::cin.clear(); 
                std::cin.ignore(256, '\n'); 
            }
            else {
                break;
            }
        }
        return Djanre;
    }
};
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
int Voice::Loud = 0; // Инициализация статического поля
//Класс для возможности приостановки рекламы через команды 0 и 1
//Класс для возможности приостановки рекламы через команды 0 и 1
class Advert {
protected:
    char TurnOnTheAdvert;
    int* AllAdvert;
    int* NamesAdd;
    int* LastAdvert;
    int size; 

public:
    // Конструктор с параметрами
    Advert(int size) : size(size) { 
        AllAdvert = new int[size];
        NamesAdd = new int[size];
        LastAdvert = new int[size];
        LastAdverts();
    }

    // Конструктор по умолчанию
    Advert() : Advert(N) {}

    // Копирующий конструктор
    Advert(const Advert& other) : size(other.size) { // Инициализация члена size из другого объекта
        AllAdvert = new int[size];
        NamesAdd = new int[size];
        LastAdvert = new int[size];
        TurnOnTheAdvert = other.TurnOnTheAdvert;

        for (int i = 0; i < size; i++) { // Используйте size
            AllAdvert[i] = other.AllAdvert[i];
            NamesAdd[i] = other.NamesAdd[i];
            LastAdvert[i] = other.LastAdvert[i];
        }
    }

    // Перегрузка оператора присваивания
    Advert& operator=(const Advert& other) {
        if (this != &other) {
            // Освобождение текущей памяти
            delete[] AllAdvert;
            delete[] NamesAdd;
            delete[] LastAdvert;

            size = other.size; 
            AllAdvert = new int[size];
            NamesAdd = new int[size];
            LastAdvert = new int[size];
            TurnOnTheAdvert = other.TurnOnTheAdvert;

            // Копирование данных
            for (int i = 0; i < size; i++) { 
                AllAdvert[i] = other.AllAdvert[i];
                NamesAdd[i] = other.NamesAdd[i];
                LastAdvert[i] = other.LastAdvert[i];
            }
        }
        return *this;
    }

    // Деструктор
    ~Advert() {
        delete[] AllAdvert;
        delete[] NamesAdd;
        delete[] LastAdvert;
    }

    // Метод подключения рекламы для просмотра через ввод 1
    virtual int ChooseAdvert() {
        int Turn;
        puts("Введите 1, если хотите добавить рекламу и 0 - если нет: ");
        scanf("%d", &Turn);
        return Turn;
    }

    // Метод добавления названий рекламы в массив
    void NameAd() {
        for (int i = 0; i < size; i++) { 
            NamesAdd[i] = i + 1;
        }
    };

    // Метод заполнения массива с уже проигранной рекламой
    void LastAdverts() {
        for (int i = 0; i < size; i++) { 
            LastAdvert[i] = 0; 
        }
    };

    void ShowAdv();
};

// Определение подкласса ButtonStopAdv
class ButtonStopAdv : public Advert {
public:
    // Конструктор производного класса с параметром
    ButtonStopAdv(int size) : Advert(size) {} // Вызов конструктора базового класса с параметром

    // Оверрайд метода
    int ChooseAdvert() override {
        int baseChoice = Advert::ChooseAdvert(); // Вызов метода базового класса
        if (baseChoice == 1) {
            puts("Реклама была добавлена через производный класс.");
        }
        else {
            puts("Реклама не была добавлена через производный класс.");
        }
        return baseChoice;
    }
    ButtonStopAdv& operator=(const ButtonStopAdv& other) {
        if (this != &other) {
            Advert::operator=(other); // Вызов оператора базового класса
        }
        return *this;
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
// Класс для выбора видео и его проигрывания
class Video {
protected:
    char** LastVid;
    char** AllVid;
    int N1;
    int M1;
public:
    Video(): N1(N1), M1(M1) {
        LastVid = new char* [N];
        AllVid = new char* [N];
        for (int i = 0; i < N; ++i) {
            LastVid[i] = new char[M];
            AllVid[i] = new char[M];
        }
        LastVids();
    }; 
    Video(const Video& other) : N1(other.N1), M1(other.M1) { // Конструктор копирования
        LastVid = new char*[N];
        AllVid = new char*[N];
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
            LastVid = new char*[N];
            AllVid = new char*[N];
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
    friend int chooseRandomVideo(Video& video); // Объявление дружественной функции
    virtual void ChooseVid()=0;
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
//Формальный класс видеопроигрывателя как объекта курсового проета
class VideoPlayer {
private:
    int playtime;
public:
    VideoPlayer(int playtime) : playtime(playtime) {}
    VideoPlayer operator+(const VideoPlayer& other) const {
        return VideoPlayer(playtime + other.playtime);// Возвращаем новый объект VideoPlayer, время воспроизведения которого равно сумме, времени воспроизведения текущего объекта и other
    }
    void printPlaytime() const {
        std::cout << "Время воспроизведения: " << playtime << " секунд" << std::endl;
    }
};

