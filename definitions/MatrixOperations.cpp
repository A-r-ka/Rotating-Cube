//
// Created by Elon Pereira Neto on 19/04/25.
//

#include <cmath>
#include "MatrixOperations.h"

using namespace std;

float* rotateX(const float angle, const float i, const float j, const float k) {
    const auto vector = new float[3];
    vector[0] = i * cos(angle) - j * sin(angle);
    vector[1] = i * sin(angle) + j * cos(angle);
    vector[2] = k;

    return vector;
}

float* rotateY(const float angle, const float i, const float j, const float k) {
    const auto vector = new float[3];
    vector[0] = i * cos(angle) - k * sin(angle);
    vector[1] = j;
    vector[2] = i * sin(angle) + k * cos(angle);

    return vector;
}

float* rotateZ(const float angle, const float i, const float j, const float k) {
    const auto vector = new float[3];
    vector[0] = i;
    vector[1] = j * cos(angle) - k * sin(angle);
    vector[2] = j * sin(angle) + k * cos(angle);

    return vector;
}

void rotateX(const float angle, float* vector) {
    vector[0] = vector[0] * cos(angle) - vector[1] * sin(angle);
    vector[1] = vector[0] * sin(angle) + vector[1] * cos(angle);

}

void rotateY(const float angle, float* vector) {
    vector[0] = vector[0] * cos(angle) + vector[2] * sin(angle);
    vector[2] = - vector[0] * sin(angle) + vector[2] * cos(angle);

}

void rotateZ(const float angle, float* vector) {
    vector[1] = vector[1] * cos(angle) - vector[2] * sin(angle);
    vector[2] = vector[1] * sin(angle) + vector[2] * cos(angle);

}

float* rotate(const float angle, const float cubeX, const float cubeY, const float cubeZ) {
    const float i = cubeX;
    const float j = cubeY;
    const float k = cubeZ;

    const float A = angle;
    const float B = angle;
    const float C = angle + 0.01;

    const auto vector = new float[3];

    vector[0] = j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
         j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);

    vector[1] =  j * cos(A) * cos(C) + k * sin(A) * cos(C) -
         j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
         i * cos(B) * sin(C);

    vector[2] = k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);

    return vector;

}