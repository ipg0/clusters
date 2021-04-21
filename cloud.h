#ifndef CLOUD_H
#define CLOUD_H
#include "point.h"

class Cloud {
private:
    Point *points;           // created inside; deleted inside
    Point centerPoint;
    size_t quantity;
    float dx, dy;
    float normalDistribution(float median, float delta);
public:
    Cloud(Point _centerPoint, float _dx, float _dy, size_t _quantity);
    void displace(float _dx, float _dy);
    void rotateAroundOrigin(float dphi);
    void rotateAroundCenterPoint(float dphi);
};

#endif