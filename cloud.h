#ifndef CLOUD_H
#define CLOUD_H
#include "point.h"
#include <iostream> // testing
class Cloud {
private:
    Point *points;           // created inside; deleted inside
    Point centerPoint;
    size_t quantity;
    float dx, dy;
public:
    Cloud(Point _centerPoint, float _dx, float _dy, size_t _quantity);   // works
    Point *getPoints() { return points; }
    size_t getQuantity() { return quantity; }
    void displace(float _dx, float _dy);
    void rotateAboutOrigin(float dphi);
    void rotateAboutCenterPoint(float dphi);
    void checkPoints() {
        for(size_t i = 0; i < quantity; i++)
            std::cout << points[i].x << ' ' << points[i].y << '\n';
    } // remove later
    ~Cloud() { delete[] points; }
};

#endif