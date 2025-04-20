//
// Created by Elon Pereira Neto on 19/04/25.
//
#pragma once

class CubeSurface {
public:
    CubeSurface(char* buffer,
        float* zBuffer,
        const float screenWidth,
        const float screenHeight,
        const float cubeSize,
        const float distanceFromCam,
        const char surfaceChar) : buffer(buffer),
                                zBuffer(zBuffer),
                                screenWidth(screenWidth),
                                screenHeight(screenHeight),
                                cubeSize(cubeSize),
                                distanceFromCam(distanceFromCam),
                                surfaceChar(surfaceChar) {}

    void calculateSurface(float angle, float perspective, float cubeX, float cubeY, float cubeZ) const;

private:
    char* buffer;
    float* zBuffer;
    float screenWidth;
    float screenHeight;
    float cubeSize;
    float distanceFromCam;
    char surfaceChar;

};
