#include "km_search.h"
#include <iostream>

void KMeans::setRandomMeans() {
    for(size_t i = 0; i < k; i++)
        means[i] = field->getPoints()[static_cast<size_t>(rand()) % field->getQuantity()];
}

bool KMeans::assignToNearestMeans() {
    bool currentDelta = false;
    for(size_t i = 0; i < field->getQuantity(); i++) {
        size_t nearestMean = 1;
        double distanceToNearestMean = field->getPoints()[i] - means[0];
        for(size_t j = 1; j < k; j++) {
            double distanceToNextMean = field->getPoints()[i] - means[j];
            if(distanceToNearestMean > distanceToNextMean) {
                distanceToNearestMean = distanceToNextMean;
                nearestMean = j + 1;
            }
        }
        if(nearestMean != field->getPoints()[i].clusterMark) {
            field->getPoints()[i].clusterMark = nearestMean;
            currentDelta = true;
        }
    }
    return currentDelta;
}

void KMeans::setMeans() {
    double *sumX = static_cast<double *>(malloc(k * sizeof(double)));
    double *sumY = static_cast<double *>(malloc(k * sizeof(double)));
    size_t *quantity = static_cast<size_t *>(malloc(k * sizeof(size_t)));
    for(size_t i = 0; i < k; i++)
        sumX[i] = sumY[i] = quantity[i] = 0;
    for(size_t i = 0; i < field->getQuantity(); i++) {
        sumX[field->getPoints()[i].clusterMark - 1] += field->getPoints()[i].x;
        sumY[field->getPoints()[i].clusterMark - 1] += field->getPoints()[i].y;
        quantity[field->getPoints()[i].clusterMark - 1]++;
    }
    for(size_t i = 0; i < k; i++)
        means[i] = Point(sumX[i] / static_cast<double>(quantity[i]), sumY[i] / static_cast<double>(quantity[i]));
    delete[] sumX;
    delete[] sumY;
    delete[] quantity;
}

size_t KMeans::search(double floatingParameter) {
    k = static_cast<size_t>(floatingParameter);
    means = new Point[k];
    setRandomMeans();
    while(assignToNearestMeans())
        setMeans();
    return k;
}
