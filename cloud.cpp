#include "cloud.h"
#include "point.h"
#include <cmath>
#include <random>

Cloud::Cloud(Point _centerPoint, float _dx, float _dy, size_t _quantity) {
    centerPoint = _centerPoint;
    dx = _dx;
    dy = _dy;
    quantity = _quantity;
    points = new Point[quantity];
    std::default_random_engine generator(time(0));
    std::normal_distribution<float> xdistr(_centerPoint.x, dx);
    std::normal_distribution<float> ydistr(_centerPoint.y, dy);
    for(size_t i = 0; i < quantity; i++)
        points[i] = Point(xdistr(generator),
            ydistr(generator));
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