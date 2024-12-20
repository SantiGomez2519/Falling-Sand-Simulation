#include <raylib.h>
#include <iostream>
#include <vector>

class Sand {
    private:
        Color color = DARKBLUE;
        float x;
        float y;
        float size;
        int gravity;

    public:
        Sand();

        void draw();

        void update();

        void updateSandUnder(std::vector<Sand> &sand);

        Vector2 getPos() {
            return {x, y};
        }

        int getSize() {
            return size;
        }
};