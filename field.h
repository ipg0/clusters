#ifndef FIELD_H
#define FIELD_H
#include "cloud.h"
#include "cloud.cpp"
#include <iostream>

class Field {
private:
    Point *points;           // created inside; deleted inside
    size_t quantity;
public:
    Field(const Field &_field);
    Field() { quantity = 0; points = nullptr; }
    Field(std::istream &input);
    Point *getPoints() { return points; }
    size_t getQuantity() { return quantity; }
    void addCloud(Cloud cloud);                   // works
    void write(std::ostream &output);
    void reset() { for(size_t i = 0; i < quantity; i++) points[i].reset(); }
    ~Field() { delete[] points; }
    void checkPoints() {
        for(size_t i = 0; i < quantity; i++)
            std::cout << points[i].x << ' ' << points[i].y << '\n';
    } // remove later
};

#endif