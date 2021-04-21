#include "cloud.h"
#include "point.h"
#include <cmath>

float Cloud::normalDistribution(float mean, float delta) {   // I copied this from rflynn/c
    float x = (float)random() / (mean - delta),
        y = (float)random() / (mean + delta),
        z = sqrt(-2 * log(x)) * cos(2 * M_PI * y);
    return z;
}

Cloud::Cloud(Point _centerPoint, float _dx, float _dy, size_t _quantity) {
    centerPoint = _centerPoint;
    dx = _dx;
    dy = _dy;
    quantity = _quantity;
    points = new Point[quantity];
    for(size_t i = 0; i < quantity; i++)
        points[i] = Point(normalDistribution(centerPoint.x, dx),
            normalDistribution(centerPoint.y, dy));
}

void Cloud::displace(float _dx, float _dy) {
    centerPoint.displace(dx, dy);
    for(size_t i = 0; i < quantity; i++)
        points[i].displace(dx, dy);
}

void Cloud::rotateAboutOrigin(float dphi) {
    Point origin(0, 0);
    centerPoint.rotate(&origin, dphi);
    for(size_t i = 0; i < quantity; i++)
        points[i].rotate(&origin, dphi);
}

void Cloud::rotateAboutCenterPoint(float dphi) {
    for(size_t i = 0; i < quantity; i++)
        points[i].rotate(&centerPoint, dphi);
}