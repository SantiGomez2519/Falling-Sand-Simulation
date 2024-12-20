#include <raylib.h>
#include <iostream>

class Sand {
    private:
        Color color = DARKBLUE;
        float x;
        float y;
        int size;
        int gravity;

    public:
        Sand();

        void draw();

        void update();
};