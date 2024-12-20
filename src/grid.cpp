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
                DrawRectangle(j * squareSize, i * squareSize, squareSize, squareSize, WHITE);
            }
        }
    }
}