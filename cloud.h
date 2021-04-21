#ifndef CLOUD_H
#define CLOUD_H
#include "point.h"
#include <iostream> // testing
class Cloud {
private:
    Point *points;           // created inside; deleted inside
    Point centerPoint;
    size_t quantity;
    double dx, dy;
public:
    Cloud(Point _centerPoint, double _dx, double _dy, size_t _quantity);   // works
    Point *getPoints() { return points; }
    size_t getQuantity() { return quantity; }
    void displace(double _dx, double _dy);
    void rotateAboutOrigin(double dphi);
    void rotateAboutCenterPoint(double dphi);
    void checkPoints() {
        for(size_t i = 0; i < quantity; i++)
            std::cout << points[i].x << ' ' << points[i].y << '\n';
    } // remove later
    ~Cloud() { delete[] points; }
};

#endif