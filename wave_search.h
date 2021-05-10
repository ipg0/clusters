#ifndef WAVE_SEARCH_H
#define WAVE_SEARCH_H

#include "clusterizer.h"

class Wave : private ISearchAlgorithm {
private:
    double delta;
    bool *valid;
    size_t randomPointIndex() const;
    void initializeWave();
    bool spreadWave(size_t currentIteration);
    bool markCurrentCluster(size_t currentClusterMark);
public:
    Wave(Field *_field) { field = _field; }
    virtual size_t search(double floatingParameter) override;
};

#endif