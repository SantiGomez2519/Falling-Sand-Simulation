#pragma once
#include <vector>
#include "sand.h"

#ifndef GRID_H
#define GRID_H
class Grid {
    private:
        int rows;
        int cols;
        int squareSize = 10;
        std::vector<std::vector<int>> matrix; // 0 for empty, 1 for sand

    public:
        Grid();
        void draw();
        void update(std::vector<Sand> &sand);
        void addSand(int x, int y, std::vector<Sand> &sand);

        int getSquareSize() {
            return squareSize;
        }
};

#endif