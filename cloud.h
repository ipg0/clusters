#ifndef CLOUD_H
#define CLOUD_H
#include "point.h"

class Cloud {
    private:
        Point **points;
        size_t numberPoints;
        float normalDistribution(float default, float delta);
    public:
        Cloud(Point *begin, size_t quantity) { points = *begin; numberPoints = quantity; }
        void fill(Point centerPoint, float dx, float dy);
        void displace(float dx, float dy);
        void rotateAroundOrigin(float dphi);
        void rotateAroundCenterPoint(float dphi);
        void clear();
};

#endif