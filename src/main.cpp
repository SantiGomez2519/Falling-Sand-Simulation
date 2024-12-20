#include <raylib.h>
#include <vector>
#include <array>
#include <iostream>

#include "grid.h"
#include "sand.h"

int main() {
    // Background color
    const Color darkGreen = {255, 255, 255, 255};
    
    // Screen dimensions
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;


    // Initialize window
    InitWindow(screenWidth, screenHeight, "Falling Sand Simulator!");
    ClearBackground(darkGreen);
    SetTargetFPS(60); // Set FPS

    // Grid
    Grid grid;

    // Sand
    std::vector<Sand> sand;
    

    while (!WindowShouldClose()) {
        // Update
        for (auto &s : sand) {
            s.update();
        }

        BeginDrawing();
            ClearBackground(darkGreen);
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                sand.push_back(Sand());
            }

            for (auto &s : sand) {
                s.draw();
            }
        EndDrawing();
    }
    
    CloseWindow();
}