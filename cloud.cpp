#include "cloud.h"
#include "point.h"
#include <cmath>
#include <random>

Cloud::Cloud(const Cloud &_cloud) {
    quantity = _cloud.quantity;
    centerPoint = _cloud.centerPoint;
    points = new Point[quantity];
    memcpy(points, _cloud.points, quantity * sizeof(Point));
}

Cloud::Cloud(Point _centerPoint, double _dx, double _dy, size_t _quantity) {
    centerPoint = _centerPoint;
    dx = _dx;
    dy = _dy;
    quantity = _quantity;
    points = new Point[quantity];
    std::default_random_engine generator(static_cast<size_t>(time(nullptr)));
    std::normal_distribution<double> xdistr(_centerPoint.x, dx);
    std::normal_distribution<double> ydistr(_centerPoint.y, dy);
    for(size_t i = 0; i < quantity; i++)
        points[i] = Point(xdistr(generator),
            ydistr(generator));
}

void Cloud::displace(double _dx, double _dy) {
    centerPoint.displace(_dx, _dy);
    for(size_t i = 0; i < quantity; i++)
        points[i].displace(_dx, _dy);
}

void Cloud::rotateAboutOrigin(double dphi) {
    Point origin(0, 0);
    centerPoint.rotate(origin, dphi);
    for(size_t i = 0; i < quantity; i++)
        points[i].rotate(origin, dphi);
}

void Cloud::rotateAboutCenterPoint(double dphi) {
    for(size_t i = 0; i < quantity; i++)
        points[i].rotate(centerPoint, dphi);
}
