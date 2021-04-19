#ifndef CLUSTERIZER_H
#define CLUSTERIZER_H
#include "point.h"
#include "cloud.h"
#include "field.h"

class ISearchAlgorithm {
private:
    Field field;
public:
    virtual Cloud *search() = 0;
};

class Clusterizer {
private:
    Field field;
    ISearchAlgorithm currentSearchAlgorithm;
public:
    Clusterizer(Field _field, ISearchAlgorithm _searchAlgorithm)
};

#endif