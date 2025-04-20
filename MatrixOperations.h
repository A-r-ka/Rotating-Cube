//
// Created by Elon Pereira Neto on 19/04/25.
//
#pragma once

float* rotateX(float angle, float i, float j, float k);

float* rotateY(float angle, float i, float j, float k);

float* rotateZ(float angle, float i, float j, float k);

void rotateX(float angle, float* vector);

void rotateY(float angle, float* vector);

void rotateZ(float angle, float* vector);

float* rotate(float angle, float cubeX, float cubeY, float cubeZ);