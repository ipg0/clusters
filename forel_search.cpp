#include "forel_search.h"
#include <cstdlib>

size_t FOREL::randomPointIndex() const {
    size_t currentIndex = static_cast<size_t>(rand()) % field->getQuantity();
    if(!field->getPoints()[currentIndex].clusterDefined())
        return currentIndex;
    return randomPointIndex();
}

Point FOREL::getCentroid(Point **points, size_t quantity) const {
    double sumX = 0, sumY = 0;
    for(size_t i = 0; i < quantity; i++) {
        sumX += points[i]->x;
        sumY += points[i]->y;
    }
    return Point(sumX / static_cast<double>(quantity), sumY / static_cast<double>(quantity));
}

Point **FOREL::getPointsWithinRadius(Point &center, size_t &quantity) const {
    quantity = 0;
    Point **pointsWithinRadius = nullptr;
    for(size_t i = 0; i < field->getQuantity(); i++) {
        if(validate(field->getPoints()[i]) && center - field->getPoints()[i] <= radius) {
                pointsWithinRadius = static_cast<Point **>(realloc(pointsWithinRadius, ++quantity * sizeof(Point *)));
                pointsWithinRadius[quantity - 1] = (field->getPoints() + i);
            }
    }
    return pointsWithinRadius;
}

size_t FOREL::search(double floatingParameter) {
    reset();
    radius = floatingParameter;
    size_t currentClusterMark = 1;
    while(!allPointsMarked()) {
        Point currentPoint = field->getPoints()[randomPointIndex()];
        size_t quantityWithinRadius;
        Point **withinRadius = getPointsWithinRadius(currentPoint, quantityWithinRadius);
        Point currentCenter = getCentroid(withinRadius, quantityWithinRadius);
        while(currentPoint != currentCenter) {
            currentPoint = currentCenter;
            free(withinRadius);
            withinRadius = getPointsWithinRadius(currentPoint, quantityWithinRadius);
            currentCenter = getCentroid(withinRadius, quantityWithinRadius);
        }
        for(size_t i = 0; i < quantityWithinRadius; i++) {
            withinRadius[i]->clusterMark = currentClusterMark;
            markedPoints++;
        }
        free(withinRadius);
        currentClusterMark++;
    }
    return currentClusterMark - 1;
}
