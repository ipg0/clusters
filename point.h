#ifndef POINT_H
#define POINT_H

typedef unsigned long size_t;

class Point {
public:
    float x, y;
    size_t clusterMark;
    Point() { x = y = 0; clusterMark = -1; }
    Point(float _x, float _y, size_t clusterMark = -1) { x = _x; y = _y, clusterMark = -1; }
    bool clusterDefined() { return !(clusterMark == -1); }
};

#endif