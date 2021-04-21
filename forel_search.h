#include "clusterizer.h"

class FOREL : public ISearchAlgorithm {
private:
    float radius;
public:
    void setRadius();
    virtual void search(Field *_field) override;
};