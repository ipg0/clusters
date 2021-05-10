#ifndef KM_SEARCH_H
#define KM_SEARCH_H

#include "clusterizer.h"

class KMeans : public ISearchAlgorithm {
private:
    size_t clusterQuantity;
    Field *field;
    void assignToNearestMeans();
    void getMeans();
public:
    virtual void setField(Field *_field) { field = _field; }
    virtual size_t search(double floatingParameter) override;
} 

#endif