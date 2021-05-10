#ifndef CLUSTERIZER_H
#define CLUSTERIZER_H
#include "point.h"
#include "cloud.h"
#include "field.h"

class ISearchAlgorithm {
public:
    Field *field;
    void setField(Field *_field) { field = _field; }
    virtual size_t search(double floatingParameter) = 0;
};

class Clusterizer {             // I really want to rename this into "clusterfuck" at this point
private:
    Field *field;                               // created outside (main flow); deleted outside
    ISearchAlgorithm *currentSearchAlgorithm;   // created outside (main flow); updated externally (main flow); deleted inside
public:
    Clusterizer(Field *_field, ISearchAlgorithm *_searchAlgorithm = nullptr) { 
        field = _field; currentSearchAlgorithm = _searchAlgorithm;
    }
    size_t search(double floatingParameter) { return currentSearchAlgorithm->search(floatingParameter); }
    void updateSearchAlgorithm(ISearchAlgorithm *_searchAlgorithm) {
        delete currentSearchAlgorithm;
        currentSearchAlgorithm = _searchAlgorithm;
    }
    ~Clusterizer() {
        if(currentSearchAlgorithm) delete currentSearchAlgorithm;
    }
};

#endif