#pragma once
#include <vector>

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
        void addSand(int x, int y);
};