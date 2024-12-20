#include <raylib.h>
#include <vector>
#include <array>
#include <iostream>

#include "grid.h"
#include "sand.h"


// bool isSandUnder(Vector2 position, std::vector<Sand> &sand){
//     // Check if there is sand under or next to the current sand
//     for (auto &s : sand) {
//         if (s.getPos().x == position.x && s.getPos().y == position.y + s.getSize()) {
//             return true;
//         }
//     }
//     return false;
// }

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
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                int x = GetMouseX() / grid.getSquareSize();
                int y = GetMouseY() / grid.getSquareSize();

                grid.addSand(x, y, sand);
            }

            grid.draw();
        EndDrawing();
    }
    
    CloseWindow();
}