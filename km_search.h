#ifndef KM_SEARCH_H
#define KM_SEARCH_H

#include "clusterizer.h"

class KMeans : public ISearchAlgorithm {
private:
    size_t k;
    Field *field;
    Point *means;
    void setRandomMeans();
    bool assignToNearestMeans();
    void setMeans();
public:
    KMeans(Field *_field) { field = _field; }
    virtual void setField(Field *_field) override { field = _field; }
    virtual size_t search(double floatingParameter) override;
};

#endif