#ifndef POINT_H
#define POINT_H
#include <cmath>

typedef unsigned long size_t;

#define EPS 1e-4

class Point {
public:
    double x, y;
    size_t clusterMark;
    Point() { x = y = 0; clusterMark = 0; }
    Point(double _x, double _y, size_t _clusterMark = 0) { x = _x; y = _y; clusterMark = _clusterMark; }
    bool clusterDefined() { return !(clusterMark == 0); }
    void displace(double dx, double dy) { x += dx; y += dy; }
    void reset() { clusterMark = 0; }
    void rotate(Point &pivot, double dphi) {
        x -= pivot.x;
        y -= pivot.y;
        double cosp = cos(dphi), sinp = sin(dphi),
            _x = x * cosp - y * sinp,
            _y = x * sinp + y * cosp;
        x = _x + pivot.x;
        y = _y + pivot.y; 
    }
    bool isEqual(const double &a, const double &b) { return fabs(a - b) <= EPS; }
    bool operator==(const Point &other) const { return fabs(x - other.x) <= EPS && fabs(y - other.y) <= EPS; }
    bool operator!=(const Point &other) const { return !operator==(other); }
    double operator-(const Point &other) const { return sqrt(pow(x - other.x, 2) +               // this calculates distance
            pow(y - other.y, 2)); }
};

#endif
