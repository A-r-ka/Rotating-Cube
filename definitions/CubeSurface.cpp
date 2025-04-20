//
// Created by Elon Pereira Neto on 19/04/25.
//

#include "MatrixOperations.hpp"
#include "CubeSurface.hpp"

void CubeSurface::calculateSurface(const float angle, const float perspective, const float cubeX, const float cubeY, const float cubeZ) const {
    float* vector = rotate(angle, cubeX, cubeY, cubeZ);
    vector[2] += distanceFromCam;

    const float ooz = 1/vector[2];

    const int x = static_cast<int>(screenWidth / 2 + perspective * ooz * vector[0] * 2);
    const int y = static_cast<int>(screenHeight / 2 + perspective * ooz * vector[1]);

    const int idx = static_cast<int>(x + y * screenWidth);
    if (idx >= 0 && idx < screenWidth * screenHeight) {
        if (ooz > zBuffer[idx]) {
            zBuffer[idx] = ooz;
            buffer[idx] = surfaceChar;
        }
    }

    delete[] vector;

}
