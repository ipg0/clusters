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