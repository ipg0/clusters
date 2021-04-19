#ifndef FIELD_H
#define FIELD_H
#include "point.h"
#include "cloud.h"
#include "istream"

class Field {
private:
    Point *points;
public:
    Field() { points = nullptr; }
    Field(std::istream &input);
    void addCloud(Cloud cloud);
    void write();
    ~Field() { delete[] points; };
};

#endif