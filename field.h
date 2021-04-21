#ifndef FIELD_H
#define FIELD_H
#include "point.h"
#include "cloud.h"
#include <iostream>

class Field {
private:
    Point *points;           // created inside; deleted inside
    size_t quantity;
public:
    Field() { quantity = 0; points = nullptr; }
    Field(std::istream &input);
    Point *getPoints() { return points; }
    size_t getQuantity() { return quantity; }
    void addCloud(Cloud cloud);
    void write(std::ostream &output);
    ~Field() { delete[] points; }
};

#endif