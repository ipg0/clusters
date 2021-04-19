#ifndef CLOUD_H
#define CLOUD_H
#include "point.h"

class Cloud {
    private:
        Point *points;
        Point centerPoint;
        size_t quantity;
        float normalDistribution(float median, float delta);
    public:
        Cloud(Point _centerPoint, float dx, float dy, size_t _quantity); // creates new cloud
        Cloud(Point *begin, size_t _quantity) { points = begin; quantity = _quantity; } // sets an array of points as cloud
        void fill(Point _centerPoint, float dx, float dy);
        void displace(float dx, float dy);
        void rotateAroundOrigin(float dphi);
        void rotateAroundCenterPoint(float dphi);
        void clear();
};

#endif