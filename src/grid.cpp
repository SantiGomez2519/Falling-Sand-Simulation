#include "grid.h"
#include <raylib.h>

Grid::Grid() {
    rows = GetScreenHeight() / squareSize;
    cols = GetScreenWidth() / squareSize;
    matrix.resize(rows, std::vector<int>(cols, 0)); // Initialize as empty
}


void Grid::draw() {
    // Increment RGB components at different rates
    colorR = (colorR + 1) % 256; // Increment red
    colorG = (colorG + 1) % 256; // Increment green
    colorB = (colorB + 1) % 256; // Increment blue

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1) {
                DrawRectangle(j * squareSize, i * squareSize, squareSize, squareSize, (Color){colorR, colorG, colorB, 255});
            } else {
                DrawRectangle(j * squareSize, i * squareSize, squareSize, squareSize, BLACK);
            }
        }
    }   
}

void Grid::update(std::vector<Sand> &sand) {
    for (auto &s : sand) {
        int x = s.getX() / squareSize;
        int y = s.getY() / squareSize;

        if (y < rows - 1) {
            if (matrix[y + 1][x] == 0) {
                matrix[y][x] = 0;
                matrix[y + 1][x] = 1;

                // Update sand position
                s.setX(x * squareSize);
                s.setY((y + 1) * squareSize);
            } else {
                if (matrix[y + 1][x -1] == 0){
                    matrix[y][x] = 0;
                    matrix[y + 1][x - 1] = 1;

                    // Update sand
                    s.setX((x - 1) * squareSize);
                    s.setY((y + 1) * squareSize); 
                }
                else if (matrix[y + 1][x + 1] == 0){
                    matrix[y][x] = 0;
                    matrix[y + 1][x + 1] = 1;

                    // Update sand
                    s.setX((x + 1) * squareSize);
                    s.setY((y + 1) * squareSize);
                }
            }
        }
    }
}

void Grid::addSand(int x, int y, std::vector<Sand> &sand) {
    x = x + (rand() % 2); // Randomize x position
    y = y + (rand() % 2); // Randomize y position
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            matrix[y + i][x + j] = 1;
            Sand s;
            s.setX((x + j) * squareSize);
            s.setY((y + i) * squareSize);
            sand.push_back(s);
        }
    }
}