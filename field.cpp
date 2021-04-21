#include "field.h"

void Field::addCloud(Cloud cloud) {
    points = realloc(points, quantity + cloud.getQuantity());
    memcpy(points + quantity, cloud.getPoints(), cloud.getQuantity());
    quantity += cloud.getQuantity();
}