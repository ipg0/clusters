#include "field.h"
#include <cstring>

void Field::addCloud(Cloud &cloud) {
    points = (Point *)realloc(points, quantity + cloud.getQuantity() * sizeof(Point));
    memcpy(points + quantity, cloud.getPoints(), cloud.getQuantity() * sizeof(Point));
    quantity += cloud.getQuantity();
}