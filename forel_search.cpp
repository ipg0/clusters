#include "forel_search.h"
#include <cstdlib>

size_t FOREL::randomPointIndex() {
    size_t currentIndex = std::rand() % field->getQuantity();
    if(!field->getPoints()[currentIndex].clusterDefined())
        return currentIndex;
    return randomPointIndex();
}

Point FOREL::centerOfMass(Point **points, size_t quantity) {
    double sumX = 0, sumY = 0;
    for(size_t i = 0; i < quantity; i++) {
        sumX += points[i]->x;
        sumY += points[i]->y;
    }
    return Point(sumX / quantity, sumY / quantity);
}

Point **FOREL::getPointsWithinRadius(Point &center, size_t &quantity) {
    quantity = 0;
    Point **pointsWithinRadius = nullptr;
    for(size_t i = 0; i < field->getQuantity(); i++) {
        if(!field->getPoints()[i].clusterDefined() sqrt(pow(center.x - field->getPoints()[i].x, 2) +
            pow(center.y - field->getPoints()[i].y, 2)) {
                pointsWithinRadius = realloc(pointsWithinRadius, ++quantity * sizeof(Point *));
                pointsWithinRadius[quantity - 1] = (field->getPoints() + i);
            }
    }
    return pointsWithinRadius;
}

size_t FOREL::search(double floatingParameter) {
    reset();
    size_t currentClusterMark = 1;
    while(!allPointsMarked()) {
        Point currentPoint = field->getPoints()[randomPointIndex()];
        size_t quantityWithinRadius;
        Point **withinRadius = getPointsWithinRadius(currentPoint, quantityWithinRadius);
        Point currentCenter = centerOfMass(withinRadius, quantityWithinRadius);
        while(currentPoint != currentCenter) {
            currentPoint = currentCenter;
            free(withinRadius);
            withinRadius = getPointsWithinRadius(currentPoint, quantityWithinRadius);
            currentCenter = centerOfMass(withinRadius, quantityWithinRadius);
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