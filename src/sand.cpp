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

void Sand::updateSandUnder(std::vector<Sand> &sand){
    for (auto &s : sand) {
        if (s.getX() == x + 1 && s.getY() == y + 1) {
            // if (s.getPos().x == x && s.getPos().y == y + size) {
                y = s.getY() - size;
            // }
        }
    }
}

