#ifndef POINT
#define POINT

struct Point {
    Point() {}
    Point(int x, int y) { this->x = x; this->y = y; }

    int x;
    int y;
};

#endif // POINT

