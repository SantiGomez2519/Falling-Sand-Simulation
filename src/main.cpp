#include <raylib.h>
#include "grid.h"

int main() {
    // Background color
    const Color darkGreen = {255, 255, 255, 255};
    
    // Screen dimensions
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;

    // Initialize window
    InitWindow(screenWidth, screenHeight, "Falling Sand Simulator!");
    SetTargetFPS(60); // Set FPS

    // Grid
    Grid grid(80, 60);
    

    while (!WindowShouldClose()) {
        grid.draw();

        BeginDrawing();
            ClearBackground(darkGreen);
        EndDrawing();
    }
    
    CloseWindow();
}