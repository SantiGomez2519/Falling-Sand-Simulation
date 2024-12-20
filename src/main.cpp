#include <raylib.h>
#include <vector>
#include <array>
#include <iostream>

#include "grid.h"
#include "sand.h"


bool isSandUnder(Vector2 position, std::vector<Sand> &sand){
    // Check if there is sand under or next to the current sand
    for (auto &s : sand) {
        if (s.getPos().x == position.x && s.getPos().y == position.y + s.getSize()) {
            return true;
        }
    }
    return false;
}

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
            if (!isSandUnder(s.getPos(), sand)) {
                s.update();
            } else {
                s.updateSandUnder(sand);
            }
        }

        BeginDrawing();
            ClearBackground(darkGreen);
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                sand.push_back(Sand());
            }

            for (auto &s : sand) {
                s.draw();
            }
        EndDrawing();
    }
    
    CloseWindow();
}