//
// Created by Elon Pereira Neto on 19/04/25.
//

#include <iostream>
#include <cstring>
#include <unistd.h>
#include "CubeSurface.hpp"

#define WIDTH 160
#define HEIGHT 44
#define CUBE_SIZE 10
#define SURFACE_CHAR '*'
#define SURFACE_COLOR "35"
#define DISTANCE_FROM_CAM 100
#define INCREMENT_SPEED 0.5

using namespace std;

void printBuffer(const char* buffer, int width, int height);

void main() {
    char buffer[WIDTH * HEIGHT];
    float zBuffer[WIDTH * HEIGHT];
    float angle = 0;
    const CubeSurface cubeSurface(buffer, zBuffer, WIDTH, HEIGHT, CUBE_SIZE, DISTANCE_FROM_CAM, SURFACE_CHAR);
    const CubeSurface cubeSurface2(buffer, zBuffer, WIDTH, HEIGHT, CUBE_SIZE, DISTANCE_FROM_CAM, '.');
    const CubeSurface cubeSurface3(buffer, zBuffer, WIDTH, HEIGHT, CUBE_SIZE, DISTANCE_FROM_CAM, '&');
    const CubeSurface cubeSurface4(buffer, zBuffer, WIDTH, HEIGHT, CUBE_SIZE, DISTANCE_FROM_CAM, '@');
    const CubeSurface cubeSurface5(buffer, zBuffer, WIDTH, HEIGHT, CUBE_SIZE, DISTANCE_FROM_CAM, '#');
    const CubeSurface cubeSurface6(buffer, zBuffer, WIDTH, HEIGHT, CUBE_SIZE, DISTANCE_FROM_CAM, '%');

    while (true) {
        memset(buffer, ' ', WIDTH * HEIGHT);
        memset(zBuffer, 0, WIDTH * HEIGHT * 4);
        cout << "\x1b[2J\x1b[H\x1b[" << SURFACE_COLOR << "m";

        for (float cubeX = -CUBE_SIZE; cubeX < CUBE_SIZE; cubeX += INCREMENT_SPEED) {
            for (float cubeY = -CUBE_SIZE; cubeY < CUBE_SIZE; cubeY += INCREMENT_SPEED) {
                cubeSurface.calculateSurface(angle, 40, cubeX, cubeY, -CUBE_SIZE);
                cubeSurface2.calculateSurface(angle, 40, CUBE_SIZE, cubeY, cubeX);
                cubeSurface3.calculateSurface(angle, 40, -CUBE_SIZE, cubeY, -cubeX);
                cubeSurface4.calculateSurface(angle, 40, -cubeX, cubeY, CUBE_SIZE);
                cubeSurface5.calculateSurface(angle, 40, cubeX, -CUBE_SIZE, -cubeY);
                cubeSurface6.calculateSurface(angle, 40, cubeX, CUBE_SIZE, cubeY);
            }
        }

        angle += 0.02;
        printBuffer(buffer, WIDTH, HEIGHT);
        usleep(10000);

    }

}

void printBuffer(const char* buffer, const int width, const int height) {
    for (int k = 0; k < width * height; k++) {
        putchar(k % width ? buffer[k] : 10);
    }
}

