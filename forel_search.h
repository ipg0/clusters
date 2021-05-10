#include "clusterizer.h"

class FOREL : public ISearchAlgorithm {
private:
    float radius;
    size_t markedPoints;
    Point currentCenter;
    Field *field;
    Point *randomPoint();
    void markPointsAround();
    bool validate(Point point) { return point.clusterDefined(); }
    bool allPointsMarked() { return markedPoints == field->getQuantity(); }
public:
    void reset() { markedPoints = 0; field->reset() };
    void setRadius(double _radius) { reset(); radius = _radius; };
    virtual void search(Field *_field) override;
};