#include "grid.h"
#include <raylib.h>

Grid::Grid() {
    rows = GetScreenHeight() / squareSize;
    cols = GetScreenWidth() / squareSize;
    matrix.resize(rows, std::vector<int>(cols, 0)); // Initialize as empty
}


void Grid::draw() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1) {
                DrawRectangle(j * squareSize, i * squareSize, squareSize, squareSize, YELLOW);
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
                s.setX(x * squareSize);
                s.setY((y + 1) * squareSize);
            }
        }
    }
}

void Grid::addSand(int x, int y, std::vector<Sand> &sand) {
    matrix[y][x] = 1;
    Sand s;
    s.setX(x * squareSize);
    s.setY(y * squareSize);
    sand.push_back(s);
}