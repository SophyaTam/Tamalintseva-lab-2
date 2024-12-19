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
#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

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
#endif

