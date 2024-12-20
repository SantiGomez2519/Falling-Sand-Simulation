#include <raylib.h>
#include <vector>
#include <array>
#include <iostream>

#include "grid.h"
#include "sand.h"


int main() {
    // Background color
    const Color black = BLACK;
    
    // Screen dimensions
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;


    // Initialize window
    InitWindow(screenWidth, screenHeight, "Falling Sand Simulator!");
    ClearBackground(black);
    SetTargetFPS(60); // Set FPS

    // Grid
    Grid grid;

    // Sand
    std::vector<Sand> sand;
    

    while (!WindowShouldClose()) {
        // Update
        grid.update(sand);

        BeginDrawing();
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                int x = GetMouseX() / grid.getSquareSize();
                int y = GetMouseY() / grid.getSquareSize();

                grid.addSand(x, y, sand);
            }

            grid.draw();
        EndDrawing();
    }
    
    CloseWindow();
}