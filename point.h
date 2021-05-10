#ifndef POINT_H
#define POINT_H
#include <cmath>

typedef unsigned long size_t;

class Point {
public:
    double x, y;
    size_t clusterMark;
    Point() { x = y = 0; clusterMark = 0; }
    Point(double _x, double _y, size_t _clusterMark = 0) { x = _x; y = _y, clusterMark = _clusterMark; }
    bool clusterDefined() { return !(clusterMark == 0); }
    void displace(double dx, double dy) { x += dx; y += dy; }
    void reset() { clusterMark = 0; }
    void rotate(Point &pivot, double dphi) {
        x -= pivot.x, y -= pivot.y;
        double cosp = cos(dphi), sinp = sin(dphi),
            _x = x * cosp - y * sinp,
            _y = x * sinp + y * cosp;
        x = _x + pivot.x, y = _y + pivot.y; 
    };
    bool operator==(Point &other) const { return (x == other.x) && (y == other.y); }
    bool operator!=(Point &other) const { return !operator==(other); }
};

#endif