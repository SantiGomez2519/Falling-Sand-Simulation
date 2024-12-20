#include "grid.h"
#include <raylib.h>

Grid::Grid() {
    // this->rows = rows;
    // this->cols = cols;
}

void Grid::draw() {
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();

    Vector2 offset = { 0 };
    offset.x = screenWidth%squareSize;
    offset.y = screenHeight%squareSize;

    // Draw grid lines
    for (int i = 0; i < screenWidth/squareSize + 1; i++) {
        DrawLineV((Vector2){squareSize*i + offset.x/2, offset.y/2}, (Vector2){squareSize*i + offset.x/2, screenHeight - offset.y/2}, LIGHTGRAY);
    }

    for (int i = 0; i < screenHeight/squareSize + 1; i++) {
        DrawLineV((Vector2){offset.x/2, squareSize*i + offset.y/2}, (Vector2){screenWidth - offset.x/2, squareSize*i + offset.y/2}, LIGHTGRAY);
    }
}