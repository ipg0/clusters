#ifndef CLOUD_H
#define CLOUD_H
#include "point.h"
#include <cstring>
#include <iostream> // testing
class Cloud {
private:
    Point *points;           // created inside; deleted inside
    Point centerPoint;
    size_t quantity;
    double dx, dy;
public:
    Cloud(const Cloud &_cloud);
    Cloud(Point _centerPoint, double _dx, double _dy, size_t _quantity);   // works
    Point *getPoints() { return points; }
    Point getCenterPoint() { return centerPoint; };
    size_t getQuantity() { return quantity; }
    void displace(double _dx, double _dy);
    void rotateAboutOrigin(double dphi);
    void rotateAboutCenterPoint(double dphi);
    ~Cloud() { delete[] points; }
};

#endif