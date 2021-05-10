#include "field.h"
#include <cstring>

Field::Field(const Field &_field) { 
    quantity = _field.quantity;
    points = new Point[quantity];
    memcpy(points, _field.points, quantity * sizeof(Point));
};

void Field::addCloud(Cloud cloud) {
    points = (Point *)realloc(points, quantity + cloud.getQuantity() * sizeof(Point));
    memcpy(points + quantity, cloud.getPoints(), cloud.getQuantity() * sizeof(Point));
    quantity += cloud.getQuantity();
}

void Field::write(std::ostream &output) {
    output << '[';
    for(size_t i = 0; i < quantity; i++) {
        output << "{ \"x\" : " << points[i].x
            << ", \"y\" : " << points[i].y
            << ", \"mark\" : " << points[i].clusterMark << '}';
        if(i != quantity - 1)
            output << ", ";
    }
    output << ']';
}