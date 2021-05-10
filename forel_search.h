#ifndef FOREL_SEARCH_H
#define FOREL_SEARCH_H

#include "clusterizer.h"

class FOREL : public ISearchAlgorithm {
private:
    double radius;
    size_t markedPoints;
    Point currentCenter;
    Field *field;
    size_t randomPointIndex() const;
    Point **getPointsWithinRadius(Point &center, size_t &quantity) const;
    Point getCentroid(Point **points, size_t quantity) const;
    bool validate(Point &point) const { return !point.clusterDefined(); }
    bool allPointsMarked() const { return markedPoints == field->getQuantity(); }
public:
    FOREL(Field *_field) { field = _field; markedPoints = 0; }
    virtual void setField(Field *_field) { field = _field; }
    void reset() { markedPoints = 0; field->reset(); };
    virtual size_t search(double floatingParameter) override;
};

#endif