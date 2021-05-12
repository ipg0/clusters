#ifndef CLUSTERIZER_H
#define CLUSTERIZER_H
#include "point.h"
#include "cloud.h"
#include "field.cpp"

class ISearchAlgorithm {
public:
    Field *field;
    void setField(Field *_field) { field = _field; }
    virtual size_t search(double floatingParameter) = 0;
};

class Clusterizer {             // I really want to rename this into "clusterfuck" at this point
private:
    Field *field;
    ISearchAlgorithm *searchAlgorithm;
public:
    Clusterizer() { 
        field = nullptr; searchAlgorithm = nullptr;
    }
    size_t search(double floatingParameter) { return searchAlgorithm->search(floatingParameter); }
    void updateSearchAlgorithm(ISearchAlgorithm *_searchAlgorithm) {
        if(searchAlgorithm) delete searchAlgorithm;
        searchAlgorithm = _searchAlgorithm;
        searchAlgorithm->setField(field);
    }
    void updateField(Field *_field) {
        if(field) delete field;
        field = _field;
        if(searchAlgorithm)
            searchAlgorithm->setField(field);
    }
    void write(std::ostream &output) {
        field->write(output);
    }
    ~Clusterizer() {
        if(searchAlgorithm) delete searchAlgorithm;
        if(field) delete field;
    }
};

#endif