#pragma once
#include <raylib.h>
#include <iostream>
#include <vector>

#ifndef SAND_H
#define SAND_H

class Sand {
    private:
        Color color = DARKBLUE;
        int x;
        int y;
        float size;
        int gravity;

    public:
        Sand();

        void draw();

        void update();

        void updateSandUnder(std::vector<Sand> &sand);

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }

        void setX(int x) {
            this->x = x;
        }

        void setY(int y) {
            this->y = y;
        }

        int getSize() {
            return size;
        }


};
#endif 