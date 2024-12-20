#include "sand.h"

Sand::Sand() {
    x = GetMouseX();
    y = GetMouseY();
    size = 10;
    color = YELLOW;
    gravity = 2;
}

void Sand::draw() {
    DrawRectangle(x, y, size, size, color);
}

void Sand::update() {
    
    if (y < GetScreenHeight() - size) {
        y += gravity;
    }
}