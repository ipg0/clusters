#ifndef CLUSTERIZER_H
#define CLUSTERIZER_H
#include "point.h"
#include "cloud.h"
#include "field.h"

class ISearchAlgorithm {
public:
    virtual Cloud *search(Field *_field, size_t _number) = 0;
};

class Clusterizer { // I really want to rename this into "clusterfuck" at this point
private:
    Field *field;
    ISearchAlgorithm *currentSearchAlgorithm;
public:
    Clusterizer(Field *_field) { field = _field; currentSearchAlgorithm = nullptr; }
    Clusterizer(Field *_field, ISearchAlgorithm *_searchAlgorithm);
    Cloud *search(size_t _number) { return currentSearchAlgorithm.search(field, _number); }
    void updateSearchAlgorithm(ISearchAlgorithm *_searchAlgorithm) { currentSearchAlgorithm = _searchAlgorithm; }
};

#endif