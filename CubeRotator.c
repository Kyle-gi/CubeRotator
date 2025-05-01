#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Rotation angles
float A = 0, B = 0, C = 0;

// Cube dimensions
float cubeWidth = 10;
int width = 160, height = 44;
float zBuffer[160 * 44];  // z-buffer to store depth information
char buffer[160 * 44];  // display buffer

// Background and camera settings
int backgroundASCIICode = ' ';
int distanceFromCam = 60;
float K1 = 40;

// Movement speed for rotation
float incrementSpeed = 0.6;

// Temporary variables for coordinates and depth
float x, y, z;
float ooz;
int xp, yp, idx;

// Function to calculate the X-coordinate based on rotation angles
float calculateX(int i, int j, int k) {
    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
           j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

// Function to calculate the Y-coordinate based on rotation angles
float calculateY(int i, int j, int k) {
    return j * cos(A) * cos(C) + k * sin(A) * cos(C) - j * sin(A) * sin(B) * sin(C) +
           k * cos(A) * sin(B) * sin(C) - i * cos(B) * sin(C);
}

// Function to calculate the Z-coordinate based on rotation angles
float calculateZ(int i, int j, int k) {
    return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

// Function to calculate the surface of the cube
void calculateForSurface(float cubeX, float cubeY, float cubeZ, int ch) {
    // Calculate transformed 3D coordinates
    x = calculateX(cubeX, cubeY, cubeZ);
    y = calculateY(cubeX, cubeY, cubeZ);
    z = calculateZ(cubeX, cubeY, cubeZ) + distanceFromCam;

    // Depth calculation for perspective
    ooz = 1 / z;

    // Projection onto 2D screen
    xp = (int)(width / 2 - 2 * cubeWidth + K1 * ooz * x * 2);
    yp = (int)(height / 2 + K1 * ooz * y);

    // Calculate the index for the buffer
    idx = xp + yp * width;

    // Check if the pixel is within bounds
    if (idx >= 0 && idx < width * height) {
        if (ooz > zBuffer[idx]) {  // Check for depth (z-buffer)
            zBuffer[idx] = ooz;  // Update depth
            buffer[idx] = ch;  // Set pixel to character
        }
    }
}

int main() {
    // Clear the screen on startup
    printf("\x1b[2j");

    // Main game loop
    while (1) {
        // Clear the display and z-buffer
        memset(buffer, backgroundASCIICode, width * height);
        memset(zBuffer, 0, width * height * 4);

        // Loop through the cube's surface and calculate each side
        for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
            for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
                // Calculate each side of the cube
                calculateForSurface(cubeX, cubeY, -cubeWidth, '.');
                calculateForSurface(cubeWidth, cubeY, cubeX, '*');
                calculateForSurface(-cubeWidth, cubeY, -cubeX, '~');
                calculateForSurface(-cubeX, cubeY, cubeWidth, '#');
                calculateForSurface(cubeX, -cubeWidth, -cubeY, '-');
                calculateForSurface(cubeX, cubeWidth, cubeY, '+');
            }
        }

        // Reset cursor to the top left corner
        printf("\x1b[H");

        // Output the buffer to the screen
        for (int k = 0; k < width * height; k++) {
            putchar(k % width ? buffer[k] : 10);  // Print each character in the buffer
        }

        // Update rotation angles
        A += 0.005;
        B += 0.005;

        // Delay for smooth animation
        usleep(3000);
    }

    return 0;
}

