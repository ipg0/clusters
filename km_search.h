#ifndef KM_SEARCH_H
#define KM_SEARCH_H

#include "clusterizer.h"

class KMeans : public ISearchAlgorithm {
private:
    size_t k;
    Point *means;
    void setRandomMeans();
    bool assignToNearestMeans();
    void setMeans();
public:
    KMeans() { field = nullptr; means = nullptr; }
    virtual size_t search(double floatingParameter) override;
    ~KMeans() { delete[] means; }
};

#endif