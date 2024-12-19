#pragma once

class Grid {
    private:
        int rows;
        int cols;
        int squareSize = 10;

    public:
        Grid(int rows, int cols);
        void draw();
};