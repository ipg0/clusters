#include "wave_search.h"

size_t Wave::randomPointIndex() const {
    size_t currentIndex = static_cast<size_t>(rand()) % field->getQuantity();
    if(valid[currentIndex])
        return currentIndex;
    return randomPointIndex();
}

void Wave::initializeWave() {
    field->getPoints()[randomPointIndex()].clusterMark = 1;
}

bool Wave::spreadWave(size_t currentIteration) {
    bool stateChangedOnIteration = false;
    for(size_t i = 0; i < field->getQuantity(); i++)
        if(valid[i] && !field->getPoints()[i].clusterDefined())
            for(size_t j = 0; j < field->getQuantity(); j++)
                if(valid[j] 
                    && field->getPoints()[j].clusterMark == currentIteration - 1 
                    && field->getPoints()[i] - field->getPoints()[j] <= delta) {
                    field->getPoints()[i].clusterMark = currentIteration;
                    stateChangedOnIteration = true;
                }
    return stateChangedOnIteration;
}

bool Wave::markCurrentCluster(size_t currentClusterMark) {
    bool unmarkedPointsRemain = false;
    for(size_t i = 0; i < field->getQuantity(); i++) {
        if(field->getPoints()[i].clusterMark == 0)
            unmarkedPointsRemain = true;
        else if(valid[i]) {
            field->getPoints()[i].clusterMark = currentClusterMark;
            valid[i] = false;
        }
    }
    return unmarkedPointsRemain;
}

size_t Wave::search(double floatingParameter) {
    delta = floatingParameter;
    field->reset();
    valid = new bool[field->getQuantity()];
    for(size_t i = 0; i < field->getQuantity(); i++)
        valid[i] = true;
    bool unmarkedPointsRemain = true;
    size_t currentClusterMark;
    for(currentClusterMark = 1; unmarkedPointsRemain; currentClusterMark++) {
        bool stateChangedOnIteration = true;
        initializeWave();
        for(size_t currentIteration = 2; stateChangedOnIteration; currentIteration++) {
            stateChangedOnIteration = spreadWave(currentIteration);
        }
        unmarkedPointsRemain = markCurrentCluster(currentClusterMark);
    }
    return currentClusterMark;
}