#ifndef KM_SEARCH_H
#define KM_SEARCH_H

#include "clusterizer.h"

class KMeans : private ISearchAlgorithm {
private:
    size_t k;
    Point *means;
    void setRandomMeans();
    bool assignToNearestMeans();
    void setMeans();
public:
    KMeans(Field *_field) { field = _field; }
    virtual size_t search(double floatingParameter) override;
    ~KMeans() { delete[] means; }
};

#endif