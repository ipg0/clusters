#ifndef POINT_H
#define POINT_H
#include <cmath>

typedef unsigned long size_t;

class Point {
public:
    float x, y;
    size_t clusterMark;
    Point() { x = y = 0; clusterMark = 0; }
    Point(float _x, float _y, size_t _clusterMark = 0) { x = _x; y = _y, clusterMark = _clusterMark; }
    bool clusterDefined() { return !(clusterMark == 0); }
    void displace(float dx, float dy) { x += dx; y += dy; }
    void rotate(Point *pivot, float dphi) {
        x -= pivot->x, y -= pivot->y;
        float cosp = cos(dphi), sinp = sin(dphi),
            _x = x * cosp - y * sinp,
            _y = x * sinp + y * cosp;
        x = _x + pivot->x, y = _y + pivot->y; 
    };
};

#endif